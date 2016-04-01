/**
	SPI DeviceSimulator
	ParallelCommandExecution1.cpp
	Purpose: This command is able to run parallel with other commands with the same possibility.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#include "ParallelCommandExecution1.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		ParallelCommandExecution1::ParallelCommandExecution1(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_executionDuration(nullptr)
		{
		}
		ParallelCommandExecution1::~ParallelCommandExecution1()
		{
		}

		std::string ParallelCommandExecution1::getCommandName()
		{
			return "ParallelCommandExecution1";
		}
		std::string ParallelCommandExecution1::getCommandDescription()
		{
			return "This command is able to run parallel with other commands with the same possibility.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> ParallelCommandExecution1::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDuration> executionDuration(new SPICE::BIG::DataEntryTypes::DataEntryDuration("executionDuration", 0, 300));
			executionDuration->setAdditionalInformations("This parameter defines how long the command will take for execution.", "","PT10S");
			_executionDuration = executionDuration;

			// Set, if they are required or optional
			_executionDuration->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_executionDuration);

			return returnVector;
		}

		double ParallelCommandExecution1::calculateEstimatedDuration()
		{
			if(_executionDuration->getIsSet())
			{
				return _executionDuration->getValue();
			}
			return 0;
		}

		bool ParallelCommandExecution1::readyForStart()
		{
			if(_commandCallback->getActiveCommandsCount() != 0)
			{
				std::map<int, std::string> activeList = _commandCallback->getActiveCommandsList();
				
				for(std::map<int, std::string>::iterator i = activeList.begin(); i != activeList.end(); i++)
				{
					if(i->second != "ParallelCommandExecution1" && i->second != "ParallelCommandExecution2")
					{
						return false;
					}
				}
			}
			return true;
		}
		bool ParallelCommandExecution1::processing()
		{
			return _specificCore->commandForParallelExecution(_executionDuration->getValue(), _commandCallback);
		}
	}
}
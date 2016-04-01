/**
	SPI DeviceSimulator
	NonParallelCommandExecution2.cpp
	Purpose: This command isn't able to run parallel with other commands.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#include "NonParallelCommandExecution2.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		NonParallelCommandExecution2::NonParallelCommandExecution2(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_executionDuration(nullptr)
		{
		}
		NonParallelCommandExecution2::~NonParallelCommandExecution2()
		{
		}

		std::string NonParallelCommandExecution2::getCommandName()
		{
			return "NonParallelCommandExecution2";
		}
		std::string NonParallelCommandExecution2::getCommandDescription()
		{
			return "This command isn't able to run parallel with other commands.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> NonParallelCommandExecution2::createAndGetAdditionalCommandParameters()
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

		double NonParallelCommandExecution2::calculateEstimatedDuration()
		{
			if(_executionDuration->getIsSet())
			{
				return _executionDuration->getValue();
			}
			return 0;
		}

		bool NonParallelCommandExecution2::processing()
		{
			return _specificCore->commandForNonParallelExecution(_executionDuration->getValue(), _commandCallback);
		}
	}
}
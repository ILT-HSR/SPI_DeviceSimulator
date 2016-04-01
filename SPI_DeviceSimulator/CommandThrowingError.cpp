/**
	SPI DeviceSimulator
	CommandThrowingError.cpp
	Purpose: This command is able to throw diffrent types of error.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#include "CommandThrowingError.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandThrowingError::CommandThrowingError(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_durationUntilThrowingError(nullptr),
			_errorType(nullptr)
		{
		}
		CommandThrowingError::~CommandThrowingError()
		{
		}

		std::string CommandThrowingError::getCommandName()
		{
			return "CommandThrowingError";
		}
		std::string CommandThrowingError::getCommandDescription()
		{
			return "This command is able to throw diffrent types of error.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandThrowingError::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDuration> durationUntilThrowingError(new SPICE::BIG::DataEntryTypes::DataEntryDuration("durationUntilThrowingError", 0, 300));
			durationUntilThrowingError->setAdditionalInformations("This parameter defines how long the command will execute before throwing the error.", "","PT5S");
			_durationUntilThrowingError = durationUntilThrowingError;
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryInt> errorType(new SPICE::BIG::DataEntryTypes::DataEntryInt("errorType", 1, 4));
			errorType->setAdditionalInformations("This parameter defines how long the command will take for execution. 1 - fatal, 2 - aborting, 3 - continuation, 4 - failing continuation", "","3");
			_errorType = errorType;

			// Set, if they are required or optional
			_durationUntilThrowingError->setIsNeeded(true);
			_errorType->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_durationUntilThrowingError);
			returnVector.push_back(_errorType);

			return returnVector;
		}

		double CommandThrowingError::calculateEstimatedDuration()
		{
			return 0;
		}

		bool CommandThrowingError::processing()
		{
			return _specificCore->commandThrowingError(_durationUntilThrowingError->getValue(), _errorType->getValue(), _commandCallback);
		}
	}
}
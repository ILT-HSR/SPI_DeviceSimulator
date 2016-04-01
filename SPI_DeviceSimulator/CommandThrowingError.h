/**
	SPI DeviceSimulator
	CommandThrowingError.h
	Purpose: This command is able to throw diffrent types of error.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#ifndef COMMANDTHROWINGERROR_H
#define COMMANDTHROWINGERROR_H

#include "SpecificCommandBase.h"

#include "DataEntryDuration.h"
#include "DataEntryInt.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandThrowingError : public SpecificCommandBase
		{
			public:
				CommandThrowingError(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandThrowingError();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDuration> _durationUntilThrowingError;
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryInt> _errorType;
		};
	}
}
#endif // COMMANDTHROWINGERROR_H

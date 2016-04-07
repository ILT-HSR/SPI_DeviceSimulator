/**
	SPI DeviceSimulator
	CommandWithUInt64Parameter.h
	Purpose: This command provides a parameters with UInt64 and returns the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#ifndef COMMANDWITHUINT64PARAMETER_H
#define COMMANDWITHUINT64PARAMETER_H

#include "SpecificCommandBase.h"

#include "DataEntryUnsignedLong.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithUInt64Parameter : public SpecificCommandBase
		{
			public:
				CommandWithUInt64Parameter(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithUInt64Parameter();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedLong> _uLongParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHUINT64PARAMETER_H

/**
	SPI DeviceSimulator
	CommandWithUInt8Parameter.h
	Purpose: This command provides a parameters with UInt8 and returns the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#ifndef COMMANDWITHUINT8PARAMETER_H
#define COMMANDWITHUINT8PARAMETER_H

#include "SpecificCommandBase.h"

#include "DataEntryUnsignedByte.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithUInt8Parameter : public SpecificCommandBase
		{
			public:
				CommandWithUInt8Parameter(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithUInt8Parameter();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedByte> _uByteParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHUINT8PARAMETER_H

/**
	SPI DeviceSimulator
	CommandWithUInt16Parameter.h
	Purpose: This command provides a parameters with UInt16 and returns the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#ifndef COMMANDWITHUINT16PARAMETER_H
#define COMMANDWITHUINT16PARAMETER_H

#include "SpecificCommandBase.h"

#include "DataEntryUnsignedShort.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithUInt16Parameter : public SpecificCommandBase
		{
			public:
				CommandWithUInt16Parameter(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithUInt16Parameter();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedShort> _uShortParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHUINT16PARAMETER_H

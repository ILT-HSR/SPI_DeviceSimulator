/**
	SPI DeviceSimulator
	CommandWithUInt32Parameter.h
	Purpose: This command provides a parameters with UInt32 and returns the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#ifndef COMMANDWITHUINT32PARAMETER_H
#define COMMANDWITHUINT32PARAMETER_H

#include "SpecificCommandBase.h"

#include "DataEntryUnsignedInt.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithUInt32Parameter : public SpecificCommandBase
		{
			public:
				CommandWithUInt32Parameter(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithUInt32Parameter();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedInt> _uIntParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHUINT32PARAMETER_H

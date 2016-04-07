/**
	SPI DeviceSimulator
	CommandWithDoubleParameter.h
	Purpose: This command provides a parameter with double data type and return the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#ifndef COMMANDWITHDOUBLEPARAMETERS_H
#define COMMANDWITHDOUBLEPARAMETERS_H

#include "SpecificCommandBase.h"

#include "DataEntryDouble.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithDoubleParameter : public SpecificCommandBase
		{
			public:
				CommandWithDoubleParameter(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithDoubleParameter();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDouble> _doubleParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHDOUBLEPARAMETERS_H

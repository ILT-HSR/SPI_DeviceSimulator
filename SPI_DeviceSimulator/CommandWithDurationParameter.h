/**
	SPI DeviceSimulator
	CommandWithDurationParameter.h
	Purpose: This command provides a parameters with duration data type and return the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#ifndef COMMANDWITHDURATIONPARAMETER_H
#define COMMANDWITHDURATIONPARAMETER_H

#include "SpecificCommandBase.h"

#include "DataEntryDuration.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithDurationParameter : public SpecificCommandBase
		{
			public:
				CommandWithDurationParameter(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithDurationParameter();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDuration> _durationParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHDURATIONPARAMETER_H

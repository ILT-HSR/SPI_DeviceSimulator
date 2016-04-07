/**
	SPI DeviceSimulator
	CommandWithFloatParameter.h
	Purpose: This command provides a parameters with float data type and return the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#ifndef COMMANDWITHFLOATPARAMETER_H
#define COMMANDWITHFLOATPARAMETER_H

#include "SpecificCommandBase.h"

#include "DataEntryFloat.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithFloatParameter : public SpecificCommandBase
		{
			public:
				CommandWithFloatParameter(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithFloatParameter();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryFloat> _floatParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHFLOATPARAMETER_H

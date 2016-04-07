/**
	SPI DeviceSimulator
	CommandWithBoolParameter.h
	Purpose: This command provides a parameter with bool data type and return the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#ifndef COMMANDWITHBOOLPARAMETER_H
#define COMMANDWITHBOOLPARAMETER_H

#include "SpecificCommandBase.h"

#include "DataEntryBool.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithBoolParameter : public SpecificCommandBase
		{
			public:
				CommandWithBoolParameter(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithBoolParameter();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryBool> _boolParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHBOOLPARAMETER_H

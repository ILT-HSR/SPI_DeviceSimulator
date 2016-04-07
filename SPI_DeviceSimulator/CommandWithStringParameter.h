/**
	SPI DeviceSimulator
	CommandWithStringParameter.h
	Purpose: This command provides a parameter with string data type and return the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#ifndef COMMANDWITHSTRINGPARAMETER_H
#define COMMANDWITHSTRINGPARAMETER_H

#include "SpecificCommandBase.h"

#include "DataEntryString.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithStringParameter : public SpecificCommandBase
		{
			public:
				CommandWithStringParameter(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithStringParameter();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryString> _stringParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHSTRINGPARAMETER_H

/**
	SPI DeviceSimulator
	CommandWithFloatingParameters.h
	Purpose: This command provides parameters with floating data types and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#ifndef COMMANDWITHFLOATINGPARAMETERS_H
#define COMMANDWITHFLOATINGPARAMETERS_H

#include "SpecificCommandBase.h"

#include "DataEntryFloat.h"
#include "DataEntryDouble.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithFloatingParameters : public SpecificCommandBase
		{
			public:
				CommandWithFloatingParameters(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithFloatingParameters();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryFloat> _floatParameter;
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDouble> _doubleParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHFLOATINGPARAMETERS_H

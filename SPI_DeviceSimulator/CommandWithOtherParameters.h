/**
	SPI DeviceSimulator
	CommandWithOtherParameters.h
	Purpose: This command provides parameters with other (none float, signed or unsigned) data types and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#ifndef COMMANDWITHOTHERPARAMETERS_H
#define COMMANDWITHOTHERPARAMETERS_H

#include "SpecificCommandBase.h"

#include "DataEntryBool.h"
#include "DataEntryString.h"
#include "DataEntryDuration.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithOtherParameters : public SpecificCommandBase
		{
			public:
				CommandWithOtherParameters(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithOtherParameters();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryBool> _boolParameter;
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryString> _stringParameter;
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDuration> _durationParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHOTHERPARAMETERS_H

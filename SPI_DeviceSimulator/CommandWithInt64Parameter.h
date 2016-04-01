/**
	SPI DeviceSimulator
	CommandWithInt64Parameter.h
	Purpose: This command provides a parameter with Int64 and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_01
*/

#ifndef COMMANDWITHINT64PARAMETER_H
#define COMMANDWITHINT64PARAMETER_H

#include "SpecificCommandBase.h"

#include "DataEntryLong.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithInt64Parameter : public SpecificCommandBase
		{
			public:
				CommandWithInt64Parameter(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithInt64Parameter();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryLong> _longParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHINT64PARAMETER_H

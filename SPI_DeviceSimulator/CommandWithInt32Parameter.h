/**
	SPI DeviceSimulator
	CommandWithInt32Parameter.h
	Purpose: This command provides a parameter with Int32 and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_01
*/

#ifndef COMMANDWITHINT32PARAMETER_H
#define COMMANDWITHINT32PARAMETER_H

#include "SpecificCommandBase.h"

#include "DataEntryInt.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithInt32Parameter : public SpecificCommandBase
		{
			public:
				CommandWithInt32Parameter(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithInt32Parameter();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryInt> _intParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHINT32PARAMETER_H

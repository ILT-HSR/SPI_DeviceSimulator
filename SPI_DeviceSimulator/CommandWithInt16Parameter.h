/**
	SPI DeviceSimulator
	CommandWithInt16Parameter.h
	Purpose: This command provides a parameter with Int16 and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_01
*/

#ifndef COMMANDWITHINT16PARAMETER_H
#define COMMANDWITHINT16PARAMETER_H

#include "SpecificCommandBase.h"

#include "DataEntryShort.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithInt16Parameter : public SpecificCommandBase
		{
			public:
				CommandWithInt16Parameter(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithInt16Parameter();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryShort> _shortParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHINT16PARAMETER_H

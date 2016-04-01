/**
	SPI DeviceSimulator
	CommandWithInt8Parameter.h
	Purpose: This command provides a parameter with Int8 and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_01
*/

#ifndef COMMANDWITHINT8PARAMETER_H
#define COMMANDWITHINT8PARAMETER_H

#include "SpecificCommandBase.h"

#include "DataEntryByte.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithInt8Parameter : public SpecificCommandBase
		{
			public:
				CommandWithInt8Parameter(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithInt8Parameter();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryByte> _byteParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHINT8PARAMETER_H

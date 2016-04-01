/**
	SPI DeviceSimulator
	CommandWithUnsignedParameters.h
	Purpose: This command provides parameters with all unsigned data types and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#ifndef COMMANDWITHUNSIGNEDPARAMETERS_H
#define COMMANDWITHUNSIGNEDPARAMETERS_H

#include "SpecificCommandBase.h"

#include "DataEntryUnsignedByte.h"
#include "DataEntryUnsignedShort.h"
#include "DataEntryUnsignedInt.h"
#include "DataEntryUnsignedLong.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithUnsignedParameters : public SpecificCommandBase
		{
			public:
				CommandWithUnsignedParameters(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithUnsignedParameters();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedByte> _uByteParameter;
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedShort> _uShortParameter;
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedInt> _uIntParameter;
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedLong> _uLongParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHUNSIGNEDPARAMETERS_H

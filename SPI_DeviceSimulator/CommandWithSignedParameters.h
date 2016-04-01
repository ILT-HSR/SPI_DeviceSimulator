/**
	SPI DeviceSimulator
	CommandWithSignedParameters.h
	Purpose: This command provides parameters with all signed data types and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#ifndef COMMANDWITHSIGNEDPARAMETERS_H
#define COMMANDWITHSIGNEDPARAMETERS_H

#include "SpecificCommandBase.h"

#include "DataEntryByte.h"
#include "DataEntryShort.h"
#include "DataEntryInt.h"
#include "DataEntryLong.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class CommandWithSignedParameters : public SpecificCommandBase
		{
			public:
				CommandWithSignedParameters(std::shared_ptr<SpecificCore> specificCore);
				virtual ~CommandWithSignedParameters();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataSet>> getResponseDataInformation(std::string& responseDescription);

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryByte> _byteParameter;
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryShort> _shortParameter;
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryInt> _intParameter;
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryLong> _longParameter;
				std::shared_ptr<SPICE::BIG::DataSet> _responseDataSet;
		};
	}
}
#endif // COMMANDWITHSIGNEDPARAMETERS_H

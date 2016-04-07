/**
	SPI DeviceSimulator
	CommandWithUInt64Parameter.cpp
	Purpose: This command provides a parameters with UInt64 and returns the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#include "CommandWithUInt64Parameter.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithUInt64Parameter::CommandWithUInt64Parameter(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_uLongParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithUInt64Parameter::~CommandWithUInt64Parameter()
		{
		}

		std::string CommandWithUInt64Parameter::getCommandName()
		{
			return "CommandWithUInt64Parameter";
		}
		std::string CommandWithUInt64Parameter::getCommandDescription()
		{
			return "This command provides a parameters with UInt64 and returns the value in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithUInt64Parameter::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedLong> uLongParameter(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedLong("uLongParameter", 0 , 18446744073709551615u));
			uLongParameter->setAdditionalInformations("This parameter provides an unsigned long value like a coffee counter.", "cups","78");
			_uLongParameter = uLongParameter;

			// Set, if they are required or optional
			_uLongParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_uLongParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithUInt64Parameter::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with uint64 parameter";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedLong> uLongResponse(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedLong("uLongResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(uLongResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithUInt64Parameter::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithUInt64Parameter::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithUInt64Parameter(_uLongParameter->getValue(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
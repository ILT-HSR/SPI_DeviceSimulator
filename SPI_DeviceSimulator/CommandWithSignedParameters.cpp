/**
	SPI DeviceSimulator
	CommandWithSignedParameters.cpp
	Purpose: This command provides parameters with all signed data types and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#include "CommandWithSignedParameters.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithSignedParameters::CommandWithSignedParameters(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_byteParameter(nullptr),
			_shortParameter(nullptr),
			_intParameter(nullptr),
			_longParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithSignedParameters::~CommandWithSignedParameters()
		{
		}

		std::string CommandWithSignedParameters::getCommandName()
		{
			return "CommandWithSignedParameters";
		}
		std::string CommandWithSignedParameters::getCommandDescription()
		{
			return "This command provides parameters with all signed data types and return the values in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithSignedParameters::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryByte> byteParameter(new SPICE::BIG::DataEntryTypes::DataEntryByte("byteParameter", INT8_MIN, INT8_MAX));
			byteParameter->setAdditionalInformations("This parameter provides a byte value.", "","10");
			_byteParameter = byteParameter;
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryShort> shortParameter(new SPICE::BIG::DataEntryTypes::DataEntryShort("shortParameter", -32767 - 1, 32767));
			shortParameter->setAdditionalInformations("This parameter provides a short value like speed", "mm/s","5");
			_shortParameter = shortParameter;
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryInt> intParameter(new SPICE::BIG::DataEntryTypes::DataEntryInt("intParameter", -2147483647 - 1, 2147483647));
			intParameter->setAdditionalInformations("This parameter provides a int value like a distance", "mm","-10");
			_intParameter = intParameter;
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryLong> longParameter(new SPICE::BIG::DataEntryTypes::DataEntryLong("longParameter", -9223372036854775807 -1, 9223372036854775807));
			longParameter->setAdditionalInformations("This parameter provides a long value like a coffee counter.", "cups","78");
			_longParameter = longParameter;

			// Set, if they are required or optional
			_byteParameter->setIsNeeded(true);
			_shortParameter->setIsNeeded(true);
			_intParameter->setIsNeeded(true);
			_longParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_byteParameter);
			returnVector.push_back(_shortParameter);
			returnVector.push_back(_intParameter);
			returnVector.push_back(_longParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithSignedParameters::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with signed parameters";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryByte> byteResponse(new SPICE::BIG::DataEntryTypes::DataEntryByte("byteResponse"));
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryShort> shortResponse(new SPICE::BIG::DataEntryTypes::DataEntryShort("shortResponse"));
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryInt> intResponse(new SPICE::BIG::DataEntryTypes::DataEntryInt("intResponse"));
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryLong> longResponse(new SPICE::BIG::DataEntryTypes::DataEntryLong("longResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(byteResponse);
			responseDataSet->addDataEntry(shortResponse);
			responseDataSet->addDataEntry(intResponse);
			responseDataSet->addDataEntry(longResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithSignedParameters::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithSignedParameters::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithSignedParameters(_byteParameter->getValue(), _shortParameter->getValue(), _intParameter->getValue(), _longParameter->getValue(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
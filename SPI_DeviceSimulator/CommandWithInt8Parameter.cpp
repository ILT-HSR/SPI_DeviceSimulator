/**
	SPI DeviceSimulator
	CommandWithInt8Parameter.cpp
	Purpose: This command provides a parameter with Int8 and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_01
*/

#include "CommandWithInt8Parameter.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithInt8Parameter::CommandWithInt8Parameter(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_byteParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithInt8Parameter::~CommandWithInt8Parameter()
		{
		}

		std::string CommandWithInt8Parameter::getCommandName()
		{
			return "CommandWithInt8Parameter";
		}
		std::string CommandWithInt8Parameter::getCommandDescription()
		{
			return "This command provides a parameter with Int8 and return the values in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithInt8Parameter::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryByte> byteParameter(new SPICE::BIG::DataEntryTypes::DataEntryByte("byteParameter", INT8_MIN, INT8_MAX));
			byteParameter->setAdditionalInformations("This parameter provides a byte value.", "","10");
			_byteParameter = byteParameter;

			// Set, if they are required or optional
			_byteParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_byteParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithInt8Parameter::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with Int8 parameter";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryByte> byteResponse(new SPICE::BIG::DataEntryTypes::DataEntryByte("byteResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(byteResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithInt8Parameter::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithInt8Parameter::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithInt8Parameter(_byteParameter->getValue(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
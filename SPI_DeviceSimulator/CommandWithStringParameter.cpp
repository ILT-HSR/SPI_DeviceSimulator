/**
	SPI DeviceSimulator
	CommandWithStringParameter.cpp
	Purpose: This command provides a parameter with string data type and return the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#include "CommandWithStringParameter.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithStringParameter::CommandWithStringParameter(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_stringParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithStringParameter::~CommandWithStringParameter()
		{
		}

		std::string CommandWithStringParameter::getCommandName()
		{
			return "CommandWithStringParameter";
		}
		std::string CommandWithStringParameter::getCommandDescription()
		{
			return "This command provides a parameter with string data type and return the value in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithStringParameter::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryString> stringParameter(new SPICE::BIG::DataEntryTypes::DataEntryString("stringParameter", false));
			stringParameter->setAdditionalInformations("This parameter provides a string value", "","Test");
			_stringParameter = stringParameter;

			// Set, if they are required or optional
			_stringParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_stringParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithStringParameter::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with a string parameter";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryString> stringResponse(new SPICE::BIG::DataEntryTypes::DataEntryString("stringResponse",true));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(stringResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithStringParameter::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithStringParameter::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithStringParameter(_stringParameter->getValueAsString(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
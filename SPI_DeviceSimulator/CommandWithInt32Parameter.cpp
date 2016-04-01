/**
	SPI DeviceSimulator
	CommandWithInt32Parameter.cpp
	Purpose: This command provides a parameter with Int32 and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_01
*/

#include "CommandWithInt32Parameter.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithInt32Parameter::CommandWithInt32Parameter(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_intParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithInt32Parameter::~CommandWithInt32Parameter()
		{
		}

		std::string CommandWithInt32Parameter::getCommandName()
		{
			return "CommandWithInt32Parameter";
		}
		std::string CommandWithInt32Parameter::getCommandDescription()
		{
			return "This command provides a parameter with Int32 and return the values in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithInt32Parameter::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryInt> intParameter(new SPICE::BIG::DataEntryTypes::DataEntryInt("intParameter", -2147483647 - 1, 2147483647));
			intParameter->setAdditionalInformations("This parameter provides a int value like a distance", "mm","-10");
			_intParameter = intParameter;

			// Set, if they are required or optional
			_intParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_intParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithInt32Parameter::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with Int32 parameter";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryInt> intResponse(new SPICE::BIG::DataEntryTypes::DataEntryInt("intResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(intResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithInt32Parameter::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithInt32Parameter::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithInt32Parameter(_intParameter->getValue(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
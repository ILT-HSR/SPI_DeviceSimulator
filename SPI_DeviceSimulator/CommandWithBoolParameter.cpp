/**
	SPI DeviceSimulator
	CommandWithBoolParameter.cpp
	Purpose: This command provides a parameter with bool data type and return the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#include "CommandWithBoolParameter.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithBoolParameter::CommandWithBoolParameter(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_boolParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithBoolParameter::~CommandWithBoolParameter()
		{
		}

		std::string CommandWithBoolParameter::getCommandName()
		{
			return "CommandWithBoolParameter";
		}
		std::string CommandWithBoolParameter::getCommandDescription()
		{
			return "This command provides a parameter with bool data type and return the value in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithBoolParameter::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryBool> boolParameter(new SPICE::BIG::DataEntryTypes::DataEntryBool("boolParameter"));
			boolParameter->setAdditionalInformations("This parameter provides a bool value.", "","true");
			_boolParameter = boolParameter;

			// Set, if they are required or optional
			_boolParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_boolParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithBoolParameter::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with a bool parameter";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryBool> boolResponse(new SPICE::BIG::DataEntryTypes::DataEntryBool("boolResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(boolResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithBoolParameter::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithBoolParameter::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithBoolParameter(_boolParameter->getValue(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
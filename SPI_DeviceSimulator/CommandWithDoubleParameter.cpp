/**
	SPI DeviceSimulator
	CommandWithDoubleParameter.cpp
	Purpose: This command provides a parameter with double data type and return the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#include "CommandWithDoubleParameter.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithDoubleParameter::CommandWithDoubleParameter(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_doubleParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithDoubleParameter::~CommandWithDoubleParameter()
		{
		}

		std::string CommandWithDoubleParameter::getCommandName()
		{
			return "CommandWithDoubleParameter";
		}
		std::string CommandWithDoubleParameter::getCommandDescription()
		{
			return "This command provides a parameter with double data type and return the value in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithDoubleParameter::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDouble> doubleParameter(new SPICE::BIG::DataEntryTypes::DataEntryDouble("doubleParameter", -123.45, 234.56));
			doubleParameter->setAdditionalInformations("This parameter provides a double value.", "","-3.28");
			_doubleParameter = doubleParameter;

			// Set, if they are required or optional
			_doubleParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_doubleParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithDoubleParameter::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with a double parameter";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDouble> doubleResponse(new SPICE::BIG::DataEntryTypes::DataEntryDouble("doubleResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(doubleResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithDoubleParameter::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithDoubleParameter::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithDoubleParameter(_doubleParameter->getValue(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
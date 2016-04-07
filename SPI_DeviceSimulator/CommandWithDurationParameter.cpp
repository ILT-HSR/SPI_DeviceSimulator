/**
	SPI DeviceSimulator
	CommandWithDurationParameter.cpp
	Purpose: This command provides a parameter with duration data type and return the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#include "CommandWithDurationParameter.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithDurationParameter::CommandWithDurationParameter(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_durationParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithDurationParameter::~CommandWithDurationParameter()
		{
		}

		std::string CommandWithDurationParameter::getCommandName()
		{
			return "CommandWithDurationParameter";
		}
		std::string CommandWithDurationParameter::getCommandDescription()
		{
			return "This command provides a parameter with duration data type and return the value in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithDurationParameter::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDuration> durationParameter(new SPICE::BIG::DataEntryTypes::DataEntryDuration("durationParameter",0, 300));
			durationParameter->setAdditionalInformations("This parameter provides a duration value", "","PT100S");
			_durationParameter = durationParameter;

			// Set, if they are required or optional
			_durationParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_durationParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithDurationParameter::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with a duration parameter";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDuration> durationResponse(new SPICE::BIG::DataEntryTypes::DataEntryDuration("durationResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(durationResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithDurationParameter::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithDurationParameter::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithDurationParameter(_durationParameter->getValue(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
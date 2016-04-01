/**
	SPI DeviceSimulator
	CommandWithOtherParameters.cpp
	Purpose: This command provides parameters with other (none float, signed or unsigned) data types and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#include "CommandWithOtherParameters.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithOtherParameters::CommandWithOtherParameters(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_boolParameter(nullptr),
			_stringParameter(nullptr),
			_durationParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithOtherParameters::~CommandWithOtherParameters()
		{
		}

		std::string CommandWithOtherParameters::getCommandName()
		{
			return "CommandWithOtherParameters";
		}
		std::string CommandWithOtherParameters::getCommandDescription()
		{
			return "";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithOtherParameters::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryBool> boolParameter(new SPICE::BIG::DataEntryTypes::DataEntryBool("boolParameter"));
			boolParameter->setAdditionalInformations("This parameter provides a bool value.", "","true");
			_boolParameter = boolParameter;
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryString> stringParameter(new SPICE::BIG::DataEntryTypes::DataEntryString("stringParameter", false));
			stringParameter->setAdditionalInformations("This parameter provides a string value", "","Test");
			_stringParameter = stringParameter;
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDuration> durationParameter(new SPICE::BIG::DataEntryTypes::DataEntryDuration("durationParameter",0, 300));
			durationParameter->setAdditionalInformations("This parameter provides a duration value", "","PT100S");
			_durationParameter = durationParameter;

			// Set, if they are required or optional
			_boolParameter->setIsNeeded(true);
			_stringParameter->setIsNeeded(true);
			_durationParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_boolParameter);
			returnVector.push_back(_stringParameter);
			returnVector.push_back(_durationParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithOtherParameters::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with other parameters";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryBool> boolResponse(new SPICE::BIG::DataEntryTypes::DataEntryBool("boolResponse"));
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryString> stringResponse(new SPICE::BIG::DataEntryTypes::DataEntryString("stringResponse",true));
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDuration> durationResponse(new SPICE::BIG::DataEntryTypes::DataEntryDuration("durationResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(boolResponse);
			responseDataSet->addDataEntry(stringResponse);
			responseDataSet->addDataEntry(durationResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithOtherParameters::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithOtherParameters::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithOtherParameters(_boolParameter->getValue(), _stringParameter->getValueAsString(), _durationParameter->getValue(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
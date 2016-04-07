/**
	SPI DeviceSimulator
	CommandWithFloatParameter.cpp
	Purpose: This command provides a parameters with float data type and return the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#include "CommandWithFloatParameter.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithFloatParameter::CommandWithFloatParameter(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_floatParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithFloatParameter::~CommandWithFloatParameter()
		{
		}

		std::string CommandWithFloatParameter::getCommandName()
		{
			return "CommandWithFloatParameter";
		}
		std::string CommandWithFloatParameter::getCommandDescription()
		{
			return "This command provides a parameters with float data type and return the value in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithFloatParameter::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryFloat> floatParameter(new SPICE::BIG::DataEntryTypes::DataEntryFloat("floatParameter"));
			floatParameter->setAdditionalInformations("This parameter provides a float value.", "","4.78");
			_floatParameter = floatParameter;

			// Set, if they are required or optional
			_floatParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_floatParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithFloatParameter::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with a float parameter";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryFloat> floatResponse(new SPICE::BIG::DataEntryTypes::DataEntryFloat("floatResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(floatResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithFloatParameter::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithFloatParameter::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithFloatParameter(_floatParameter->getValue(),  _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
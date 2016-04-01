/**
	SPI DeviceSimulator
	CommandWithFloatingParameters.cpp
	Purpose: This command provides parameters with floating data types and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#include "CommandWithFloatingParameters.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithFloatingParameters::CommandWithFloatingParameters(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_floatParameter(nullptr),
			_doubleParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithFloatingParameters::~CommandWithFloatingParameters()
		{
		}

		std::string CommandWithFloatingParameters::getCommandName()
		{
			return "CommandWithFloatingParameters";
		}
		std::string CommandWithFloatingParameters::getCommandDescription()
		{
			return "This command provides parameters with floating data types and return the values in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithFloatingParameters::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryFloat> floatParameter(new SPICE::BIG::DataEntryTypes::DataEntryFloat("floatParameter"));
			floatParameter->setAdditionalInformations("This parameter provides a float value.", "","4.78");
			_floatParameter = floatParameter;
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDouble> doubleParameter(new SPICE::BIG::DataEntryTypes::DataEntryDouble("doubleParameter", -123.45, 234.56));
			doubleParameter->setAdditionalInformations("This parameter provides a double value.", "","-3.28");
			_doubleParameter = doubleParameter;

			// Set, if they are required or optional
			_floatParameter->setIsNeeded(true);
			_doubleParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_floatParameter);
			returnVector.push_back(_doubleParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithFloatingParameters::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with floating parameters";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryFloat> floatResponse(new SPICE::BIG::DataEntryTypes::DataEntryFloat("floatResponse"));
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDouble> doubleResponse(new SPICE::BIG::DataEntryTypes::DataEntryDouble("doubleResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(floatResponse);
			responseDataSet->addDataEntry(doubleResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithFloatingParameters::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithFloatingParameters::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithFloatingParameters(_floatParameter->getValue(), _doubleParameter->getValue(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
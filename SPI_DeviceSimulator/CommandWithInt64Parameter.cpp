/**
	SPI DeviceSimulator
	CommandWithInt64Parameter.cpp
	Purpose: This command provides a parameter with Int64 and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_01
*/

#include "CommandWithInt64Parameter.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithInt64Parameter::CommandWithInt64Parameter(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_longParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithInt64Parameter::~CommandWithInt64Parameter()
		{
		}

		std::string CommandWithInt64Parameter::getCommandName()
		{
			return "CommandWithInt64Parameter";
		}
		std::string CommandWithInt64Parameter::getCommandDescription()
		{
			return "This command provides a parameter with Int64 and return the values in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithInt64Parameter::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryLong> longParameter(new SPICE::BIG::DataEntryTypes::DataEntryLong("longParameter", -9223372036854775807 -1, 9223372036854775807));
			longParameter->setAdditionalInformations("This parameter provides a long value like a coffee counter.", "cups","78");
			_longParameter = longParameter;

			// Set, if they are required or optional
			_longParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_longParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithInt64Parameter::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with Int64 parameter";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryLong> longResponse(new SPICE::BIG::DataEntryTypes::DataEntryLong("longResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(longResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithInt64Parameter::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithInt64Parameter::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithInt64Parameter(_longParameter->getValue(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
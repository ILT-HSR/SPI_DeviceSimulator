/**
	SPI DeviceSimulator
	CommandWithInt16Parameter.cpp
	Purpose: This command provides a parameter with Int16 and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_01
*/

#include "CommandWithInt16Parameter.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithInt16Parameter::CommandWithInt16Parameter(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_shortParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithInt16Parameter::~CommandWithInt16Parameter()
		{
		}

		std::string CommandWithInt16Parameter::getCommandName()
		{
			return "CommandWithInt16Parameter";
		}
		std::string CommandWithInt16Parameter::getCommandDescription()
		{
			return "This command provides a parameter with Int16 and return the values in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithInt16Parameter::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryShort> shortParameter(new SPICE::BIG::DataEntryTypes::DataEntryShort("shortParameter", -32767 - 1, 32767));
			shortParameter->setAdditionalInformations("This parameter provides a short value like speed", "mm/s","5");
			_shortParameter = shortParameter;

			// Set, if they are required or optional
			_shortParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_shortParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithInt16Parameter::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with Int16 parameter";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryShort> shortResponse(new SPICE::BIG::DataEntryTypes::DataEntryShort("shortResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(shortResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithInt16Parameter::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithInt16Parameter::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithInt16Parameter(_shortParameter->getValue(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
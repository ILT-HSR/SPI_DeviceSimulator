/**
	SPI DeviceSimulator
	CommandWithUInt16Parameter.cpp
	Purpose: This command provides a parameters with UInt16 and returns the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#include "CommandWithUInt16Parameter.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithUInt16Parameter::CommandWithUInt16Parameter(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_uShortParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithUInt16Parameter::~CommandWithUInt16Parameter()
		{
		}

		std::string CommandWithUInt16Parameter::getCommandName()
		{
			return "CommandWithUInt16Parameter";
		}
		std::string CommandWithUInt16Parameter::getCommandDescription()
		{
			return "This command provides a parameters with UInt16 and returns the value in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithUInt16Parameter::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedShort> uShortParameter(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedShort("uShortParameter", 0, 65535));
			uShortParameter->setAdditionalInformations("This parameter provides an unsigned short value like an undirected speed", "mm/s","5");
			_uShortParameter = uShortParameter;

			// Set, if they are required or optional
			_uShortParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_uShortParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithUInt16Parameter::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with uint16 parameter";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedShort> uShortResponse(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedShort("uShortResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(uShortResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithUInt16Parameter::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithUInt16Parameter::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithUInt16Parameter(_uShortParameter->getValue(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
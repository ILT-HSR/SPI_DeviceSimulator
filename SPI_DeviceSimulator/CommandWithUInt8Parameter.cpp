/**
	SPI DeviceSimulator
	CommandWithUInt8Parameter.cpp
	Purpose: This command provides a parameters with UInt8 and returns the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#include "CommandWithUInt8Parameter.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithUInt8Parameter::CommandWithUInt8Parameter(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_uByteParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithUInt8Parameter::~CommandWithUInt8Parameter()
		{
		}

		std::string CommandWithUInt8Parameter::getCommandName()
		{
			return "CommandWithUInt8Parameter";
		}
		std::string CommandWithUInt8Parameter::getCommandDescription()
		{
			return "This command provides a parameters with UInt8 and returns the value in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithUInt8Parameter::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedByte> uByteParameter(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedByte("uByteParameter", 0, UINT8_MAX));
			uByteParameter->setAdditionalInformations("This parameter provides an unsigned byte value.", "","10");
			_uByteParameter = uByteParameter;

			// Set, if they are required or optional
			_uByteParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_uByteParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithUInt8Parameter::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with uint8 parameter";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedByte> uByteResponse(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedByte("uByteResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(uByteResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithUInt8Parameter::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithUInt8Parameter::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithUInt8Parameter(_uByteParameter->getValue(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
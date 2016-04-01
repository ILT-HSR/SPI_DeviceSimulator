/**
	SPI DeviceSimulator
	CommandWithUnsignedParameters.cpp
	Purpose: This command provides parameters with all unsigned data types and return the values in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#include "CommandWithUnsignedParameters.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithUnsignedParameters::CommandWithUnsignedParameters(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_uByteParameter(nullptr),
			_uShortParameter(nullptr),
			_uIntParameter(nullptr),
			_uLongParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithUnsignedParameters::~CommandWithUnsignedParameters()
		{
		}

		std::string CommandWithUnsignedParameters::getCommandName()
		{
			return "CommandWithUnsignedParameters";
		}
		std::string CommandWithUnsignedParameters::getCommandDescription()
		{
			return "This command provides parameters with all unsigned data types and return the values in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithUnsignedParameters::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedByte> uByteParameter(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedByte("uByteParameter", 0, UINT8_MAX));
			uByteParameter->setAdditionalInformations("This parameter provides an unsigned byte value.", "","10");
			_uByteParameter = uByteParameter;
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedShort> uShortParameter(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedShort("uShortParameter", 0, 65535));
			uShortParameter->setAdditionalInformations("This parameter provides an unsigned short value like an undirected speed", "mm/s","5");
			_uShortParameter = uShortParameter;
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedInt> uIntParameter(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedInt("uIntParameter", 0, 4294967295));
			uIntParameter->setAdditionalInformations("This parameter provides an unsigned int value like a distance", "mm","20");
			_uIntParameter = uIntParameter;
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedLong> uLongParameter(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedLong("uLongParameter", 0 , 18446744073709551615));
			uLongParameter->setAdditionalInformations("This parameter provides an unsigned long value like a coffee counter.", "cups","78");
			_uLongParameter = uLongParameter;

			// Set, if they are required or optional
			_uByteParameter->setIsNeeded(true);
			_uShortParameter->setIsNeeded(true);
			_uIntParameter->setIsNeeded(true);
			_uLongParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_uByteParameter);
			returnVector.push_back(_uShortParameter);
			returnVector.push_back(_uIntParameter);
			returnVector.push_back(_uLongParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithUnsignedParameters::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with unsigned parameters";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedByte> uByteResponse(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedByte("uByteResponse"));
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedShort> uShortResponse(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedShort("uShortResponse"));
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedInt> uIntResponse(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedInt("uIntResponse"));
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedLong> uLongResponse(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedLong("uLongResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(uByteResponse);
			responseDataSet->addDataEntry(uShortResponse);
			responseDataSet->addDataEntry(uIntResponse);
			responseDataSet->addDataEntry(uLongResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithUnsignedParameters::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithUnsignedParameters::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithUnsignedParameters(_uByteParameter->getValue(), _uShortParameter->getValue(), _uIntParameter->getValue(), _uLongParameter->getValue(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
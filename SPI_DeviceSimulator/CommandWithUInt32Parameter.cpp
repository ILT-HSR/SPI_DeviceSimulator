/**
	SPI DeviceSimulator
	CommandWithUInt32Parameter.cpp
	Purpose: This command provides a parameters with UInt32 and returns the value in the response data set.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_04_06
*/

#include "CommandWithUInt32Parameter.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		CommandWithUInt32Parameter::CommandWithUInt32Parameter(std::shared_ptr<SpecificCore> specificCore) :
			SpecificCommandBase(specificCore),
			_uIntParameter(nullptr),
			_responseDataSet(nullptr)
		{
		}
		CommandWithUInt32Parameter::~CommandWithUInt32Parameter()
		{
		}

		std::string CommandWithUInt32Parameter::getCommandName()
		{
			return "CommandWithUInt32Parameter";
		}
		std::string CommandWithUInt32Parameter::getCommandDescription()
		{
			return "This command provides a parameters with UInt32 and returns the value in the response data set.";
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> CommandWithUInt32Parameter::createAndGetAdditionalCommandParameters()
		{
			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedInt> uIntParameter(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedInt("uIntParameter", 0, 4294967295u));
			uIntParameter->setAdditionalInformations("This parameter provides an unsigned int value like a distance", "mm","20");
			_uIntParameter = uIntParameter;

			// Set, if they are required or optional
			_uIntParameter->setIsNeeded(true);

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> returnVector;
			returnVector.push_back(_uIntParameter);

			return returnVector;
		}
		std::vector<std::shared_ptr<SPICE::BIG::DataSet>> CommandWithUInt32Parameter::getResponseDataInformation(std::string& responseDescription)
		{
			// This method is a little bit problematic cause the sila-standard has a weak definition how the responseData is descripted within the WSDL.
			// So if this function is not implemented, the responseData would not be defined within the WSDL. But it's still possible to give
			// responseData to the ServiceConsumer. Anyway at the moment their isn't a ServiceConsumer witch would analyse the responseXML. So you could left this method.

			// set a description
			responseDescription = "Response data with uint32 parameter";

			// Create the parameters
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedInt> uIntResponse(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedInt("uIntResponse"));

			// combine to a dataSet
			std::shared_ptr<SPICE::BIG::DataSet> responseDataSet(new SPICE::BIG::DataSet());
			responseDataSet->addDataEntry(uIntResponse);
			_responseDataSet = responseDataSet;

			// Create a vector and add the parameters
			std::vector<std::shared_ptr<SPICE::BIG::DataSet>> returnVector;
			returnVector.push_back(responseDataSet);

			return returnVector;
		}

		double CommandWithUInt32Parameter::calculateEstimatedDuration()
		{
			return 5;
		}

		bool CommandWithUInt32Parameter::processing()
		{
			std::string desc = "";
			getResponseDataInformation(desc);
			bool returnValue = _specificCore->commandWithUInt32Parameter(_uIntParameter->getValue(), _responseDataSet, _commandCallback);
			_commandCallback->setResponseEventData(_responseDataSet->getXMLParameterSet());
			return returnValue;
		}
	}
}
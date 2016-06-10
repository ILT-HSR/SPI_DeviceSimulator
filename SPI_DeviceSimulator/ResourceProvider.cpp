/**
	SPI DeviceSimulator
	ResourceProvider.cpp
	Purpose: Implementation of the specific resource provider

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.1 2016_06_10
*/

#include "ResourceProvider.h"

#include "XMLParserPoco.h"

#include "DataEntryUnsignedShort.h"
#include "DataEntryUnsignedInt.h"
#include "DataEntryBool.h"

#include "CommandThrowingError.h"
#include "CommandWithFloatParameter.h"
#include "CommandWithDoubleParameter.h"
#include "CommandWithBoolParameter.h"
#include "CommandWithStringParameter.h"
#include "CommandWithDurationParameter.h"
#include "CommandWithInt8Parameter.h"
#include "CommandWithInt16Parameter.h"
#include "CommandWithInt32Parameter.h"
#include "CommandWithInt64Parameter.h"
#include "CommandWithUInt8Parameter.h"
#include "CommandWithUInt16Parameter.h"
#include "CommandWithUInt32Parameter.h"
#include "CommandWithUInt64Parameter.h"
#include "NonParallelCommandExecution1.h"
#include "NonParallelCommandExecution2.h"
#include "ParallelCommandExecution1.h"
#include "ParallelCommandExecution2.h"
#include "SpecificInit.h"
#include "SpecificSetParameters.h"
#include "SpecificReset.h"

namespace SPI
{
	namespace DeviceSimulator
	{

		ResourceProvider::ResourceProvider() :
			_specificCoreContainer(nullptr),
			_parameterSet(std::shared_ptr<SPICE::BIG::DataSet>(new SPICE::BIG::DataSet()))
		{
			// --- Generate parameterSet ---
			// -> Generate parameters, with names and maybe limits
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryBool> boolParameter(new SPICE::BIG::DataEntryTypes::DataEntryBool("BoolParameter"));
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryInt> intParameter(new SPICE::BIG::DataEntryTypes::DataEntryInt("IntParameter", -100, 100));
			std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryUnsignedInt> unsignedIntParameter(new SPICE::BIG::DataEntryTypes::DataEntryUnsignedInt("UnsignedIntParameter", 0, 100));

			// -> Add description, unit and default-value
			boolParameter->setAdditionalInformations("This parameter defines a bool value","","true");
			intParameter->setAdditionalInformations("This parameter defines a int value like a speed.", "mm/s","3");
			unsignedIntParameter->setAdditionalInformations("This parameter defines an uint value like a position","mm","0");

			// -> define init-value (normaly the default-value)
			boolParameter->setValue(true);
			intParameter->setValue(3);
			unsignedIntParameter->setValue(0);

			// -> add parameters to the parameterSet
			_parameterSet->addDataEntry(boolParameter);
			_parameterSet->addDataEntry(intParameter);
			_parameterSet->addDataEntry(unsignedIntParameter);


			// --- Generate configurationSet ---
			// -> can be generated like the parameterSets. This examples shows, how to use parameterSet as configurationSet too
			_configSets[1] = _parameterSet;
			// -> Load configuration from an XML-File.
			_configSets[1]->loadParameterSetFromPath("configuration1.xml", getNewXMLParserInstance());
			// -> to password protect the configuration
			//_configSets[1]->setPassword("examplePassword");
		}
		ResourceProvider::~ResourceProvider()
		{
		}

		std::vector<std::shared_ptr<SPICE::BIG::CommandBase>> ResourceProvider::getInstanceOfAllCommands()
		{
			std::vector<std::shared_ptr<SPICE::BIG::CommandBase>> returnVector;

			returnVector.push_back(createCommand("CommandThrowingError"));
			returnVector.push_back(createCommand("CommandWithFloatParameter"));
			returnVector.push_back(createCommand("CommandWithDoubleParameter"));
			returnVector.push_back(createCommand("CommandWithBoolParameter"));
			returnVector.push_back(createCommand("CommandWithStringParameter"));
			returnVector.push_back(createCommand("CommandWithDurationParameter"));
			returnVector.push_back(createCommand("CommandWithInt8Parameter"));
			returnVector.push_back(createCommand("CommandWithInt16Parameter"));
			returnVector.push_back(createCommand("CommandWithInt32Parameter"));
			returnVector.push_back(createCommand("CommandWithInt64Parameter"));
			returnVector.push_back(createCommand("CommandWithUInt8Parameter"));
			returnVector.push_back(createCommand("CommandWithUInt16Parameter"));
			returnVector.push_back(createCommand("CommandWithUInt32Parameter"));
			returnVector.push_back(createCommand("CommandWithUInt64Parameter"));
			returnVector.push_back(createCommand("NonParallelCommandExecution1"));
			returnVector.push_back(createCommand("NonParallelCommandExecution2"));
			returnVector.push_back(createCommand("ParallelCommandExecution1"));
			returnVector.push_back(createCommand("ParallelCommandExecution2"));
			return returnVector;
		}
		std::shared_ptr<SPICE::BIG::CommandBase> ResourceProvider::createCommand(std::string commandName)
		{
			std::shared_ptr<SPICE::BIG::CommandBase> command = nullptr;
			if(commandName == "CommandThrowingError")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new CommandThrowingError(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "CommandWithFloatParameter")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new CommandWithFloatParameter(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "CommandWithDoubleParameter")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new CommandWithDoubleParameter(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "CommandWithBoolParameter")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new CommandWithBoolParameter(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "CommandWithStringParameter")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new CommandWithStringParameter(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "CommandWithDurationParameter")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new CommandWithDurationParameter(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "CommandWithInt8Parameter")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new CommandWithInt8Parameter(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "CommandWithInt16Parameter")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new CommandWithInt16Parameter(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "CommandWithInt32Parameter")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new CommandWithInt32Parameter(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "CommandWithInt64Parameter")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new CommandWithInt64Parameter(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "CommandWithUInt8Parameter")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new CommandWithUInt8Parameter(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "CommandWithUInt16Parameter")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new CommandWithUInt16Parameter(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "CommandWithUInt32Parameter")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new CommandWithUInt32Parameter(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "CommandWithUInt64Parameter")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new CommandWithUInt64Parameter(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "NonParallelCommandExecution1")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new NonParallelCommandExecution1(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "NonParallelCommandExecution2")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new NonParallelCommandExecution2(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "ParallelCommandExecution1")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new ParallelCommandExecution1(_specificCoreContainer->getSpecificCore()));
			}
			else if(commandName == "ParallelCommandExecution2")
			{
				command = std::shared_ptr<SPICE::BIG::CommandBase>(new ParallelCommandExecution2(_specificCoreContainer->getSpecificCore()));
			}
			return command;
		}
		std::shared_ptr<SPICE::BIG::SpecificBase> ResourceProvider::getSpecificInit()
		{
			std::shared_ptr<SpecificInit> specificInit(new SpecificInit(_specificCoreContainer->getSpecificCore()));
			return specificInit;
		}
		std::shared_ptr<SPICE::BIG::SpecificBase> ResourceProvider::getSpecificSetParameters()
		{
			std::shared_ptr<SpecificSetParameters> specificSetParameters(new SpecificSetParameters(_specificCoreContainer->getSpecificCore()));
			return specificSetParameters;
		}
		std::shared_ptr<SPICE::BIG::SpecificResetBase> ResourceProvider::getSpecificReset()
		{
			std::shared_ptr<SpecificReset> specificReset(new SpecificReset(_specificCoreContainer));
			return specificReset;
		}

		std::shared_ptr<SPICE::BIG::DataSet> ResourceProvider::getParameterSet()
		{
			return _parameterSet;
		}
		std::shared_ptr<SPICE::BIG::DataSet> ResourceProvider::getConfigurationSet(int configLevel, std::string password)
		{
			if(_configSets.find(configLevel) != _configSets.end())
			{
				std::string configPassword = _configSets[configLevel]->getPassword();
				if(configPassword == password || configPassword == "")
				{
					return _configSets[configLevel];
				}
			}
			return nullptr;
		}
		void ResourceProvider::configurationSetHasChanged(int configLevel)
		{
			if(_configSets.find(configLevel) != _configSets.end())
			{
				_configSets[configLevel]->writeParameterSetToPath("configuration" + std::to_string(configLevel) + ".xml");
			}
		}

		void ResourceProvider::getDeviceIdentification(std::string& uriPathName, int& silaDevicClass, std::string& deviceManufacturer, std::string& deviceName, std::string& deviceSerialNumber, std::string& deviceFirmwareVersion, bool& includeConverterIdentification)
		{
			uriPathName = "/" + getCoreConfigurationParameter("URI_PATHNAME");
			silaDevicClass = getDeviceClass();
			deviceManufacturer = "ilt.hsr.ch";
			deviceName = "DeviceSimulator";
			deviceSerialNumber = "-";
			deviceFirmwareVersion = "v1.0.1 - 20160610";
			includeConverterIdentification = true; // true -> includes the identification of SPICE
		}
		int ResourceProvider::getDeviceClass()
		{
			return 1000;
		}
		std::string ResourceProvider::getCoreConfigurationParameter(std::string parameterName)
		{
			if(parameterName == "URI_PATHNAME")
			{
				return "DeviceSimulator"; // default: "<DeviceClass>"
			}
			else if(parameterName == "SERIAL_NUMBER_EXTENSION")
			{
				return ""; // default: ""
			}
			else if(parameterName == "USE_WSDISCOVERY")
			{
				return "true"; // default: "false"
			}
			else if(parameterName == "NICELABFIX_SUBSTATES")
			{
				return "true"; // default: "false"
			}
			else if(parameterName == "SILA_NS_PREFIX")
			{
				return ""; // default "", example: "sila:"
			}
			return "";
		}

		std::shared_ptr<SPICE::BIG::IXMLParser> ResourceProvider::getNewXMLParserInstance()
		{
			std::shared_ptr<SPICE::XML::POCO::XMLParserPoco> xmlParser(new SPICE::XML::POCO::XMLParserPoco());
			return xmlParser;
		}

		void ResourceProvider::setSpecificCoreContainer(std::shared_ptr<SpecificCoreContainer> specificCoreContainer)
		{
			_specificCoreContainer = specificCoreContainer;
		}

	}
}
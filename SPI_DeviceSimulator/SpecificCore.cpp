/**
	SPI DeviceSimulator
	SpecificCore.cpp
	Purpose: Central class of a specific implemention. An instance is just deleted and new generated with the reset command. Every command can use it.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#include "SpecificCore.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		SpecificCore::SpecificCore(bool simulationMode, std::shared_ptr<SPICE::BIG::IResourceProvider> resourceProvider) :
			_simulationMode(simulationMode),
			_resourceProvider(resourceProvider)
		{
		}
		SpecificCore::~SpecificCore()
		{
		}

		// Implementations of the expected time calculations.
		// They can be fix or calculated depending on parameters and configurations.
		// If no time can be calculated, return 0;
		double SpecificCore::calculateTimePrepareForReset()
		{
			return 5;
		}
		double SpecificCore::calculateTimeInitialize()
		{
			return 5;
		}
		double SpecificCore::calculateTimeSetParameters()
		{
			return 3;
		}

		// Implementation of the functions
		// Use commandCallback to check cyclic if a command should pause, abort or reset
		// Pause -> reach stable state and call commanCallback-Function enterPause
		// Abort -> abort immediate and try to reach a stable state.
		// Reset -> do nothing else, try direct to return. Actions should be done withing the prepareForReset-Function
		// The bool returnValue stands for success execution. Return false if their is a not recoverable error.
		void SpecificCore::prepareForReset(std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			executeDuration(5, commandCallback);
		}
		bool SpecificCore::initialize(std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			return executeDuration(5, commandCallback);
		}
		bool SpecificCore::setParameters(std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			return executeDuration(3, commandCallback);
		}

		bool SpecificCore::commandWithSignedParameters(char byteParameter, short shortParameter, int intParameter, int64_t longParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			bool returnValue = executeDuration(5, commandCallback);
			responseDataSet->getFirstDataEntryByName("byteResponse")->setValueString(std::to_string(byteParameter));
			responseDataSet->getFirstDataEntryByName("shortResponse")->setValueString(std::to_string(shortParameter));
			responseDataSet->getFirstDataEntryByName("intResponse")->setValueString(std::to_string(intParameter));
			responseDataSet->getFirstDataEntryByName("longResponse")->setValueString(std::to_string(longParameter));
			return returnValue;
		}
		bool SpecificCore::commandWithInt8Parameter(int8_t byteParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			bool returnValue = executeDuration(5, commandCallback);
			responseDataSet->getFirstDataEntryByName("byteResponse")->setValueString(std::to_string(byteParameter));
			return returnValue;
		}
		bool SpecificCore::commandWithInt16Parameter(int16_t shortParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			bool returnValue = executeDuration(5, commandCallback);
			responseDataSet->getFirstDataEntryByName("shortResponse")->setValueString(std::to_string(shortParameter));
			return returnValue;
		}
		bool SpecificCore::commandWithInt32Parameter(int32_t intParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			bool returnValue = executeDuration(5, commandCallback);
			responseDataSet->getFirstDataEntryByName("intResponse")->setValueString(std::to_string(intParameter));
			return returnValue;
		}
		bool SpecificCore::commandWithInt64Parameter(int64_t longParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			bool returnValue = executeDuration(5, commandCallback);
			responseDataSet->getFirstDataEntryByName("longResponse")->setValueString(std::to_string(longParameter));
			return returnValue;
		}
		bool SpecificCore::commandWithUInt8Parameter(uint8_t uByteParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			bool returnValue = executeDuration(5, commandCallback);
			responseDataSet->getFirstDataEntryByName("uByteResponse")->setValueString(std::to_string(uByteParameter));
			return returnValue;
		}
		bool SpecificCore::commandWithUInt16Parameter(uint16_t uShortParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			bool returnValue = executeDuration(5, commandCallback);
			responseDataSet->getFirstDataEntryByName("uShortResponse")->setValueString(std::to_string(uShortParameter));
			return returnValue;
		}
		bool SpecificCore::commandWithUInt32Parameter(uint32_t uIntParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			bool returnValue = executeDuration(5, commandCallback);
			responseDataSet->getFirstDataEntryByName("uIntResponse")->setValueString(std::to_string(uIntParameter));
			return returnValue;
		}
		bool SpecificCore::commandWithUInt64Parameter(uint64_t uLongParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			bool returnValue = executeDuration(5, commandCallback);
			responseDataSet->getFirstDataEntryByName("uLongResponse")->setValueString(std::to_string(uLongParameter));
			return returnValue;
		}
		bool SpecificCore::commandWithFloatParameter(float floatParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			bool returnValue = executeDuration(5, commandCallback);
			responseDataSet->getFirstDataEntryByName("floatResponse")->setValueString(std::to_string(floatParameter));
			return returnValue;
		}
		bool SpecificCore::commandWithDoubleParameter(double doubleParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			bool returnValue = executeDuration(5, commandCallback);
			responseDataSet->getFirstDataEntryByName("doubleResponse")->setValueString(std::to_string(doubleParameter));
			return returnValue;
		}
		bool SpecificCore::commandWithBoolParameter(bool boolParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			bool returnValue = executeDuration(5, commandCallback);
			responseDataSet->getFirstDataEntryByName("boolResponse")->setValueString(std::to_string(boolParameter));
			return returnValue;
		}
		bool SpecificCore::commandWithStringParameter(std::string stringParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			bool returnValue = executeDuration(5, commandCallback);
			responseDataSet->getFirstDataEntryByName("stringResponse")->setValueString(stringParameter);
			return returnValue;
		}
		bool SpecificCore::commandWithDurationParameter(double durationParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			bool returnValue = executeDuration(5, commandCallback);
			responseDataSet->getFirstDataEntryByName("durationResponse")->setValueString(std::to_string(durationParameter));
			return returnValue;
		}

		bool SpecificCore::commandForNonParallelExecution(double executionDuration, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			return executeDuration(executionDuration, commandCallback);
		}
		bool SpecificCore::commandForParallelExecution(double executionDuration, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			return executeDuration(executionDuration, commandCallback);
		}

		bool SpecificCore::commandThrowingError(double durationUntilThrowingError, int errorType, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			if(!executeDuration(durationUntilThrowingError, commandCallback))
			{
				return false;
			}
			std::shared_ptr<SPICE::BIG::CommandError> error = nullptr;

			switch(errorType)
			{
			case 1 : // fatal
				error = std::shared_ptr<SPICE::BIG::CommandError>(new SPICE::BIG::CommandError("This is a fatal error. State machine will turn into InError-state.", "EnterInError", "Enters the inError state. A SiLA-Reset is needed.", SPICE::BIG::ContinuationTask::TaskTypes::fatalError));
				break;
			case 2 : // aborting
				error = std::shared_ptr<SPICE::BIG::CommandError>(new SPICE::BIG::CommandError("This is an error where the command at least has to abort", "AbortThis", "Aborts this command.", SPICE::BIG::ContinuationTask::TaskTypes::abortCurrentCommand));
				error->addContinuationTask("AbortAll", "Aborts this command and empty the command buffer.", SPICE::BIG::ContinuationTask::TaskTypes::abortAllCommands);
				error->addContinuationTask("EnterInError", "Enters the inError state. A SiLA-Reset is needed.", SPICE::BIG::ContinuationTask::TaskTypes::fatalError);
				break;
			case 3 : // continuation
				error = std::shared_ptr<SPICE::BIG::CommandError>(new SPICE::BIG::CommandError("This is an error with a continuation option.", "Continue", "Tries to continue the command.", SPICE::BIG::ContinuationTask::TaskTypes::continueCommand));
				error->addContinuationTask("AbortThis", "Aborts this command.", SPICE::BIG::ContinuationTask::TaskTypes::abortCurrentCommand);
				error->addContinuationTask("AbortAll", "Aborts this command and empty the command buffer.", SPICE::BIG::ContinuationTask::TaskTypes::abortAllCommands);
				error->addContinuationTask("EnterInError", "Enters the inError state. A SiLA-Reset is needed.", SPICE::BIG::ContinuationTask::TaskTypes::fatalError);
				break;
			case 4 : // failing continuation
				error = std::shared_ptr<SPICE::BIG::CommandError>(new SPICE::BIG::CommandError("This is an error with a failing continuation option.", "Continue", "Tries to continue the command (will fail).", SPICE::BIG::ContinuationTask::TaskTypes::continueCommand));
				error->addContinuationTask("AbortThis", "Aborts this command.", SPICE::BIG::ContinuationTask::TaskTypes::abortCurrentCommand);
				error->addContinuationTask("AbortAll", "Aborts this command and empty the command buffer.", SPICE::BIG::ContinuationTask::TaskTypes::abortAllCommands);
				error->addContinuationTask("EnterInError", "Enters the inError state. A SiLA-Reset is needed.", SPICE::BIG::ContinuationTask::TaskTypes::fatalError);
				break;
			default :
				return true;
				break;
			}

			commandCallback->throwError(error);
			if(error->getSelectedTaskType() == SPICE::BIG::ContinuationTask::TaskTypes::continueCommand)
			{
				if(errorType == 4)
				{
					return commandThrowingError(2, 4, commandCallback);
				}
				else
				{
					return executeDuration(5, commandCallback);
				}
			}
			else
			{
				return false;
			}
		}

		bool SpecificCore::executeDuration(double duration, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback)
		{
			double durationCounter = 0;
			while(durationCounter < duration)
			{
				// wait on end of process and check for interupts from the ServiceConsumer
				if(commandCallback->hasToAbortOrReset())
				{
					return false;
				}
				else if(commandCallback->hasToPause())
				{
					commandCallback->enterPause();
				}
				else
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(20));
					durationCounter += 0.02;
				}
			}
			return true;
		}


	}
}
/**
	SPI DeviceSimulator
	SpecificCore.h
	Purpose: Central class of a specific implemention. Usually used to communicate with the device. An instance is just deleted and new generated with the reset command. Every command can use it.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_01_22
*/

#ifndef SPECIFICCORE_H
#define SPECIFICCORE_H

#include <memory>
#include <queue>
#include <thread>

#include "IResourceProvider.h"
#include "ICommandCallback.h"
#include "GeneralFunctions.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class SpecificCore
		{
			public:

				SpecificCore(bool simulationMode, std::shared_ptr<SPICE::BIG::IResourceProvider> resourceProvider);
				virtual ~SpecificCore();

				double calculateTimePrepareForReset();
				double calculateTimeInitialize();
				double calculateTimeSetParameters();

				void prepareForReset(std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool initialize(std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool setParameters(std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);

				bool commandWithSignedParameters(char byteParameter, short shortParameter, int intParameter, int64_t longParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool commandWithInt8Parameter(int8_t byteParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool commandWithInt16Parameter(int16_t shortParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool commandWithInt32Parameter(int32_t intParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool commandWithInt64Parameter(int64_t longParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool commandWithUnsignedParameters(unsigned char uByteParameter, unsigned short uShortParameter, unsigned int uIntParameter, uint64_t uLongParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool commandWithUInt8Parameter(uint8_t byteParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool commandWithUInt16Parameter(uint16_t shortParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool commandWithUInt32Parameter(uint32_t intParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool commandWithUInt64Parameter(uint64_t longParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool commandWithFloatParameter(float floatParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool commandWithDoubleParameter(double doubleParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool commandWithBoolParameter(bool boolParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool commandWithStringParameter(std::string stringParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool commandWithDurationParameter(double durationParameter, std::shared_ptr<SPICE::BIG::DataSet> responseDataSet, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);

				bool commandForNonParallelExecution(double executionDuration, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
				bool commandForParallelExecution(double executionDuration, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);

				bool commandThrowingError(double durationUntilThrowingError, int errorType, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);
		
			protected:
			private:

				bool executeDuration(double duration, std::shared_ptr<SPICE::BIG::ICommandCallback> commandCallback);

				bool _simulationMode;
				std::shared_ptr<SPICE::BIG::IResourceProvider> _resourceProvider;

		};
	}
}
#endif // SPECIFICCORE_H

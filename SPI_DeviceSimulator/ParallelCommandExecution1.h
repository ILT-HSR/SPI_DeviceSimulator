/**
	SPI DeviceSimulator
	ParallelCommandExecution1.h
	Purpose: This command is able to run parallel with other commands with the same possibility.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#ifndef PARALLELCOMMANDEXECUTION1_H
#define PARALLELCOMMANDEXECUTION1_H

#include "SpecificCommandBase.h"

#include "DataEntryDuration.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class ParallelCommandExecution1 : public SpecificCommandBase
		{
			public:
				ParallelCommandExecution1(std::shared_ptr<SpecificCore> specificCore);
				virtual ~ParallelCommandExecution1();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();

				virtual double calculateEstimatedDuration();

				virtual bool readyForStart();
				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDuration> _executionDuration;
		};
	}
}
#endif // PARALLELCOMMANDEXECUTION1_H

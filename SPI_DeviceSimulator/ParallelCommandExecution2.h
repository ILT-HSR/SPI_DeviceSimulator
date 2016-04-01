/**
	SPI DeviceSimulator
	ParallelCommandExecution2.h
	Purpose: This command is able to run parallel with other commands with the same possibility.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#ifndef PARALLELCOMMANDEXECUTION2_H
#define PARALLELCOMMANDEXECUTION2_H

#include "SpecificCommandBase.h"

#include "DataEntryDuration.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class ParallelCommandExecution2 : public SpecificCommandBase
		{
			public:
				ParallelCommandExecution2(std::shared_ptr<SpecificCore> specificCore);
				virtual ~ParallelCommandExecution2();

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
#endif // PARALLELCOMMANDEXECUTION2_H

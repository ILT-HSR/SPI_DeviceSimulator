/**
	SPI DeviceSimulator
	NonParallelCommandExecution2.h
	Purpose: This command isn't able to run parallel with other commands.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#ifndef NONPARALLELCOMMANDEXECUTION2_H
#define NONPARALLELCOMMANDEXECUTION2_H

#include "SpecificCommandBase.h"

#include "DataEntryDuration.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class NonParallelCommandExecution2 : public SpecificCommandBase
		{
			public:
				NonParallelCommandExecution2(std::shared_ptr<SpecificCore> specificCore);
				virtual ~NonParallelCommandExecution2();

				virtual std::string getCommandName();
				virtual std::string getCommandDescription();
				virtual std::vector<std::shared_ptr<SPICE::BIG::DataEntry>> createAndGetAdditionalCommandParameters();

				virtual double calculateEstimatedDuration();

				virtual bool processing();

			protected:
			private:
				std::shared_ptr<SPICE::BIG::DataEntryTypes::DataEntryDuration> _executionDuration;
		};
	}
}
#endif // NONPARALLELCOMMANDEXECUTION2_H

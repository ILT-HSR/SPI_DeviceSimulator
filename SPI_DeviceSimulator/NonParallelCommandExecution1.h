/**
	SPI DeviceSimulator
	NonParallelCommandExecution1.h
	Purpose: This command isn't able to run parallel with other commands.

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2016_03_31
*/

#ifndef NONPARALLELCOMMANDEXECUTION1_H
#define NONPARALLELCOMMANDEXECUTION1_H

#include "SpecificCommandBase.h"

#include "DataEntryDuration.h"

namespace SPI
{
	namespace DeviceSimulator
	{
		class NonParallelCommandExecution1 : public SpecificCommandBase
		{
			public:
				NonParallelCommandExecution1(std::shared_ptr<SpecificCore> specificCore);
				virtual ~NonParallelCommandExecution1();

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
#endif // NONPARALLELCOMMANDEXECUTION1_H

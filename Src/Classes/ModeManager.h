/*
 * SteeringManager.h
 *
 *  Created on: Jan 11, 2020
 *      Author: rvbc-
 */

#ifndef TASKS_STEERINGMANAGER_H_
#define TASKS_STEERINGMANAGER_H_

#include "main.h"
#include "LightsManager.h"

#define TIM_IDLE htim13

class ModeManager {
public:
	enum RC_MODE{
		DISARMED = 0,
		MODE_AUTONOMOUS,
		MODE_SEMI,
		MODE_ACRO
	};

	enum DRIVE_MODE{
		DISABLE = 0,
		ENABLE
	};

	enum SERVICE_MODE{
		CUP = 0,
		TESTING

	};

	void init();
	void proccess();
	RC_MODE getRCmode();
	DRIVE_MODE getDriveMode();
	SERVICE_MODE getServiceMode();

	void ToggleServiceMode();

	void modeDelayTimIT();
	ModeManager();
	virtual ~ModeManager();
private:
	const uint32_t task_dt = 1u;
	RC_MODE rc_mode = DISARMED;
	DRIVE_MODE drive_mode = DISABLE;
	SERVICE_MODE service_mode = CUP;
	void startUnlockDriveTimer();
	void breakUnlockDriveTimer();
	uint8_t isUnlockDriveTimerRunning = false;
	uint8_t firstUnlockDriveTimerIT_flag = true;

};

extern ModeManager mode_manager;

#endif /* TASKS_STEERINGMANAGER_H_ */

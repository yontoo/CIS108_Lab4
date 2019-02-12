/* (c) 2019 Reno Technology Academy, Multnomah University */
/*
  Course:		CIS108 - Introduction to Software Development
  Author:		Kory William Herzinger
  Description:	Lab Assignment #4 / Exercise #1
				Security System
  Purpose:		Implements the security alarm IoT device
*/

#include "SecurityAlarm.h"

#define OUTPUT_EVENTS_TO_CONSOLE

#ifdef OUTPUT_EVENTS_TO_CONSOLE
	#include <iostream>
#endif

namespace SecurityAlarm
{

	SecurityAlarmEventHandler securityAlarmEventHandler = nullptr;

	bool alarmEnabled = false;
	bool isAlarming = false;

	// Initializes the security alarm
	void initializeSecurityAlarm (SecurityAlarmEventHandler event_handler)
	{
		securityAlarmEventHandler = event_handler;
	}

	// Enables the security alarm
	void enableAlarm ()
	{
		if (!alarmEnabled)
		{
			alarmEnabled = true;

			#ifdef OUTPUT_EVENTS_TO_CONSOLE
				std::cout << "[SecurityAlarm] The alarm is enabled" << std::endl;
			#endif

			securityAlarmEventHandler (SecurityAlarmEvent::ALARM_ENABLED);
		}
	}

	// Disables the security alarm
	void disableAlarm ()
	{
		if (alarmEnabled)
		{
			alarmEnabled = false;

			#ifdef OUTPUT_EVENTS_TO_CONSOLE
				std::cout << "[SecurityAlarm] The alarm is disabled" << std::endl;
			#endif

			securityAlarmEventHandler (SecurityAlarmEvent::ALARM_DISABLED);
		}
	}

	// Triggers the security alarm and optionally notifies the authorities
	void triggerAlarm (bool notify_authorities)
	{
		if (!isAlarming)
		{
			isAlarming = true;

			#ifdef OUTPUT_EVENTS_TO_CONSOLE
				std::cout << "[SecurityAlarm] The alarm has been triggered: ALARM! ALARM! ALARM!" << std::endl;
				if (notify_authorities)
					std::cout << "[SecurityAlarm] The authorities have been notified" << std::endl;
			#endif

			securityAlarmEventHandler (SecurityAlarmEvent::ALARM_TRIGGERED);
		}
	}

	// Resets the security alarm
	void resetAlarm ()
	{
		if (isAlarming)
		{
			isAlarming = false;

			#ifdef OUTPUT_EVENTS_TO_CONSOLE
				std::cout << "[SecurityAlarm] The alarm has been reset" << std::endl;
			#endif

			securityAlarmEventHandler (SecurityAlarmEvent::ALARM_RESET);
		}
	}

}

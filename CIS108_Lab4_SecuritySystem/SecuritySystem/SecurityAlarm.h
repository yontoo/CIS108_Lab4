/* (c) 2019 Reno Technology Academy, Multnomah University */
/*
  Course:		CIS108 - Introduction to Software Development
  Author:		Kory William Herzinger
  Description:	Lab Assignment #4 / Exercise #1
				Security System
  Purpose:		Declares the security alarm IoT device
*/

#pragma once

#include <functional>

namespace SecurityAlarm
{
	// List of door lock events
	enum class SecurityAlarmEvent : int
	{
		ALARM_ENABLED,				// event that indicates the alarm was enabled
		ALARM_DISABLED,				// event that indicates the alarm was disabled
		ALARM_TRIGGERED,			// event that indicates the alarm was triggered
		ALARM_RESET					// event that indicates the alarm was reset
	};

	// The security alarm event handler
	typedef std::function<void (SecurityAlarmEvent)> SecurityAlarmEventHandler;

	// Initializes the security alarm
	void initializeSecurityAlarm (SecurityAlarmEventHandler event_handler);

	// Enables the security alarm
	void enableAlarm ();

	// Disables the security alarm
	void disableAlarm ();

	// Triggers the security alarm and optionally notifies the authorities
	void triggerAlarm (bool notify_authorities);

	// Resets the security alarm
	void resetAlarm ();
}

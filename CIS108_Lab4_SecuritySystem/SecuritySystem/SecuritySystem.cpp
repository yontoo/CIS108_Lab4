/* (c) 2019 Reno Technology Academy, Multnomah University */
/*
  Course:		CIS108 - Introduction to Software Development
  Author:		Kory William Herzinger
  Description:	Lab Assignment #4 / Exercise #1
				Security System
  Purpose:		Implements the smart home security system
*/

#include <iostream>
#include <string>
#include "SecuritySystem.h"

#include "DoorLock.h"
#include "MobileAppInterface.h"
#include "SecurityAlarm.h"
#include "VideoDoorbell.h"
#include "WindowSensor.h"

using namespace std;
using namespace SecuritySystem;

const std::string SECURE_PIN_CODE = "5297";
const char* ALLOW_ACCESS [] = {
	"Steve Jobs",
	"Jeff Bezos"
};

bool access_granted = false;
bool allowed_person_inside = false;

bool isPersonAllowed (std::string person)
{
	bool is_allowed = false;

	for (int x = 0; x < (sizeof (ALLOW_ACCESS) / sizeof (char*)); x++)
	{
		if (person == ALLOW_ACCESS[x])
		{
			is_allowed = true;
			break;
		}
	}

	return is_allowed;
}

// Handles events from the smart door lock IoT device
void ssDoorLockEventHandler (DoorLock::DoorLockEvent event, int pin_code)
{
	// NOTE: The pin_code is only valid for the PIN_CODE_ENTERED event

	switch (event)
	{
		case DoorLock::DoorLockEvent::DOOR_LOCKED:
		{
		} break;

		case DoorLock::DoorLockEvent::DOOR_UNLOCKED:
		{
		} break;

		case DoorLock::DoorLockEvent::DOOR_OPENED:
		{
			if (allowed_person_inside)
			{
				// it appears the person is leaving
				allowed_person_inside = false;
			}
			else
			{
				if (access_granted)
				{
					// access was granted to this person
					allowed_person_inside = true;
				}
				else
				{
					// access was NOT granted to this person
					SecurityAlarm::triggerAlarm (true);
				}
			}
		} break;

		case DoorLock::DoorLockEvent::DOOR_CLOSED:
		{
			access_granted = false;
			DoorLock::lockDoor ();
		} break;

		case DoorLock::DoorLockEvent::PIN_CODE_ENTERED:
		{
			if (pin_code == stoi(SECURE_PIN_CODE))
			{
				access_granted = true;
				DoorLock::unlockDoor ();
			}
		} break;
	}
}

// Handles events from the smart video doorbell IoT device
void ssVideoDoorbellEventHandler (VideoDoorbell::VideoDoorbellEvent event, std::string person_at_door)
{
	// NOTE: The person_at_door is only valid for the SOMEONE_AT_THE_DOOR event

	switch (event)
	{
		case VideoDoorbell::VideoDoorbellEvent::DOORBELL_RING:
		{
			MobileAppInterface::notifyDoorbellRing ();
		} break;

		case VideoDoorbell::VideoDoorbellEvent::SOMEONE_AT_THE_DOOR:
		{
			MobileAppInterface::notifyFrontDoorActivity (true, person_at_door);

			if (!isPersonAllowed (person_at_door))
			{
				access_granted = true;
				DoorLock::unlockDoor ();
			}
		} break;

		case VideoDoorbell::VideoDoorbellEvent::NO_ONE_AT_THE_DOOR:
		{
			MobileAppInterface::notifyFrontDoorActivity(false);
		} break;
	}
}

// Handles events from the smart security alarm IoT device
void ssSecurityAlarmEventHandler (SecurityAlarm::SecurityAlarmEvent event)
{
	switch (event)
	{
		case SecurityAlarm::SecurityAlarmEvent::ALARM_ENABLED:
		{
		} break;

		case SecurityAlarm::SecurityAlarmEvent::ALARM_DISABLED:
		{
		} break;

		case SecurityAlarm::SecurityAlarmEvent::ALARM_TRIGGERED:
		{
		} break;

		case SecurityAlarm::SecurityAlarmEvent::ALARM_RESET:
		{
		} break;
	}
}

// Handles events from the smart window sensor IoT device
void ssWindowSensorEventHandler (WindowSensor::WindowSensorEvent event)
{
	switch (event)
	{
		case WindowSensor::WindowSensorEvent::WINDOW_OPENED:
		{
			SecurityAlarm::triggerAlarm (true);
		} break;

		case WindowSensor::WindowSensorEvent::WINDOW_CLOSED:
		{
		} break;
	}
}

// Handles events from the mobile app
void ssMobileAppEventHandler (MobileAppInterface::MobileAppEvent event)
{
	switch (event)
	{
		case MobileAppInterface::MobileAppEvent::REQUEST_DOOR_LOCK:
		{
			access_granted = false;
			DoorLock::lockDoor ();
		} break;

		case MobileAppInterface::MobileAppEvent::REQUEST_DOOR_UNLOCK:
		{
			access_granted = true;
			DoorLock::unlockDoor ();
		} break;
	}
}

// Initializes the security system
void SecuritySystem::initializeSecuritySystem ()
{
	// initialize the door lock
	DoorLock::initializeDoorLock (ssDoorLockEventHandler);

	// initialize the video doorbell
	VideoDoorbell::initializeDoorbell (ssVideoDoorbellEventHandler);

	// initialize the security alarm
	SecurityAlarm::initializeSecurityAlarm (ssSecurityAlarmEventHandler);

	// initialize the window sensor
	WindowSensor::initializeWindowSensor (ssWindowSensorEventHandler);

	// initialize the mobile app
	MobileAppInterface::initializeMobileApp (ssMobileAppEventHandler);
}

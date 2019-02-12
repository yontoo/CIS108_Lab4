/* (c) 2019 Reno Technology Academy, Multnomah University */
/*
  Course:		CIS108 - Introduction to Software Development
  Author:		Kory William Herzinger
  Description:	Lab Assignment #4 / Exercise #1
				Security System
  Purpose:		Implements the smart video doorbell IoT device
*/

#include "DoorLock.h"

#define OUTPUT_EVENTS_TO_CONSOLE

#ifdef OUTPUT_EVENTS_TO_CONSOLE
	#include <iostream>
#endif

namespace DoorLock
{

	DoorLockEventHandler doorLockEventHandler = nullptr;

	bool doorState = false;
	bool doorLockState = true;

	// Initializes the door lock
	void initializeDoorLock (DoorLockEventHandler event_handler)
	{
		doorLockEventHandler = event_handler;
	}

	// Lock the door
	void lockDoor ()
	{
		if (!doorLockState)
		{
			doorLockState = true;

			#ifdef OUTPUT_EVENTS_TO_CONSOLE
				std::cout << "[DoorLock]      The door is locked" << std::endl;
			#endif

			doorLockEventHandler (DoorLockEvent::DOOR_LOCKED, "");
		}
	}

	// Unlock the door
	void unlockDoor ()
	{
		if (doorLockState)
		{
			doorLockState = false;

			#ifdef OUTPUT_EVENTS_TO_CONSOLE
				std::cout << "[DoorLock]      The door is unlocked" << std::endl;
			#endif

			doorLockEventHandler (DoorLockEvent::DOOR_UNLOCKED, "");
		}
	}

	// Enter a pin code
	void enterPinCode (std::string pin_code)
	{
		#ifdef OUTPUT_EVENTS_TO_CONSOLE
			std::cout << "[DoorLock]      A pin code was entered: " << pin_code << std::endl;
		#endif

		doorLockEventHandler (DoorLockEvent::PIN_CODE_ENTERED, pin_code);
	}

	// The door sensor was updated (opened/closed)
	void doorSensorUpdate (bool opened)
	{
		if (doorState != opened)
		{
			doorState = opened;

			#ifdef OUTPUT_EVENTS_TO_CONSOLE
				std::cout << "[DoorLock]      The door was " << (doorState ? "opened" : "closed") << std::endl;
			#endif

			if (doorState)
				doorLockEventHandler (DoorLockEvent::DOOR_OPENED, "");
			else
				doorLockEventHandler (DoorLockEvent::DOOR_CLOSED, "");
		}
	}

}

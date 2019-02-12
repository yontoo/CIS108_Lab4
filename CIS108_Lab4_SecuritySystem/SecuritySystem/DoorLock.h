/* (c) 2019 Reno Technology Academy, Multnomah University */
/*
  Course:		CIS108 - Introduction to Software Development
  Author:		Kory William Herzinger
  Description:	Lab Assignment #4 / Exercise #1
				Security System
  Purpose:		Declares the smart door lock IoT device
*/

#pragma once

#include <functional>
#include <string>

namespace DoorLock
{
	// List of door lock events
	enum class DoorLockEvent : int
	{
		DOOR_LOCKED,				// event that indicates the door was locked
		DOOR_UNLOCKED,				// event that indicates the door was unlocked
		DOOR_OPENED,				// event that indicates the door was opened
		DOOR_CLOSED,				// event that indicates the door was closed
		PIN_CODE_ENTERED			// event that indicates that someone has entered a pin code
	};

	// The door lock event handler
	typedef std::function<void (DoorLockEvent, std::string)> DoorLockEventHandler;

	// Initializes the door lock
	void initializeDoorLock (DoorLockEventHandler event_handler);

	// Lock the door
	void lockDoor ();

	// Unlock the door
	void unlockDoor ();

	// Enter a pin code
	void enterPinCode (std::string pin_code);

	// The door sensor was updated (opened/closed)
	void doorSensorUpdate (bool opened);
}

/* (c) 2019 Reno Technology Academy, Multnomah University */
/*
  Course:		CIS108 - Introduction to Software Development
  Author:		Kory William Herzinger
  Description:	Lab Assignment #4 / Exercise #1
				Security System
  Purpose:		Declares the mobile phone app interface
*/

#pragma once

#include <functional>
#include <string>

namespace MobileAppInterface
{
	// List of mobile app events
	enum class MobileAppEvent : int
	{
		REQUEST_DOOR_LOCK,			// event that indicates the user has requested for the door to be locked
		REQUEST_DOOR_UNLOCK			// event that indicates the user has requested for the door to be unlocked
	};

	// The mobile app event handler
	typedef std::function<void (MobileAppEvent)> MobileAppEventHandler;

	// Initializes the mobile app
	void initializeMobileApp (MobileAppEventHandler event_handler);

	// Notifies the user that the doorbell was rung
	void notifyDoorbellRing ();

	// Notifies the user of activity at the front door
	void notifyFrontDoorActivity (bool activity, std::string personAtDoor = "");

	// Notifies the user of activity at the window
	void notifyWindowActivity (bool activity);

	// Requests door lock/unlock
	void requestDoorLock (bool lock);
}

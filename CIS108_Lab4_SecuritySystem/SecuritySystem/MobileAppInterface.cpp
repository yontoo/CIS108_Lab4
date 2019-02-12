/* (c) 2019 Reno Technology Academy, Multnomah University */
/*
  Course:		CIS108 - Introduction to Software Development
  Author:		Kory William Herzinger
  Description:	Lab Assignment #4 / Exercise #1
				Security System
  Purpose:		Implements the mobile phone app interface
*/

#include "MobileAppInterface.h"

#define OUTPUT_EVENTS_TO_CONSOLE

#ifdef OUTPUT_EVENTS_TO_CONSOLE
	#include <iostream>
#endif

namespace MobileAppInterface
{

	MobileAppEventHandler mobileAppEventHandler = nullptr;

	// Initializes the door lock
	void initializeMobileApp (MobileAppEventHandler event_handler)
	{
		mobileAppEventHandler = event_handler;
	}

	// Notifies the user that the doorbell was rung
	void notifyDoorbellRing ()
	{
		#ifdef OUTPUT_EVENTS_TO_CONSOLE
			std::cout << "[MobileApp]     The owner has been notified that the doorbell was rung" << std::endl;
		#endif
	}

	// Notifies the user of activity at the front door
	void notifyFrontDoorActivity (bool activity, std::string personAtDoor)
	{
		#ifdef OUTPUT_EVENTS_TO_CONSOLE
			if (activity)
				std::cout << "[MobileApp]     The owner has been notified that '" << personAtDoor << "' is at the door" << std::endl;
			else
				std::cout << "[MobileApp]     The owner has been notified that no one is at the door" << std::endl;
		#endif
	}

	// Notifies the user of activity at the window
	void notifyWindowActivity (bool activity)
	{
		#ifdef OUTPUT_EVENTS_TO_CONSOLE
			std::cout << "[MobileApp]     The owner has been notified of window sensor " << (activity ? "activity" : "inactivity") << std::endl;
		#endif
	}

	// Requests door lock/unlock
	void requestDoorLock (bool lock)
	{
		#ifdef OUTPUT_EVENTS_TO_CONSOLE
			std::cout << "[MobileApp]     The owner has requested that the door be " << (lock ? "locked" : "unlocked") << std::endl;
		#endif

		if (lock)
			mobileAppEventHandler (MobileAppEvent::REQUEST_DOOR_LOCK);
		else
			mobileAppEventHandler (MobileAppEvent::REQUEST_DOOR_UNLOCK);
	}

}

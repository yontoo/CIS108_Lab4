/* (c) 2019 Reno Technology Academy, Multnomah University */
/*
  Course:		CIS108 - Introduction to Software Development
  Author:		Kory William Herzinger
  Description:	Lab Assignment #4 / Exercise #1
				Security System
  Purpose:		Implements the smart video doorbell IoT device
*/

#include "VideoDoorbell.h"

#define OUTPUT_EVENTS_TO_CONSOLE

#ifdef OUTPUT_EVENTS_TO_CONSOLE
	#include <iostream>
#endif

namespace VideoDoorbell
{

	VideoDoorbellEventHandler videoDoorbellEventHandler = nullptr;

	bool someoneAtTheDoor = false;
	std::string personAtTheDoor = UNKNOWN_PERSON;

	// Initializes the doorbell
	void initializeDoorbell (VideoDoorbellEventHandler event_handler)
	{
		videoDoorbellEventHandler = event_handler;
	}

	// Rings the doorbell
	void ringDoorbell ()
	{
		#ifdef OUTPUT_EVENTS_TO_CONSOLE
			std::cout << "[VideoDoorbell] The doorbell was rung" << std::endl;
		#endif

		videoDoorbellEventHandler (VideoDoorbellEvent::DOORBELL_RING, "");
	}

	// Indicate video activity (face recognition)
	void videoActivity (std::string personAtDoor)
	{
		if (!someoneAtTheDoor)
		{
			someoneAtTheDoor = true;
			personAtTheDoor = personAtDoor;

			#ifdef OUTPUT_EVENTS_TO_CONSOLE
				if (personAtTheDoor == UNKNOWN_PERSON)
					std::cout << "[VideoDoorbell] There is activity at the door" << std::endl;
				else
					std::cout << "[VideoDoorbell] '" << personAtTheDoor << "' is at the door" << std::endl;
			#endif

			videoDoorbellEventHandler (VideoDoorbellEvent::SOMEONE_AT_THE_DOOR, personAtDoor);
		}
	}

	// Indicate video inactivity
	void videoInactivity ()
	{
		if (someoneAtTheDoor)
		{
			someoneAtTheDoor = false;
			personAtTheDoor = UNKNOWN_PERSON;

			#ifdef OUTPUT_EVENTS_TO_CONSOLE
				std::cout << "[VideoDoorbell] No one is at the door anymore" << std::endl;
			#endif

			videoDoorbellEventHandler (VideoDoorbellEvent::NO_ONE_AT_THE_DOOR, "");
		}
	}

}

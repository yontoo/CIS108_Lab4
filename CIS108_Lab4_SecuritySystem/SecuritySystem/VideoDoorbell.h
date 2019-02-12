/* (c) 2019 Reno Technology Academy, Multnomah University */
/*
  Course:		CIS108 - Introduction to Software Development
  Author:		Kory William Herzinger
  Description:	Lab Assignment #4 / Exercise #1
				Security System
  Purpose:		Declares the smart video doorbell IoT device
*/

#pragma once

#include <functional>
#include <string>

namespace VideoDoorbell
{
	const std::string UNKNOWN_PERSON = "Unknown";

	// List of video doorbell events
	enum class VideoDoorbellEvent : int
	{
		DOORBELL_RING,				// event that indicates the doorbell was rung
		SOMEONE_AT_THE_DOOR,		// event that indicates someone is at the door
		NO_ONE_AT_THE_DOOR			// event that indicates that someone has left the door
	};

	// The video doorbell event handler
	typedef std::function<void (VideoDoorbellEvent, std::string)> VideoDoorbellEventHandler;

	// Initializes the doorbell
	void initializeDoorbell (VideoDoorbellEventHandler event_handler);

	// Rings the doorbell
	void ringDoorbell ();

	// Indicate video activity (face recognition)
	void videoActivity (std::string personAtDoor);

	// Indicate video inactivity
	void videoInactivity ();
}

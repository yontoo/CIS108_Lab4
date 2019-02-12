/* (c) 2019 Reno Technology Academy, Multnomah University */
/*
  Course:		CIS108 - Introduction to Software Development
  Author:		Kory William Herzinger
  Description:	Lab Assignment #4 / Exercise #1
				Security System
  Purpose:		Implements the window sensor IoT device
*/

#include "WindowSensor.h"

#define OUTPUT_EVENTS_TO_CONSOLE

#ifdef OUTPUT_EVENTS_TO_CONSOLE
	#include <iostream>
#endif

namespace WindowSensor
{

	WindowSensorEventHandler windowSensorEventHandler = nullptr;

	bool windowState = false;

	// Initializes the window sensor
	void initializeWindowSensor (WindowSensorEventHandler event_handler)
	{
		windowSensorEventHandler = event_handler;
	}

	// The window sensor was updated (opened/closed)
	void windowSensorUpdate (bool opened)
	{
		if (windowState != opened)
		{
			windowState = opened;

			#ifdef OUTPUT_EVENTS_TO_CONSOLE
				std::cout << "[WindowSensor] The window was " << (windowState ? "opened" : "closed") << std::endl;
			#endif

			if (windowState)
				windowSensorEventHandler (WindowSensorEvent::WINDOW_OPENED);
			else
				windowSensorEventHandler (WindowSensorEvent::WINDOW_CLOSED);
		}
	}

}

/* (c) 2019 Reno Technology Academy, Multnomah University */
/*
  Course:		CIS108 - Introduction to Software Development
  Author:		Kory William Herzinger
  Description:	Lab Assignment #4 / Exercise #1
				Security System
  Purpose:		Declares the window sensor IoT device
*/

#pragma once

#include <functional>

namespace WindowSensor
{
	// List of window sensor events
	enum class WindowSensorEvent : int
	{
		WINDOW_OPENED,				// event that indicates the window was opened
		WINDOW_CLOSED				// event that indicates the window was closed
	};

	// The window sensor event handler
	typedef std::function<void (WindowSensorEvent)> WindowSensorEventHandler;

	// Initializes the window sensor
	void initializeWindowSensor (WindowSensorEventHandler event_handler);

	// The window sensor was updated (opened/closed)
	void windowSensorUpdate (bool opened);
}

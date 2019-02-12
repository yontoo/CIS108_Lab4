/* (c) 2019 Reno Technology Academy, Multnomah University */
/*
  Course:		CIS108 - Introduction to Software Development
  Author:		Kory William Herzinger
  Description:	Lab Assignment #4 / Exercise #1
				Security System
  Purpose:		Pre-defined sequence of sensor input to test the security system
*/

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// DO NOT MODIFY THIS FILE
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include "SensorInputTest.h"

#include <vector>

using namespace SensorInputTest;

std::vector<SensorInput*> sensorInputs = {

	// An unknown person rings the doorbell
	(SensorInput*)(new SensorInput (SensorInput::SensorType::NEW_TEST, 0, "An unknown person rings the doorbell")),
	(SensorInput*)(new VideoDoorbellInput (2000, VideoDoorbellInput::VideoDoorbellInputType::VIDEO_ACTIVITY, "Unknown")),
	(SensorInput*)(new VideoDoorbellInput (2000, VideoDoorbellInput::VideoDoorbellInputType::RING_DOORBELL)),
	(SensorInput*)(new VideoDoorbellInput (5000, VideoDoorbellInput::VideoDoorbellInputType::VIDEO_INACTIVITY)),

	// A person with automatic allowed access comes and leaves
	(SensorInput*)(new SensorInput (SensorInput::SensorType::NEW_TEST, 0, "A person with automatic allowed access comes and leaves")),
	(SensorInput*)(new VideoDoorbellInput (5000, VideoDoorbellInput::VideoDoorbellInputType::VIDEO_ACTIVITY, "Jeff Bezos")),
	(SensorInput*)(new DoorLockSensorInput (2000, DoorLockSensorInput::DoorLockSensorInputType::SENSOR_UPDATE, true)),
	(SensorInput*)(new DoorLockSensorInput (1000, DoorLockSensorInput::DoorLockSensorInputType::SENSOR_UPDATE, false)),
	(SensorInput*)(new VideoDoorbellInput (1000, VideoDoorbellInput::VideoDoorbellInputType::VIDEO_INACTIVITY)),
	(SensorInput*)(new DoorLockSensorInput (5000, DoorLockSensorInput::DoorLockSensorInputType::SENSOR_UPDATE, true)),
	(SensorInput*)(new DoorLockSensorInput (1000, DoorLockSensorInput::DoorLockSensorInputType::SENSOR_UPDATE, false)),

	// A person who is not automatically allowed access rings the doorbell, but the homeowner grants access
	(SensorInput*)(new SensorInput (SensorInput::SensorType::NEW_TEST, 0, "A person rings the doorbell and the homeowner grants access")),
	(SensorInput*)(new VideoDoorbellInput (5000, VideoDoorbellInput::VideoDoorbellInputType::VIDEO_ACTIVITY, "Bill Gates")),
	(SensorInput*)(new VideoDoorbellInput (2000, VideoDoorbellInput::VideoDoorbellInputType::RING_DOORBELL)),
	(SensorInput*)(new MobileAppInput (2000, MobileAppInput::MobileAppInputType::REQUEST_DOOR_LOCK, false)),
	(SensorInput*)(new DoorLockSensorInput (2000, DoorLockSensorInput::DoorLockSensorInputType::SENSOR_UPDATE, true)),
	(SensorInput*)(new DoorLockSensorInput (1000, DoorLockSensorInput::DoorLockSensorInputType::SENSOR_UPDATE, false)),
	(SensorInput*)(new VideoDoorbellInput (1000, VideoDoorbellInput::VideoDoorbellInputType::VIDEO_INACTIVITY)),
	(SensorInput*)(new DoorLockSensorInput (5000, DoorLockSensorInput::DoorLockSensorInputType::SENSOR_UPDATE, true)),
	(SensorInput*)(new DoorLockSensorInput (1000, DoorLockSensorInput::DoorLockSensorInputType::SENSOR_UPDATE, false)),

	// An unknown person rings the doorbell and tries to enter an invalid pin code
	(SensorInput*)(new SensorInput (SensorInput::SensorType::NEW_TEST, 0, "An unknown person rings the doorbell and tries to enter an invalid pin code")),
	(SensorInput*)(new VideoDoorbellInput (5000, VideoDoorbellInput::VideoDoorbellInputType::VIDEO_ACTIVITY, "Unknown")),
	(SensorInput*)(new DoorLockSensorInput (2000, DoorLockSensorInput::DoorLockSensorInputType::ENTER_PINCODE, std::string ("1234"))),
	
	// The unknown person forces open the door
	(SensorInput*)(new SensorInput (SensorInput::SensorType::NEW_TEST, 0, "The unknown person forces open the door")),
	(SensorInput*)(new DoorLockSensorInput (2000, DoorLockSensorInput::DoorLockSensorInputType::SENSOR_UPDATE, true)),
};
uint32_t currentInput = 0;

// Retrieves the next sensor input to test
SensorInput* SensorInputTest::getNextSensorInput ()
{
	SensorInput* next_sensor_input = nullptr;

	if (currentInput < sensorInputs.size ())
	{
		next_sensor_input = sensorInputs[currentInput];
		currentInput++;
	}

	return next_sensor_input;
}

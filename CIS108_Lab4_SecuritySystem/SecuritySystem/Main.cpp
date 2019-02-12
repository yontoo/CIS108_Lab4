/* (c) 2019 Reno Technology Academy, Multnomah University */
/*
  Course:		CIS108 - Introduction to Software Development
  Author:		Kory William Herzinger
  Description:	Lab Assignment #4 / Exercise #1
				Security System
  Purpose:		Application entry point and main loop
*/

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// DO NOT MODIFY THIS FILE
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Provides a sequence of sensor input to test the system
#include "SensorInputTest.h"

// The security system
#include "DoorLock.h"
#include "MobileAppInterface.h"
#include "SecurityAlarm.h"
#include "SecuritySystem.h"
#include "VideoDoorbell.h"
#include "WindowSensor.h"

#include <chrono>
#include <iostream>
#include <thread>

int main ()
{
	// initialize the smart home security system
	SecuritySystem::initializeSecuritySystem ();

	auto sensor_input = SensorInputTest::getNextSensorInput ();
	while (sensor_input != nullptr)
	{
		// wait for the specified time
		std::this_thread::sleep_for (std::chrono::milliseconds (sensor_input->delay ()));

		switch (sensor_input->sensorType ())
		{
			case SensorInputTest::SensorInput::SensorType::NEW_TEST:
			{
				std::cout << std::endl << "{" << sensor_input->testDescription () << "}" << std::endl;
			} break;

			case SensorInputTest::SensorInput::SensorType::DOOR_LOCK:
			{
				auto door_input = (SensorInputTest::DoorLockSensorInput*)sensor_input;
				switch (door_input->inputType ())
				{
					case SensorInputTest::DoorLockSensorInput::DoorLockSensorInputType::SENSOR_UPDATE:
					{
						DoorLock::doorSensorUpdate (door_input->sensorUpdate ());
					} break;

					case SensorInputTest::DoorLockSensorInput::DoorLockSensorInputType::ENTER_PINCODE:
					{
						DoorLock::enterPinCode (door_input->pinCode ());
					} break;
				}
			} break;

			case SensorInputTest::SensorInput::SensorType::MOBILE_APP:
			{
				auto mobile_app_input = (SensorInputTest::MobileAppInput*)sensor_input;
				switch (mobile_app_input->inputType ())
				{
					case SensorInputTest::MobileAppInput::MobileAppInputType::REQUEST_DOOR_LOCK:
					{
						MobileAppInterface::requestDoorLock (mobile_app_input->lockDoor ());
					} break;
				}
			} break;

			case SensorInputTest::SensorInput::SensorType::SECURITY_ALARM:
			{
				auto security_alarm_input = (SensorInputTest::SecurityAlarmInput*)sensor_input;
				switch (security_alarm_input->inputType ())
				{
					case SensorInputTest::SecurityAlarmInput::SecurityAlarmInputType::ENABLE_ALARM:
					{
						if (security_alarm_input->enableAlarm ())
							SecurityAlarm::enableAlarm ();
						else
							SecurityAlarm::disableAlarm ();
					} break;

					case SensorInputTest::SecurityAlarmInput::SecurityAlarmInputType::RESET_ALARM:
					{
						SecurityAlarm::resetAlarm ();
					} break;
				}
			} break;

			case SensorInputTest::SensorInput::SensorType::VIDEO_DOORBELL:
			{
				auto video_doorbell_input = (SensorInputTest::VideoDoorbellInput*)sensor_input;
				switch (video_doorbell_input->inputType ())
				{
					case SensorInputTest::VideoDoorbellInput::VideoDoorbellInputType::RING_DOORBELL:
					{
						VideoDoorbell::ringDoorbell ();
					} break;

					case SensorInputTest::VideoDoorbellInput::VideoDoorbellInputType::VIDEO_ACTIVITY:
					{
						VideoDoorbell::videoActivity (video_doorbell_input->personAtDoor ());
					} break;

					case SensorInputTest::VideoDoorbellInput::VideoDoorbellInputType::VIDEO_INACTIVITY:
					{
						VideoDoorbell::videoInactivity ();
					} break;
				}
			} break;

			case SensorInputTest::SensorInput::SensorType::WINDOW_SENSOR:
			{
				auto window_input = (SensorInputTest::WindowSensorInput*)sensor_input;
				switch (window_input->inputType ())
				{
					case SensorInputTest::WindowSensorInput::WindowSensorInputType::SENSOR_UPDATE:
					{
						WindowSensor::windowSensorUpdate (window_input->sensorUpdate ());
					} break;
				}
			} break;
		}

		sensor_input = SensorInputTest::getNextSensorInput ();
	}

	system ("pause");

	return 0;
}

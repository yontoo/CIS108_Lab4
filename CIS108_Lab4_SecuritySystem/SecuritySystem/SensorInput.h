/* (c) 2019 Reno Technology Academy, Multnomah University */
/*
  Course:		CIS108 - Introduction to Software Development
  Author:		Kory William Herzinger
  Description:	Lab Assignment #4 / Exercise #1
				Security System
  Purpose:		Declares the  sensor input types for the sensor input test
*/

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// DO NOT MODIFY THIS FILE
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#pragma once

#include <string>

namespace SensorInputTest
{
	class SensorInput
	{
	public:
		enum class SensorType : int
		{
			NEW_TEST,					// denotes a new test
			DOOR_LOCK,					// the door lock sensor
			MOBILE_APP,					// the mobile application
			SECURITY_ALARM,				// the security alarm
			VIDEO_DOORBELL,				// the video doorbell
			WINDOW_SENSOR				// the window sensor
		};

	public:
		SensorInput (SensorInput::SensorType _sensor_type, uint32_t _delay_ms)
			: sensor_type (_sensor_type), delay_ms (_delay_ms)
		{}
		SensorInput (SensorInput::SensorType _sensor_type, uint32_t _delay_ms, std::string _test_description)
			: sensor_type (_sensor_type), delay_ms (_delay_ms), test_description (_test_description)
		{}

		SensorType sensorType () { return sensor_type; }
		uint32_t delay () { return delay_ms; }
		std::string testDescription () { return test_description; }

	protected:
		SensorType sensor_type;
		uint32_t delay_ms = 0;
		std::string test_description;
	};

	class DoorLockSensorInput : SensorInput
	{
	public:
		enum class DoorLockSensorInputType : int
		{
			SENSOR_UPDATE,				// the door sensor was updated
			ENTER_PINCODE				// a pin code as entered
		};

	public:
		DoorLockSensorInput (uint32_t _delay_ms, DoorLockSensorInputType _input_type, bool _sensor_update)
			: SensorInput (SensorInput::SensorType::DOOR_LOCK, _delay_ms),
			  input_type (_input_type), sensor_update (_sensor_update)
		{}
		DoorLockSensorInput (uint32_t _delay_ms, DoorLockSensorInputType _input_type, std::string _pin_code)
			: SensorInput (SensorInput::SensorType::DOOR_LOCK, _delay_ms),
			  input_type (_input_type), pin_code (_pin_code)
		{
			pin_code = _pin_code;
		}

		DoorLockSensorInputType inputType () { return input_type; }
		bool sensorUpdate () { return sensor_update; }
		std::string pinCode () { return pin_code; }

	protected:
		DoorLockSensorInputType input_type;
		bool sensor_update = false;
		std::string pin_code;
	};

	class MobileAppInput : SensorInput
	{
	public:
		enum class MobileAppInputType : int
		{
			REQUEST_DOOR_LOCK			// the user has requested the door be locked/unlocked
		};

	public:
		MobileAppInput (uint32_t _delay_ms, MobileAppInputType _input_type, bool _lock_door)
			: SensorInput (SensorInput::SensorType::MOBILE_APP, _delay_ms),
			  input_type (_input_type), lock_door (_lock_door)
		{}

		MobileAppInputType inputType () { return input_type; }
		bool lockDoor () { return lock_door; }

	protected:
		MobileAppInputType input_type;
		bool lock_door = false;
	};

	class SecurityAlarmInput : SensorInput
	{
	public:
		enum class SecurityAlarmInputType : int
		{
			ENABLE_ALARM,				// the user has enabled/disabled the alarm
			RESET_ALARM					// the user has reset the alarm
		};

	public:
		SecurityAlarmInput (uint32_t _delay_ms, SecurityAlarmInputType _input_type)
			: SensorInput (SensorInput::SensorType::SECURITY_ALARM, _delay_ms),
			  input_type (_input_type)
		{}
		SecurityAlarmInput (uint32_t _delay_ms, SecurityAlarmInputType _input_type, bool _enable_alarm)
			: SensorInput (SensorInput::SensorType::SECURITY_ALARM, _delay_ms),
			  input_type (_input_type), enable_alarm (_enable_alarm)
		{}

		SecurityAlarmInputType inputType () { return input_type; }
		bool enableAlarm () { return enable_alarm; }

	protected:
		SecurityAlarmInputType input_type;
		bool enable_alarm = false;
	};

	class VideoDoorbellInput : SensorInput
	{
	public:
		enum class VideoDoorbellInputType : int
		{
			RING_DOORBELL,				// someone has rung the doorbell
			VIDEO_ACTIVITY,				// someone is at the door
			VIDEO_INACTIVITY			// no one is at the door
		};

	public:
		VideoDoorbellInput (uint32_t _delay_ms, VideoDoorbellInputType _input_type)
			: SensorInput (SensorInput::SensorType::VIDEO_DOORBELL, _delay_ms),
			  input_type (_input_type)
		{}
		VideoDoorbellInput (uint32_t _delay_ms, VideoDoorbellInputType _input_type, std::string _person_at_door)
			: SensorInput (SensorInput::SensorType::VIDEO_DOORBELL, _delay_ms),
			  input_type (_input_type), person_at_door (_person_at_door)
		{}

		VideoDoorbellInputType inputType () { return input_type; }
		std::string personAtDoor () { return person_at_door; }

	protected:
		VideoDoorbellInputType input_type;
		std::string person_at_door;
	};

	class WindowSensorInput : SensorInput
	{
	public:
		enum class WindowSensorInputType : int
		{
			SENSOR_UPDATE,				// the window sensor was updated
		};

	public:
		WindowSensorInput (uint32_t _delay_ms, WindowSensorInputType _input_type, bool _sensor_update)
			: SensorInput (SensorInput::SensorType::WINDOW_SENSOR, _delay_ms),
			input_type (_input_type), sensor_update (_sensor_update)
		{}

		WindowSensorInputType inputType () { return input_type; }
		bool sensorUpdate () { return sensor_update; }

	protected:
		WindowSensorInputType input_type;
		bool sensor_update;
	};
}

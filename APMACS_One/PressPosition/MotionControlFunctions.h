#pragma once
#include "PressPositionInterfaces.h"
class MotionControlFunctions
{
public:
	MotionControlFunctions::MotionControlFunctions(DriveInputsStruct* inputs, DriveOutputsStruct* outputs, DriveCommandsStruct* driveCommands, bool* isRunning, SHORT* velocityInRPM, ULONG encoderResolution);
	~MotionControlFunctions();
	void ProcessDriveCommands();
	void ProcessMotionCommands();
	void DetermineDriveStatus();
	bool EnableDrive();
	void DisableDrive();
	void ResetDrive();

	DriveInputsStruct* Inputs;
	DriveOutputsStruct* Outputs;
	DriveCommandsStruct* DriveCommands;
	bool* IsRunning;
	DriveStatusEnum DriveStatus = DriveStatusEnum::UnknownState;
	SHORT* VelocityInRPM;
	ULONG EncoderResolution;
};
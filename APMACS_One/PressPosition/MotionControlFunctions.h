#pragma once
#include "PressPositionInterfaces.h"
class MotionControlFunctions
{
public:
	MotionControlFunctions(DriveInputsStruct& inputs, DriveOutputsStruct& outputs, DriveCommandsStruct& driveCommands, MotionCommandsStruct& motionCommands, SHORT& velocityInRPM, ULONG encoderResolution);
	~MotionControlFunctions();
	void ProcessDriveCommands();
	void ProcessMotionCommands();
	void DetermineDriveStatus();
	bool EnableDrive();
	void DisableDrive();
	void ResetDrive();

	DriveInputsStruct Inputs;
	DriveOutputsStruct Outputs;
	DriveCommandsStruct DriveCommands;
	MotionCommandsStruct MotionCommands;
	DriveStatusEnum DriveStatus = DriveStatusEnum::UnknownState;
	SHORT VelocityInRPM;
	ULONG EncoderResolution;

};
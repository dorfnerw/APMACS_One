#include "TcPch.h"
#pragma hdrstop

#include "MotionControlFunctions.h"
#include "TcMath.h"

MotionControlFunctions::MotionControlFunctions(DriveInputsStruct& inputs, DriveOutputsStruct& outputs, DriveCommandsStruct& driveCommands, MotionCommandsStruct& motionCommands, SHORT& velocityInRPM, ULONG encoderResolution)
{
	Inputs = inputs;
	Outputs = outputs;
	DriveCommands = driveCommands;
	MotionCommands = motionCommands;
	EncoderResolution = encoderResolution;
	VelocityInRPM = velocityInRPM;
}

MotionControlFunctions::~MotionControlFunctions()
{
}

void MotionControlFunctions::ProcessDriveCommands()
{
	//Handle the drive commands
	DetermineDriveStatus();
	if (DriveCommands.Enable)
	{
		DriveCommands.Enable = EnableDrive();
	}
	if (DriveCommands.Disable)
	{
		DriveCommands.Disable = false;
		DisableDrive();
	}
	if (DriveCommands.Reset)
	{
		DriveCommands.Reset = false;
		ResetDrive();
	}
	return;
}

void MotionControlFunctions::ProcessMotionCommands()
{
	Outputs.ModesOfOperation = 3; //profile velocity mode
	Outputs.ProfileAcceleration = 700; //equates to 400 RPM/s
	if (MotionCommands.Start)
	{
		MotionCommands.Start = false;
		Outputs.TargetVelocity = VelocityInRPM / 60.0 * EncoderResolution;
	}
	if (MotionCommands.Stop)
	{
		MotionCommands.Stop = false;
		Outputs.TargetVelocity = 0;
	}
	return;
}

void MotionControlFunctions::DetermineDriveStatus()
{
	if ((Inputs.StatusWord & 0x006F) == 0x0027)
	{
		//state 4 Operational
		DriveStatus = DriveStatusEnum::Operational;
	}
	if ((Inputs.StatusWord & 0x006F) == 0x0023)
	{
		//state 3 Switched on
		DriveStatus = DriveStatusEnum::SwitchedOn;
	}
	if ((Inputs.StatusWord & 0x006F) == 0x0021)
	{
		//state 2 Ready to switch on
		DriveStatus = DriveStatusEnum::ReadyToSwitchOn;
	}
	if ((Inputs.StatusWord & 0x004F) == 0x0040)
	{
		//state 1 Switch on disabled
		DriveStatus = DriveStatusEnum::SwitchOnDisabled;
	}
	if ((Inputs.StatusWord & 0x000F) == 0x000F)
	{
		//state 13 Fault reaction active
		DriveStatus = DriveStatusEnum::FaultReactionActive;
	}
	if ((Inputs.StatusWord & 0x000F) == 0x0008)
	{
		//state 14 Fault
		DriveStatus = DriveStatusEnum::Fault;
	}
	else
	{
		//unknown state
		DriveStatus = DriveStatusEnum::UnknownState;
	}
	return;
}

bool MotionControlFunctions::EnableDrive()
{
	if (DriveStatus == DriveStatusEnum::Operational)
	{
		//state 4 Operational
		Outputs.ControlWord = 0xF;
		return false;
	}
	if (DriveStatus == DriveStatusEnum::SwitchedOn)
	{
		//state 3 Switched on
		Outputs.ControlWord = 0xF;
	}
	if (DriveStatus == DriveStatusEnum::ReadyToSwitchOn)
	{
		//state 2 Ready to switch on
		Outputs.ControlWord = 0x7;
	}
	if (DriveStatus == DriveStatusEnum::SwitchOnDisabled)
	{
		//state 1 Switch on disabled
		Outputs.ControlWord = 0x6;
	}
	return true;
}

void MotionControlFunctions::DisableDrive()
{
	Outputs.ControlWord = 0x0;
	Outputs.TargetPosition = Inputs.PositionActualValue;
	Outputs.TargetVelocity = 0;
	DriveStatus = DriveStatusEnum::Disabled;
	return;
}

void MotionControlFunctions::ResetDrive()
{
	Outputs.ControlWord = 0x80;
	Outputs.TargetPosition = Inputs.PositionActualValue;
	Outputs.TargetVelocity = 0;
	DriveStatus = DriveStatusEnum::Reset;
	return;
}
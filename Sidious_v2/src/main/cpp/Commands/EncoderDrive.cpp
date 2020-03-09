// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Commands/EncoderDrive.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

EncoderDrive::EncoderDrive(double left, double right): frc::Command() {
m_left = left;
m_right = right;
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drivetrain.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void EncoderDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void EncoderDrive::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool EncoderDrive::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void EncoderDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EncoderDrive::Interrupted() {

}
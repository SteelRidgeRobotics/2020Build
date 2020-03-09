// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Subsystems/Drivetrain.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/DriveWithJoystick.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Drivetrain::Drivetrain() : frc::Subsystem("Drivetrain") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
frontLeft.reset(new WPI_TalonSRX(0));


backLeft.reset(new WPI_TalonSRX(1));


frontRight.reset(new WPI_TalonSRX(2));


backRight.reset(new WPI_TalonSRX(3));



    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

leftside = std::make_shared<frc::SpeedControllerGroup>(*frontLeft, *backLeft);
AddChild("leftside", leftside);

rightside = std::make_shared<frc::SpeedControllerGroup>(*frontRight, *backRight);
AddChild("rightside", rightside);

limelightdrive.reset(new frc::DifferentialDrive(*leftside, *rightside));
AddChild("Limelight Drive", limelightdrive);
limelightdrive->SetSafetyEnabled(false);

frontLeft->SetSensorPhase(false); //Reverse sensors
frontRight->SetSensorPhase(false); //Reverse sensors

backRight->SetInverted(true); //Reverse motor and slave for right side of robot.
frontRight->SetInverted(true);

frontLeft->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, PIDIdx, kTimeoutMs);
frontRight->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, PIDIdx, kTimeoutMs);

initMotors();
//Set Neutral modes to brake


/*
backLeft->Follow(*frontLeft); //left back to follow left front
backRight->Follow(*frontRight); //right back to follow right front

frontLeft->SetNeutralMode(NeutralMode::Brake);
backLeft->SetNeutralMode(NeutralMode::Brake);
frontRight->SetNeutralMode(NeutralMode::Brake);
backRight->SetNeutralMode(NeutralMode::Brake);
*/

//Configure PID_F for Closed Loop

frontLeft->Config_kF(kSlotIDx_Cloop, kF_CloopLeft, kTimeoutMs);
frontLeft->Config_kP(kSlotIDx_Cloop, kP_CloopLeft, kTimeoutMs);
frontLeft->Config_kI(kSlotIDx_Cloop, kI_CloopLeft, kTimeoutMs);
frontLeft->Config_kD(kSlotIDx_Cloop, kD_CloopLeft, kTimeoutMs);

frontRight->Config_kF(kSlotIDx_Cloop, kF_CloopRight, kTimeoutMs);
frontRight->Config_kP(kSlotIDx_Cloop, kP_CloopRight, kTimeoutMs);
frontRight->Config_kI(kSlotIDx_Cloop, kI_CloopRight, kTimeoutMs);
frontRight->Config_kD(kSlotIDx_Cloop, kD_CloopRight, kTimeoutMs);

}

void Drivetrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new DriveWithJoystick());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Drivetrain::Periodic() {
    // Put code here to be run every loop

}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drivetrain::userDrive(std::shared_ptr<frc::Joystick>mainController){
	double left_y = - 1 * mainController->GetRawAxis(1);
	double right_y = - 1 * mainController->GetRawAxis(5);
  	bool l_bump = mainController->GetRawButton(5);


	if( fabs(left_y) < 0.1)   left_y = 0;
	if( fabs(right_y) < 0.1)   right_y = 0;

	if(l_bump)
	{
		left_y = slowFactor * left_y;
		right_y = slowFactor * right_y;
	}

	frontLeft->Set(ControlMode::PercentOutput, left_y);
	frontRight->Set(ControlMode::PercentOutput, right_y);
}

void Drivetrain::autoDrive(double move, double turn){
limelightdrive->ArcadeDrive(move, turn, false);
}

void Drivetrain::setInvert(bool left_bool, bool right_bool){
	frontRight->SetInverted(right_bool);
	backRight->SetInverted(right_bool);

	frontLeft->SetInverted(left_bool);
	backLeft->SetInverted(left_bool);
}

void Drivetrain::stopMotors(){
	frontRight->Set(ControlMode::PercentOutput, 0.0);
	frontLeft->Set(ControlMode::PercentOutput, 0.0);
}

void Drivetrain::initMotors(){
	backLeft->Follow(*frontLeft);
	backRight->Follow(*frontRight);

	frontLeft->SetNeutralMode(NeutralMode::Brake);
	backLeft->SetNeutralMode(NeutralMode::Brake);
	frontRight->SetNeutralMode(NeutralMode::Brake);
	backRight->SetNeutralMode(NeutralMode::Brake);
}

void Drivetrain::encoderPosition(double left, double right){
    l_pos = left;
	r_pos = right;	

	frontLeft->Set(ControlMode::Position, ftToRotations(left));
	frontRight->Set(ControlMode::Position, ftToRotations(right));

    sendDataToSD();
}


void Drivetrain::encoderDone() {
    frontLeft->Set(ControlMode::PercentOutput, 0.0);
	frontRight->Set(ControlMode::PercentOutput, 0.0);
    
    l_pos = 0.0;
	r_pos = 0.0;
}

void Drivetrain::encoderReset() {
	frontLeft->SetSelectedSensorPosition(0, 0, kTimeoutMs);
	frontRight->SetSelectedSensorPosition(0, 0, kTimeoutMs);

}

bool Drivetrain::isMove() {
	if ((frontLeft->GetSelectedSensorPosition() < (l_pos + .1) && frontLeft->GetSelectedSensorPosition() > (l_pos - .1)) && frontRight->GetSelectedSensorPosition(0) < (r_pos + .1) && frontRight->GetSelectedSensorPosition(0) > (r_pos - .1)) {
			return true;
		} else {
			return false;
		}
}

double Drivetrain::ftToRotations(double ft){
	return ft*kGearRatio*kSensorUnitsPerRotation*(1/kWheelDiam)*(1/M_PI);
}

double Drivetrain::rotationsToFt(double rotations){
	return rotations/kGearRatio/kSensorUnitsPerRotation/(1/kWheelDiam)/(1/M_PI);
}

void Drivetrain::sendDataToSD(){
	double l_data = frontLeft->GetSelectedSensorPosition();
	double r_data = frontRight->GetSelectedSensorPosition();
	l_data = rotationsToFt(l_data);
	r_data = rotationsToFt(r_data);
	frc::SmartDashboard::PutNumber("L_Position", l_data);
	frc::SmartDashboard::PutNumber("R_Position", r_data);
}

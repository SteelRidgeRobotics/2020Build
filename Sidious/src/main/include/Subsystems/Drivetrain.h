// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#pragma once

#include "frc/commands/Subsystem.h"
#include "frc/Joystick.h"
#include "frc/SpeedControllerGroup.h"
#include "frc/drive/DifferentialDrive.h"
#include "frc/smartdashboard/SmartDashboard.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "ctre/Phoenix.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

/**
 *
 *
 * @author ExampleAuthor
 */
class Drivetrain: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
std::shared_ptr<WPI_TalonSRX> frontLeft;
std::shared_ptr<WPI_TalonSRX> backLeft;
std::shared_ptr<WPI_TalonSRX> frontRight;
std::shared_ptr<WPI_TalonSRX> backRight;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

std::shared_ptr<frc::SpeedControllerGroup> leftside;
std::shared_ptr<frc::SpeedControllerGroup> rightside;

std::shared_ptr<frc::DifferentialDrive> limelightdrive;




public:
Drivetrain();
	void InitDefaultCommand() override;
	void Periodic() override;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	void userDrive(std::shared_ptr<frc::Joystick>mainController); //Method to drive robot using joystick input.

	void autoDrive(double move, double turn); //Method to drive robot using lime light.

	void setInvert(bool left_bool, bool right_bool);

	void stopMotors();

	void initMotors();

	void encoderPosition(double left, double right); //Method to move robot a distance using encoders.

	void encoderDone();

	void encoderReset();

	bool isMove(); //Determines whether the robot is moving.

	double ftToRotations(double ft); //Method to convert from feet to rotations. The talons only work in rotations.

	double rotationsToFt(double rotations);

	static const int kTimeoutMs = 10; //Talon timeout default

	static const int kSensorUnitsPerRotation = 360; // E4T encoder

	static constexpr double kGearRatio = 10.71; //Mini box motor gear ratio

	static constexpr double kWheelDiam = (6.0/12); //Diameter of the wheel in feet

	static const int kSlotIDx_Cloop = 0; //Talon controller slot for CL

	//static const int kSlotIDx_Motion = 1; //Talon controller slot 1 for MP

	//static const int kProfilePeriodMs = 50; //Motion Profile period between points

	//Closed Loop PID_F constants

	static constexpr double kF_CloopLeft = 0.0; //Feed forward gain

	static constexpr double kP_CloopLeft = 1.0; //Proportional gain. This is just a start and needs tuning.

	static constexpr double kI_CloopLeft = 0.0; //Integral gain

	static constexpr double kD_CloopLeft = 0.00; // Derivative gain

	static constexpr double kF_CloopRight = 0.0; //Feed forward gain

	static constexpr double kP_CloopRight = 1.0; //Proportional gain. This is just a start and needs tuning.

	static constexpr double kI_CloopRight = 0.0; //Integral gain

	static constexpr double kD_CloopRight = 0.0; // Derivative gain

	/*
	static constexpr double kF_CloopLeft = 0.0; //Feed forward gain

	static constexpr double kP_CloopLeft = 1.72; //Proportional gain. This is just a start and needs tuning.

	static constexpr double kI_CloopLeft = 0.0; //Integral gain

	static constexpr double kD_CloopLeft = 0.783; // Derivative gain

	static constexpr double kF_CloopRight = 0.0; //Feed forward gain

	static constexpr double kP_CloopRight = 1.72; //Proportional gain. This is just a start and needs tuning.

	static constexpr double kI_CloopRight = 0.0; //Integral gain

	static constexpr double kD_CloopRight = 0.783; // Derivative gain
	

	//Motion Profile PID_F constants

	static constexpr double kF_MotionLeft = 0.25; //Feed forward gain. This is just a start and needs tuning.

	static constexpr double kP_MotionLeft = 1.0; //Proportional gain. This is just a start and needs tuning.

	static constexpr double kI_MotionLeft = 0.0; //Integral gain

	static constexpr double kD_MotionLeft = 0.0; // Derivative gain

	static constexpr double kF_MotionRight = 0.25; //Feed forward gain. This is just a start and needs tuning.

	static constexpr double kP_MotionRight = 1.0; //Proportional gain. This is just a start and needs tuning.

	static constexpr double kI_MotionRight = 0.0; //Integral gain

	static constexpr double kD_MotionRight = 0.0; // Derivative gain

	*/

	double l_pos;
	double r_pos;

	double slowFactor = 0.6;


};

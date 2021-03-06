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

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "ctre/Phoenix.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

/**
 *
 *
 * @author ExampleAuthor
 */
class Shooter: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
std::shared_ptr<WPI_TalonFX> shooterFalcon;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	double kF = 0.06;

	double kP = 0.08;

	double kI = 0.0;

	double kD = 0.0;

	int kTimeout = 30;

	double sensorTPR = 2048.0;

	double kGearRatio = 0.75;

public:
Shooter();
	void InitDefaultCommand() override;
	void Periodic() override;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

	double velocityBeforeInitLint = 5000.0;

	double velocityAtInitLine = 6000.0;

	double velocityAtTrenchRun = 6000.0;

	double velocityAtRendezvousPoint = 6000.0;

	//^^ not needed? these numbers are defined in the command "SetVelocityWithLimelight"

	void runShooterAtVelocity(double velocity);

	double velocityToTicks(double velocity);

	double ticksToVelocity(double ticks);

	void sendDataToSD();



};


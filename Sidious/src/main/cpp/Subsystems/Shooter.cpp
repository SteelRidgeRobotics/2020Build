// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Subsystems/Shooter.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Shooter::Shooter() : frc::Subsystem("Shooter") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
leftFalcon.reset(new WPI_TalonFX(5));


rightFalcon.reset(new WPI_TalonFX(6));



    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void Shooter::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    leftFalcon->ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);

    rightFalcon->Follow(*leftFalcon);

    leftFalcon->SetNeutralMode(NeutralMode::Brake);
    rightFalcon->SetNeutralMode(NeutralMode::Brake);

    rightFalcon->SetInverted(true);

    leftFalcon->Config_kF(kF, 0, kTimeout);
    leftFalcon->Config_kP(kP, 0, kTimeout);
    leftFalcon->Config_kI(kI, 0, kTimeout);
    leftFalcon->Config_kD(kD, 0, kTimeout);
    

}

void Shooter::Periodic() {
    // Put code here to be run every loop

}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Shooter::AutoShooter(double velocity)
{

    leftFalcon->Set(ControlMode::Velocity, VelocityToTicks(velocity));

}

void Shooter::StopShooter()
{

    leftFalcon->Set(ControlMode::PercentOutput, 0.0);

}

double Shooter::VelocityToTicks(double velocity)
{

   velocity = velocity * 2048 * kGearRatio;

    return velocity;

}


/*
void Shooter::manualShooter(std::shared_ptr<frc::Joystick>systemsController)
{

    double Rtrigger = systemsController->GetRawAxis(3);
    double Ltrigger = systemsController->GetRawAxis(2);

    if (fabs(Rtrigger) < 0.1)
    {
        Rtrigger = 0.0;
    }

    if (fabs(Ltrigger) < 0.1)
    {
        Ltrigger = 0.0;
    }

    if(Rtrigger > 0.1 && !(Ltrigger > 0.1))

    {
        leftFalcon->Set(ControlMode::PercentOutput, Rtrigger);
    }

    if(Ltrigger > 0.1 && !(Rtrigger > 0.1))
    {
        leftFalcon->Set(ControlMode::PercentOutput, (Ltrigger * -1));
    }

}

*/

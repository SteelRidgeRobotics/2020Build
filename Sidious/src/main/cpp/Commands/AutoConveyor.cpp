// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Commands/AutoConveyor.h"



// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutoConveyor::AutoConveyor(): frc::Command() {
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::conveyor.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void AutoConveyor::Initialize() {

    timer = new frc::Timer();

    timer->Start();

}

// Called repeatedly when this Command is scheduled to run
void AutoConveyor::Execute() {

    bool sensorState = Robot::conveyor->SensorReading();

    double initTime = timer->Get();

    frc::SmartDashboard::PutNumber("timer", timer->Get());

    frc::SmartDashboard::PutNumber("counter", Robot::conveyor->GetCounter());

    double pistonWaitTime = 0.3;

    double movingPowercellTime = 0.25;

    double targetTime = initTime + pistonWaitTime + movingPowercellTime; //500 needs to be tuned timer is in SECONDS

    //I'm assuming this is in milliseconds... 
    //anyway, this is the time it takes to move the powercell up enough to clear 
    //it from the conveyor opening, in order to feed in another. my thoght is that
    //maybe we don't even need a piston, as the powercells feed very slowly into 
    //the conveyor

    if(Robot::conveyor->GetCounter() < 2){

        if(Robot::conveyor->SensorReading() == true){
            Robot::conveyor->ControlSolenoid("forward");

            while(timer->Get() < initTime + pistonWaitTime){
                frc::SmartDashboard::PutBoolean("waiting", true);
            }
                //maybe we need to have this be an if loop... I dont know how freezing the thread will effect the robot.

            initTime = timer->Get();

            frc::SmartDashboard::PutBoolean("waiting", false);

            while(timer->Get() < targetTime){   //maybe we need to have this be an if loop... I dont know how freezing the thread will effect the robot.
                Robot::conveyor->ConveyorRun(0.5);
                frc::SmartDashboard::PutBoolean("waiting", true);

            }
                Robot::conveyor->AddToCounter(1);

                frc::SmartDashboard::PutBoolean("waiting", false);
                Robot::conveyor->ConveyorRun(0.0);
            }

        else{
            Robot::conveyor->ControlSolenoid("reverse");
            Robot::conveyor->ConveyorRun(0.0);
        }
    }
}

// Make this return true when this Command no longer needs to run execute()
bool AutoConveyor::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void AutoConveyor::End() {

    Robot::conveyor->ConveyorRun(0.0);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoConveyor::Interrupted() {

    End();

}

// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Subsystems/Conveyor.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutoConveyor.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Conveyor::Conveyor() : frc::Subsystem("Conveyor") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
conveyorSensor.reset(new frc::DigitalInput(1));
AddChild("ConveyorSensor", conveyorSensor);

conveyorSolenoid.reset(new frc::DoubleSolenoid(0, 6, 1));
AddChild("ConveyorSolenoid", conveyorSolenoid);

conveyorMotor.reset(new WPI_VictorSPX(4));


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void Conveyor::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new AutoConveyor());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Conveyor::Periodic() {
    // Put code here to be run every loop

SensorReadingToSmartDashboard();

}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.

bool Conveyor::SensorReading(){
    if(conveyorSensor->Get()){
        return true;
    }
    else{
        return false;
    }
}

void Conveyor::ControlSolenoid(std::string dir){
    if(dir == "forward"){
        conveyorSolenoid->Set(frc::DoubleSolenoid::kForward);
    }
    else if(dir == "reverse"){
        conveyorSolenoid->Set(frc::DoubleSolenoid::kReverse);
    }
}

void Conveyor::ControlMotor(double speed){
    conveyorMotor->Set(speed);
}

void Conveyor::SensorReadingToSmartDashboard(){
    frc::SmartDashboard::PutBoolean("Conveyor Sensor State", SensorReading());
}

void Conveyor::AddToCounter(int input){

counter = counter + input;

}

void Conveyor::SetCounter(int input){

counter = input;

}

int Conveyor::GetCounter(){
    return counter;
}

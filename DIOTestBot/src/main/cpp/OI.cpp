// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "frc/smartdashboard/SmartDashboard.h"
#include "Commands/AutoConveyor.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/ConveyorOveride.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
sysController.reset(new frc::Joystick(0));

x.reset(new frc::JoystickButton(sysController.get(), 3));
x->WhileHeld(new ConveyorOveride());

    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("ConveyorOveride", new ConveyorOveride());
    frc::SmartDashboard::PutData("AutoConveyor", new AutoConveyor());
    frc::SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> OI::getSysController() {
   return sysController;
}

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

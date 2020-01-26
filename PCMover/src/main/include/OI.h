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

#include "frc/Joystick.h"
#include "frc/buttons/JoystickButton.h"

class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS











std::shared_ptr<frc::Joystick> mainController;
std::shared_ptr<frc::JoystickButton> rBump;
std::shared_ptr<frc::JoystickButton> lBump;
std::shared_ptr<frc::JoystickButton> y;
std::shared_ptr<frc::JoystickButton> x;
std::shared_ptr<frc::JoystickButton> b;
std::shared_ptr<frc::JoystickButton> a;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	OI();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

std::shared_ptr<frc::Joystick> getMainController();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
};


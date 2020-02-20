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

























std::shared_ptr<frc::Joystick> systemsController;
std::shared_ptr<frc::JoystickButton> sc_X;
std::shared_ptr<frc::JoystickButton> sc_Y;
std::shared_ptr<frc::JoystickButton> sc_Rbump;
std::shared_ptr<frc::JoystickButton> sc_Lbump;
std::shared_ptr<frc::JoystickButton> sc_B;
std::shared_ptr<frc::JoystickButton> sc_A;
std::shared_ptr<frc::Joystick> driveController;
std::shared_ptr<frc::JoystickButton> mc_Rbump;
std::shared_ptr<frc::JoystickButton> mc_B;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	OI();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

std::shared_ptr<frc::Joystick> getDriveController();
std::shared_ptr<frc::Joystick> getSystemsController();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
};


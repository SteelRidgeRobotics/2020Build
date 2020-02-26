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
#include "Commands/AutonomousCommandGroup.h"
#include "Commands/ClimberPistonIn.h"
#include "Commands/ClimberPistonOut.h"
#include "Commands/ClimberWinchRun.h"
#include "Commands/ConveyorPistonIn.h"
#include "Commands/ConveyorPistonOut.h"
#include "Commands/ConveyorRest.h"
#include "Commands/ConveyorRun.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/EncoderDrive.h"
#include "Commands/IntakeDown.h"
#include "Commands/IntakeDownSequence.h"
#include "Commands/IntakeRun.h"
#include "Commands/IntakeUp.h"
#include "Commands/IntakeUpSequence.h"
#include "Commands/LimelightOff.h"
#include "Commands/LimelightTrack.h"
#include "Commands/RunShooter.h"
#include "Commands/ShootSequence.h"
#include "Commands/SpinnerControlPiston.h"
#include "Commands/SpinnerPositionControl.h"
#include "Commands/SpinnerPositionControlSequence.h"
#include "Commands/SpinnerRest.h"
#include "Commands/SpinnerRotationControl.h"
#include "Commands/SpinnerRotationControlSequence.h"
#include "Commands/SpinnerStop.h"
#include "Commands/TimedConveyor.h"
#include "Commands/TimedConveyorPistonIn.h"
#include "Commands/TimedShooter.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
systemsController.reset(new frc::Joystick(1));

sc_X.reset(new frc::JoystickButton(systemsController.get(), 3));
sc_X->WhenPressed(new SpinnerRotationControl());
sc_Y.reset(new frc::JoystickButton(systemsController.get(), 4));
sc_Y->WhenPressed(new SpinnerPositionControl());
sc_Rbump.reset(new frc::JoystickButton(systemsController.get(), 6));
sc_Rbump->WhileHeld(new ClimberWinchRun(0.33));
sc_B.reset(new frc::JoystickButton(systemsController.get(), 2));
sc_B->WhileHeld(new RunShooter(250.00));
sc_A.reset(new frc::JoystickButton(systemsController.get(), 1));
sc_A->WhileHeld(new IntakeDownSequence());
driveController.reset(new frc::Joystick(0));

mc_Rbump.reset(new frc::JoystickButton(driveController.get(), 6));
mc_Rbump->WhileHeld(new LimelightTrack());
mc_B.reset(new frc::JoystickButton(driveController.get(), 2));
mc_B->WhenPressed(new EncoderDrive(0, 0));

    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("SpinnerControlPiston: in", new SpinnerControlPiston("in"));
    frc::SmartDashboard::PutData("SpinnerControlPiston: out", new SpinnerControlPiston("out"));
    frc::SmartDashboard::PutData("LimelightOff", new LimelightOff());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

sc_Lbump.reset(new frc::JoystickButton(systemsController.get(), 5));

sc_Lbump->ToggleWhenPressed(new ClimberPistonOut());
sc_Lbump->ToggleWhenPressed(new ClimberPistonIn());

//toggle when pressed to save controller space. Works like last years.
//remember that the sc_Lbump is NOT needed in robotbuilder
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> OI::getDriveController() {
   return driveController;
}

std::shared_ptr<frc::Joystick> OI::getSystemsController() {
   return systemsController;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

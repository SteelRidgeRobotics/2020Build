// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Subsystems/Spinner.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Spinner::Spinner() : frc::Subsystem("Spinner") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
spinnerMotor.reset(new frc::VictorSP(0));
AddChild("SpinnerMotor", std::static_pointer_cast<frc::VictorSP>(spinnerMotor));

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    m_colorMatcher.AddColorMatch(kBlueTarget);
    m_colorMatcher.AddColorMatch(kGreenTarget);
    m_colorMatcher.AddColorMatch(kRedTarget);
    m_colorMatcher.AddColorMatch(kYellowTarget);
    m_colorMatcher.AddColorMatch(kWhiteTarget);


}

void Spinner::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Spinner::Periodic() {
    // Put code here to be run every loop


}



// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Spinner::DetectColor()
{

  int counter = 0; //create a counter to count how many rotations of the spinner we have made
  bool same = true; //used for checking if the first color we see is the same as we see now
  double confidence = 0.0; // used only for setting up the color matcher 
  const frc::Color initialColor = m_colorMatcher.MatchClosestColor(m_colorSensor.GetColor(), confidence);

  while(counter < rotations)
  {

    std::string colorString;
    frc::Color matchedColor = m_colorMatcher.MatchClosestColor(m_colorSensor.GetColor(), confidence);

    if (matchedColor == kBlueTarget){
      colorString = "Blue";
    } else if (matchedColor == kRedTarget) {
      colorString = "Red";
    } else if (matchedColor == kGreenTarget) {
      colorString = "Green";
    } else if (matchedColor == kYellowTarget) {
      colorString = "Yellow";
    }else if(matchedColor == kWhiteTarget) {
      colorString = "White";
    } else {
      colorString = "Unknown";
    }

    //pervious section used for sending data to the smart dashboard. used for troubleshooting, may remove later

    spinnerMotor->Set(motorSpeed);

    frc::SmartDashboard::PutNumber("Counter", counter);
    frc::SmartDashboard::PutString("Detected Color", colorString);

    if(matchedColor == initialColor)
    {
          
      if(!same) //if we are on the initial color and the last color we have seen was not the initial. 
      {
        counter += increment;
        same = true; //saying the color we are reading now is the same as the one we just read previously. 
      }
      else
      {
        same = true;
      }
        
    }

    if(!(matchedColor == initialColor))
    {
      same = false;
    }

  }

spinnerMotor->Set(0.00);
frc::SmartDashboard::PutNumber("Counter", counter);



}
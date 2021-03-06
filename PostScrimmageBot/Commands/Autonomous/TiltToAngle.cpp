#include "TiltToAngle.h"

TiltToAngle::TiltToAngle(float inputAngle) {
	// Use requires() here to declare subsystem dependencies
	Requires(turhop);
	desiredAngle = inputAngle;
}

// Called just before this Command runs the first time
void TiltToAngle::Initialize() {
	SmartDashboard::PutNumber("Tilt Angle", turhop->GetTiltAngle());
}

// Called repeatedly when this Command is scheduled to run
void TiltToAngle::Execute() {

	if(turhop->GetTiltAngle() > desiredAngle)
			{turhop->AltitudeControl(-0.85);}
		else if(turhop->GetTiltAngle() < desiredAngle)
			{turhop->AltitudeControl(0.85);}
	
	SmartDashboard::PutNumber("Tilt Angle", turhop->GetTiltAngle());
	SmartDashboard::PutNumber("Potentiometer", turhop->GetPotAngle());
}

// Make this return true when this Command no longer needs to run execute()
bool TiltToAngle::IsFinished() {
	//return ((turhop->GetTiltAngle() > desiredAngle - 0.65) && (turhop->GetTiltAngle() < desiredAngle + 0.65));
	return ((turhop->GetPotAngle() > desiredAngle - 0.1) && (turhop->GetPotAngle() < desiredAngle + 0.1));
}

// Called once after isFinished returns true
void TiltToAngle::End() {
	turhop->AltitudeControl(0.0);
	SmartDashboard::PutNumber("Tilt Angle", turhop->GetTiltAngle());
	SmartDashboard::PutNumber("Potentiometer", turhop->GetPotAngle());
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TiltToAngle::Interrupted() {
	turhop->AltitudeControl(0.0);
	SmartDashboard::PutNumber("Tilt Angle", turhop->GetTiltAngle());
	SmartDashboard::PutNumber("Potentiometer", turhop->GetPotAngle());
}

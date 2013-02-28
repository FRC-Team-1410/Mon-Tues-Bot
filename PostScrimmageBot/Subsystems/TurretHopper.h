#ifndef TURRETHOPPER_H
#define TURRETHOPPER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author zeitgeist
 */
class TurretHopper: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Jaguar *altitude;
	Jaguar *hopRotat;
	DoubleSolenoid *feeder;
	Servo *hopFeed1;
	Servo *hopFeed2;
	
	bool hopLoadOn;
	
	Compressor *comp;
	
	ADXL345_I2C *accel;
public:
	TurretHopper();
	void InitDefaultCommand();
	void AltitudeControl(double speed);
	void FeederToggle();
	void HopFeedToggle();
	double GetTiltAngle();
};

#endif

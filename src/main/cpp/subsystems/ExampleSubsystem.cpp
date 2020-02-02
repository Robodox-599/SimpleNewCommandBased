/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ExampleSubsystem.h"
#include "frc/smartdashboard/SmartDashboard.h"

ExampleSubsystem::ExampleSubsystem() : frontLeftMotor(4), rearLeftMotor(5), frontRightMotor(0), rearRightMotor(1) {
  // Implementation of subsystem constructor goes here.
    frontLeftMotor.SetInverted(true);
    rearLeftMotor.SetInverted(true);
    frontRightMotor.SetInverted(false);
    rearRightMotor.SetInverted(false);
}

void ExampleSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void ExampleSubsystem::powerDrive(double x, double y)
{
    double l;
    double r;
    if (y > 0.2)
    {
        y = (y - 0.2  ) * 1 / .8;
    }
    else if (y < -0.2)
    {
        y = (y + 0.2) * 1 / .8;
    }
    else
    {
        y = 0;
    }

    if (x > 0.2)
    {
        x = (x - 0.2) * 1 / .8;
    }
    else if (x < -0.2)
    {
        x = (x + 0.2) * 1 / .8;
    }
    else
    {
        x = 0;
    }

    l = -y - x;
    r = -y + x;

    frontLeftMotor.Set(ControlMode::PercentOutput, r);
    rearLeftMotor.Set(ControlMode::PercentOutput, r);
    frontRightMotor.Set(ControlMode::PercentOutput, l);
    rearRightMotor.Set(ControlMode::PercentOutput, l);

    frc::SmartDashboard::PutNumber("x drive", x);
    frc::SmartDashboard::PutNumber("y drive", y);
    frc::SmartDashboard::PutNumber("left drive", l);
    frc::SmartDashboard::PutNumber("right drive", r);    
}

void ExampleSubsystem::autoDrive(double power)
{
    frontLeftMotor.Set(ControlMode::PercentOutput, power);
    rearLeftMotor.Set(ControlMode::PercentOutput, power);
    frontRightMotor.Set(ControlMode::PercentOutput, power);
    rearRightMotor.Set(ControlMode::PercentOutput, power);
}
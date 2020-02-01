/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ExampleAutoCommand.h"

ExampleAutoCommand::ExampleAutoCommand(ExampleSubsystem* subsystem, std::function<double()> power) : m_subsystem{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void ExampleAutoCommand::Initialize() 
{
  m_subsystem->autoDrive(0.5);
}

// Called repeatedly when this Command is scheduled to run
void ExampleAutoCommand::Execute() {}

// Called once the command ends or is interrupted.
void ExampleAutoCommand::End(bool interrupted) {m_subsystem->autoDrive(0);}

// Returns true when the command should end.
bool ExampleAutoCommand::IsFinished() { return false; }
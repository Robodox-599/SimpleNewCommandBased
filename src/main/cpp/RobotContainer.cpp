/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "commands/ExampleCommand.h"
#include "frc2/command/button/JoystickButton.h"

#include "commands/ExampleAutoCommand.h"
#include "frc2/command/ParallelRaceGroup.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem, [=] {return 0.5;}) {
  // Initialize all of your commands and subsystems here
  m_subsystem.SetDefaultCommand(ExampleCommand(&m_subsystem, [this] {return xbox.GetRawAxis(1);},[this] {return xbox.GetRawAxis(4);}));
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::JoystickButton xboxA{&xbox, 1};
  frc2::JoystickButton xboxB{&xbox, 2};
  xboxA.WhenPressed(ExampleAutoCommand(&m_subsystem, [=] {return 0.5;}).WithTimeout(1.0_s));
  xboxB.WhenPressed(ExampleAutoCommand(&m_subsystem, [=] {return 0.5;}).WithTimeout(1.0_s));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}

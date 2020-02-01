/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ExampleCommand.h"

ExampleCommand::ExampleCommand(ExampleSubsystem* subsystem, std::function<double()> forward, std::function<double()> rotation)
    : m_subsystem{subsystem}, m_forward{forward}, m_rotation{rotation}
    {
        AddRequirements({subsystem});
    }

void ExampleCommand::Execute() {
  m_subsystem->powerDrive(m_forward(), m_rotation());
}
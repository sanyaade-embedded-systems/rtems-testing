/*
 *  $Id$
 */

/*! @file Target_powerpc.cc
 *  @brief Target_powerpc Implementation
 *
 *  This file contains the implementation of the base class for 
 *  functions supporting target unique functionallity.
 */
#include "Target_powerpc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

namespace Target {

  Target_powerpc::Target_powerpc( std::string targetName ):
    TargetBase( targetName )
  {
  }

  Target_powerpc::~Target_powerpc()
  {
  }

  bool Target_powerpc::isNopLine(
    const char* const line,
    int&              size
  )
  {
    if (!strcmp( &line[strlen(line)-3], "nop")) {
      size = 4; 
      return true;
    }

    return false;
  }

  bool Target_powerpc::isBranch(
      const char* const instruction
  )
  {
    fprintf( stderr, "DETERMINE BRANCH INSTRUCTIONS FOR THIS ARCHITECTURE! -- fix me\n" );
    exit( -1 );    
  }

  TargetBase *Target_powerpc_Constructor(
    std::string          targetName
  )
  {
    return new Target_powerpc( targetName );
  }

}
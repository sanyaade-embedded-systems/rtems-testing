/*
 *  $Id$
 */

/*! @file SymbolTable.cc
 *  @brief SymbolTable Implementation
 *
 *  This file contains ...
 */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SymbolTable.h"
#include "app_common.h"

namespace Coverage {

  SymbolTable::SymbolTable()
  {
  }

  SymbolTable::~SymbolTable()
  {
  }

  void SymbolTable::addSymbol(
    const std::string& symbol,
    const uint32_t     start,
    const uint32_t     length
  )
  {
    uint32_t       end = 0;
    symbol_entry_t entry;
    symbolInfo     symbolData;

    // Add an entry to the address map.
    end = start + length - 1;
    entry.low = start;
    entry.high = end;
    entry.symbol = symbol;
    contents[ end ] = entry;

    // Add an entry to the symbol information map.
    symbolData.startingAddress = start;
    symbolData.length = length;
    info[ symbol ] = symbolData;
  }

  SymbolTable::symbolInfo* SymbolTable::getInfo(
    const std::string& symbol
  )
  {
    info_t::iterator it = info.find( symbol );

    if (it == info.end())
      return NULL;
    else
      return (&(it->second));
  }

  uint32_t SymbolTable::getLength(
    const std::string& symbol
  )
  {
    info_t::iterator it = info.find( symbol );

    if (it == info.end())
      return 0;
    else
      return ((*it).second.length);
  }

  std::string SymbolTable::getSymbol(
    uint32_t address
  )
  {
    contents_t::iterator it;

    // Ensure that the symbol table is not empty.
    if ( contents.size() == 0 )
      return "";

    // Find the first entry whose end address is greater
    // than the specified address.
    it = contents.lower_bound( address );

    // If an entry was found and its low address is less than or
    // equal to the specified address, then return the symbol.
    if ((it != contents.end()) && ((it->second).low <= address ))
      return (it->second).symbol;

    return "";
  }

}

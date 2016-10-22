#pragma once

#include "Symbol.h"
#include <map>

namespace minkey {

  class Object {
      std::map<const std::string, Symbol> symbols;

  public:
      std::map<const std::string, Symbol> &get_symbols() {
        return symbols;
      }
  };
}
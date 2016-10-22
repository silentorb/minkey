#pragma once

#include "Object.h"

namespace minkey {

#define PARENT_SCOPE "_parent_scope"

  class Instance {
      Object *scope;

  public:
      Object *get_scope() const {
        return scope;
      }

      void set_scope(Object *current_scope) {
        Instance::scope = current_scope;
      }

      Object *resolve_object(const std::string &symbol_name) const;
      static Object *resolve_object(Object *object, const std::string &symbol_name);
  };
}
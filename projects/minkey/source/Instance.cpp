#include "Instance.h"

using namespace std;

namespace minkey {
  Object *Instance::resolve_object(const std::string &symbol_name) const {
    return resolve_object(scope, symbol_name);
  }

  Object *Instance::resolve_object(Object *object, const std::string &symbol_name) {
    auto &symbols = object->get_symbols();
    if (symbols.count(symbol_name))
      return symbols[symbol_name].data.object_data.object;

    if (!symbols.count(PARENT_SCOPE))
      throw runtime_error("Scope does not have _parent_scope");

    return resolve_object(symbols[PARENT_SCOPE].data.object_data.object, symbol_name);
  }
}
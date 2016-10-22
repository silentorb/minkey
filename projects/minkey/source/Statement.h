#pragma once

#include <string>

namespace minkey {

  enum class Statement_Type {
      If,
      set,
      set_scope
  };

  struct If_Data {
      std::string source_name;
  };

  struct Set_Data {
      std::string source_name;
      std::string target_name;
  };

  struct Set_Scope_Data {
      std::string source_name;
  };

  union Statement_Data {
      If_Data if_data;
      Set_Data set_data;
      Set_Scope_Data set_scope_data;
  };

  struct Statement {
      Statement_Type type;
      Statement *next = nullptr;
      Statement_Data data;
  };
}
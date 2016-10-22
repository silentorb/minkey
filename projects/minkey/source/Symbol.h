#pragma once

namespace minkey {

  enum class Symbol_Type {
      object
  };

  class Object;

  struct Object_Data {
      Object *object;
  };

  union Symbol_Data {
      Object_Data object_data;
  };

  struct Symbol {
      Symbol_Type type;
      Symbol_Data data;
  };
}
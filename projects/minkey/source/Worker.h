#pragma once

#include "Statement.h"
#include "Instance.h"

namespace minkey {

  class Worker {
      Instance &instance;
      Statement *next_statement = nullptr;

      void process_if(const Statement &statement);
      void process_set(const Statement &statement);
      void process_set_scope(const Statement &statement);

  public:
      Worker(Instance &instance);
      void execute_statement(const Statement &statement);
      void execute_statement();

  };
}
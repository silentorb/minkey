#include "Worker.h"

namespace minkey {

  Worker::Worker(Instance &instance) :
    instance(instance) {}

  void Worker::execute_statement(const Statement &statement) {
    switch (statement.type) {
      case Statement_Type::If: {
        process_if(statement);
        break;
      }

      case Statement_Type::set: {
        process_set(statement);
        break;
      }

      case Statement_Type::set_scope: {
        process_set_scope(statement);
        break;
      }
    }
    next_statement = statement.next;
  }

  void Worker::execute_statement() {
    execute_statement(*next_statement);
  }

  void Worker::process_if(const Statement &statement) {

  }

  void Worker::process_set(const Statement &statement) {

  }

  void Worker::process_set_scope(const Statement &statement) {
    auto object = instance.resolve_object(statement.data.set_scope_data.source_name);
    instance.set_scope(object);
  }
}
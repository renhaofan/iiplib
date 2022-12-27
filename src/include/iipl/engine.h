//
// Created by steve on 9/17/22.
//
/**
 * @todo multiple thread
 */

#ifndef IIPL_INCLUDE_IIPL_ENGINE_H_
#define IIPL_INCLUDE_IIPL_ENGINE_H_
#include "log.h"
#include "log_timer.h"

namespace IIPL {

void init(int pargc, char*** argv);
void shutdown();

class Engine {
 public:
  static Engine* instance_ptr;
  static Engine* instance(void) {
    if (instance_ptr == nullptr) instance_ptr = new Engine();
    if (instance_ptr == nullptr) {
      LOG_FATAL("Failed to allocate Engine pointer memory");
      throw "Failed to allocate Engine pointer memory";
    }
    return instance_ptr;
  }

  void print_test() {
    std::cout << "print_test() NICE" << "\n";
  }

  Engine();
  ~Engine();

 private:
  Log log_;
};
}
#endif //IIPL_INCLUDE_IIPL_ENGINE_H_
//
// Created by steve on 9/17/22.
//
/**
 * @todo multiple thread
 */

#ifndef IIPLIB_INCLUDE_IIPL_ENGINE_H_
#define IIPLIB_INCLUDE_IIPL_ENGINE_H_
#include "log.h"
#include "log_timer.h"

namespace iiplib {

extern void init(int* pargc, char*** argv);
extern void shutdown();

class IIPLEngine {
 public:
  static IIPLEngine* instance_ptr;
  static IIPLEngine* instance(void) {
    if (instance_ptr == nullptr) instance_ptr = new IIPLEngine();
    if (instance_ptr == nullptr) {
      LOG_FATAL("Failed to allocate IIPLEngine pointer memory");
      throw "Failed to allocate IIPLEngine pointer memory";
    }
    return instance_ptr;
  }

  void print_test() {
    std::cout << "print_test() NICE" << "\n";
  }

  IIPLEngine();
  ~IIPLEngine();

 private:
  Log log_;
};
}
#endif //IIPLIB_INCLUDE_IIPL_ENGINE_H_
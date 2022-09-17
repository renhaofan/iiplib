//
// Created by steve on 9/17/22.
//
/**
 * @todo multiple thread
 */

#ifndef IIPLIB_INCLUDE_IIPL_ENGINE_H_
#define IIPLIB_INCLUDE_IIPL_ENGINE_H_
#include "../include/config.h"
#include "../include/log.h"
#include "../include/log_timer.h"

namespace iiplib {

extern void init(int* pargc, char*** argv);
extern void shutdown();

class IIPLEngine {
 public:
  static IIPLEngine* instance_ptr;
  static IIPLEngine* instance(void) {
    if (instance_ptr == nullptr) instance_ptr = new IIPLEngine();
    if (instance_ptr == nullptr) {
#ifdef LOGGING
      LOG_FATAL("Failed to allocate IIPLEngine pointer memory");
#endif
      throw "Failed to allocate IIPLEngine pointer memory";
    }
    return instance_ptr;
  }

  bool set_json(const char* file_name);
  bool set_yaml(const char* file_name);
  void print_test() {
    std::cout << "NICE\n";
  }

  void set_config_mode(iiplib::ConfigMode mode = iiplib::ConfigMode::SINGLE_JSON);

  IIPLEngine();
  ~IIPLEngine();

 private:
  Config config_;
  Log log_;
};
}
#endif //IIPLIB_INCLUDE_IIPL_ENGINE_H_
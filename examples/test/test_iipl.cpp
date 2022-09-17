//
// Created by steve on 9/17/22.
//

#include "../../include/iipl_engine.h"
#include "../../include/log_timer.h"

int main(int argc, char** argv) {
  iiplib::init(&argc, &argv);
  log_tic(test);
  iiplib::IIPLEngine::instance()->print_test();
  log_toc(test);
  iiplib::shutdown();
  return EXIT_SUCCESS;
}

//
// Created by steve on 9/17/22.
//

//#include "../../include/iipl_engine.h"
//#include "../../include/log_timer.h"
#include "../../include/iipl_engine.h"

int main(int argc, char** argv) {

  iiplib::init(&argc, &argv);

//  iiplib::init(&argc, &argv, "config.json",
//               iiplib::ConfigMode::SINGLE_JSON);

//  iiplib::init(&argc, &argv, iiplib::ConfigMode::MODE_NUM);
  log_tic(test);
  iiplib::IIPLEngine::instance()->print_test();
  log_toc(test);
  LOG_INFO("A");
  iiplib::shutdown();
  return EXIT_SUCCESS;
}

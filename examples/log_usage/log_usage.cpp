/*
 * This is a example for IIPL::Log usage, 
*/

#define LOGTOSTD
#include <iipl/log.h>

using IIPL::Log;

int main(int argc, char** argv) {

  // IIPL::Log::instance()->init(argc, &argv);
  Log::instance()->init(argc, &argv);

  log_tic(test);
  log_toc(test);
  LOG_INFO("A");
  LOG_WARNING("A");

  // IIPL::Log::instance()->shutdown();
  Log::instance()->shutdown();

  return 0;
}


// -DLOGTOSTD
#define LOGTOSTD
#include <iipl/engine.h>

int main(int argc, char** argv) {

  iiplib::init(&argc, &argv);

  log_tic(test);
  iiplib::IIPLEngine::instance()->print_test();
  log_toc(test);
  LOG_INFO("A");
  iiplib::shutdown();

  return 0;
}


#define LOGTOSTD 
#include <iipl/log.h>
#include <iipl/IIPLConfig.h>

using IIPL::Log;

int main(int argc, char** argv) {

  std::cout << "IIPL Version "
              << IIPL_VERSION_MAJOR << "." 
              << IIPL_VERSION_MINOR << "." 
              << IIPL_VERSION_PATCH
			  << "\n";

  Log::instance()->init(argc, &argv);

  log_tic(test);
  log_toc(test);
  LOG_INFO("A");
  LOG_WARNING("A");

  Log::instance()->shutdown();

  return 0;
}

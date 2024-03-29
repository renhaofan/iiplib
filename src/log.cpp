//
// Created by steve on 9/16/22.
//
#include <iipl/log.h>

IIPL::Log *IIPL::Log::instance_ptr = nullptr;

void IIPL::Log::init(int pargc, char ***pargv) {
  std::string log_dir = "iipl_log";
  FLAGS_log_dir = "./" + log_dir;
  boost::filesystem::path dir(FLAGS_log_dir);
  boost::filesystem::create_directory(dir);
  google::InitGoogleLogging(*(pargv)[0]);
  std::cout << "Log file located in "
            << "EXECUTABLE_OUTPUT_PATH " << log_dir << "\n";

  if ('y' == logtostd) {
    FLAGS_alsologtostderr = true;
  }

  
  FLAGS_colorlogtostderr = true;  // set log color if termimal supports.
  FLAGS_logbufsecs = 0;           // set log output speed(s)
  // FLAGS_max_log_size = 16;        // set max log file size(MB)
  // FLAGS_stop_logging_if_full_disk = true;  // If disk if full

  LOG(INFO) << "[INFO]     argc: " << pargc;
  LOG(INFO) << "[INFO]     argvs: ";
  for (int i = 0; i < pargc; ++i) {
    LOG(INFO) << "[INFO]     argv[" << i << "]: " << (*(pargv))[i];
  }
}

void IIPL::Log::shutdown() { google::ShutdownGoogleLogging(); }
//
// Created by steve on 9/17/22.
//
#include "iipl_engine.h"

iiplib::IIPLEngine* iiplib::IIPLEngine::instance_ptr = nullptr;

iiplib::IIPLEngine::IIPLEngine() {}
iiplib::IIPLEngine::~IIPLEngine() {}

void iiplib::init(int *pargc, char ***pargv) {
  //! log system init
  std::string log_dir = "iipl_log";
  FLAGS_log_dir = "./" + log_dir;
  boost::filesystem::path dir(FLAGS_log_dir);
  boost::filesystem::create_directory(dir);
  google::InitGoogleLogging(*(pargv)[0]);
  std::cout << "Log file located in "
            << "${EXECUTABLE_OUTPUT_PATH}/" << log_dir << "\n";
  ;
#ifdef LOGTOSTD
  FLAGS_alsologtostderr = true;
#endif
  FLAGS_colorlogtostderr = true;  // set log color if termimal supports.
  FLAGS_logbufsecs = 0;           // set log output speed(s)
  FLAGS_max_log_size = 16;        // set max log file size(MB)
  FLAGS_stop_logging_if_full_disk = true;  // If disk if full

  LOG(INFO) << "[INFO]     argc: " << *pargc;
  for (int i = 0; i < (*pargc); ++i) {
    LOG(INFO) << "[INFO]     argv[" << i << "]: " << (*(pargv))[i];
  }
}

void iiplib::shutdown() { google::ShutdownGoogleLogging(); }
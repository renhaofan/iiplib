//
// Created by steve on 9/17/22.
//
#include "../include/iipl_engine.h"

iiplib::IIPLEngine* iiplib::IIPLEngine::instance_ptr = nullptr;

iiplib::IIPLEngine::IIPLEngine() {}
iiplib::IIPLEngine::~IIPLEngine() {}

void iiplib::IIPLEngine::set_config_mode(iiplib::ConfigMode mode) {
  this->config_.set_mode(mode);
}

void iiplib::init(int *pargc, char ***pargv) {
  std::string log_dir = "iipl_log";
  FLAGS_log_dir = "./" + log_dir;
  boost::filesystem::path dir(FLAGS_log_dir);
  boost::filesystem::create_directory(dir);
  google::InitGoogleLogging(*(pargv)[0]);
  std::cout << "Log file located in "
            << "EXECUTABLE_OUTPUT_PATH" << "\n";
  ;
#ifdef LOGTOSTD
  FLAGS_alsologtostderr = true;
#endif
  FLAGS_colorlogtostderr = true;  // set log color if termimal supports.
  FLAGS_logbufsecs = 0;           // set log output speed(s)
  FLAGS_max_log_size = 16;        // set max log file size(MB)
  FLAGS_stop_logging_if_full_disk = true;  // If disk if full

  LOG(INFO) << "[INFO]     argc :" << *pargc;
  LOG(INFO) << "[INFO]     argvs: ";
  for (int i = 0; i < (*pargc); ++i) {
    LOG(INFO) << "[INFO]     argv[" << i << "]: " << (*(pargv))[i];
  }
}

void iiplib::shutdown() { google::ShutdownGoogleLogging(); }


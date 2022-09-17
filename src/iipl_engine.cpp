//
// Created by steve on 9/17/22.
//
#include "../include/iipl_engine.h"

iiplib::IIPLEngine* iiplib::IIPLEngine::instance_ptr = nullptr;

iiplib::IIPLEngine::IIPLEngine() {}
iiplib::IIPLEngine::~IIPLEngine() {}

void iiplib::init(int *pargc, char ***pargv, const char* file_name, ConfigMode mode) {
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

  LOG(INFO) << "[INFO]     argc :" << *pargc;
  LOG(INFO) << "[INFO]     argvs: ";
  for (int i = 0; i < (*pargc); ++i) {
    LOG(INFO) << "[INFO]     argv[" << i << "]: " << (*(pargv))[i];
  }

  //! config system init
  iiplib::IIPLEngine::instance()->set_config_mode(mode);
  iiplib::IIPLEngine::instance()->config_init(file_name);

}

void iiplib::shutdown() { google::ShutdownGoogleLogging(); }

void iiplib::IIPLEngine::config_init(const char* file_name) {
  this->config_.init(file_name);
}

void iiplib::IIPLEngine::set_config_mode(iiplib::ConfigMode mode) {
  this->config_.set_mode(mode);
}

void iiplib::IIPLEngine::print_config() {
  this->config_.print();
}
//
// Created by steve on 9/16/22.
//
#include <iostream>
using namespace std;

#include <glog/logging.h>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

#define LOGGING

#define LOG_INFO(...) loginfo(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void loginfo(std::string vars, Args&&... values) {
  LOG(INFO) << "[INFO]    " << vars << " = ";
  std::string delim = "";
  (..., (LOG(INFO) << delim << values, delim = ", "));
}

int main(int argc, char** argv) {
#ifdef LOGGING

  string s = "test_log";
  FLAGS_log_dir = "./" + s;
  boost::filesystem::path dir(FLAGS_log_dir);
  boost::filesystem::create_directory(dir);
  google::InitGoogleLogging(argv[0]);
#ifdef LOGTOSTDERR
  FLAGS_alsologtostderr =
      true;  // 设置日志消息除了日志文件之外是否输出到标准输出
#endif
  FLAGS_colorlogtostderr = true;           // Set log color
  FLAGS_logbufsecs = 0;                    // Set log output speed(s)
  FLAGS_max_log_size = 16;                 // Set max log file size MB
  FLAGS_stop_logging_if_full_disk = true;  // If disk is full
  LOG(INFO) << "info new";
  //  LOG(WARNING) << "warning new";
  //  LOG(ERROR) << "error new";
  //  fprintf(stderr, "File %s, Line %d, Function %s(), Unknown dataset\n",
  //          __FILE__, __LINE__, __FUNCTION__);
  //  LOG(FATAL) << "File " << __FILE__ << ", Line " << __LINE__ << ", Function
  //  "
  //             << __FUNCTION__ << "()";
  cout << "cout " << endl;
  int xx = 3;
  int yy = 5;
  int zz = 4;
  LOG_INFO(xx, yy, zz);

  google::ShutdownGoogleLogging();
#endif
  cout << "logging " << endl;
  return 0;
}
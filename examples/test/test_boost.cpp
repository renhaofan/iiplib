//
// Created by steve on 9/16/22.
//
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <iostream>

void test_mkdir(const char* dir_path) {
  boost::filesystem::path dir(dir_path);
  if (boost::filesystem::create_directory(dir)) {
    std::cout << dir_path << " Success"
              << "\n";
  } else {
    std::cout << dir_path << " Failed "
              << "\n";
  }
}

bool is_dir_exists(const std::string& path_name) {
  if (boost::filesystem::exists(path_name) &&
      boost::filesystem::is_directory(path_name)) {
    return true;
  }
  return false;
}

bool create_dir(const std::string& path_name) {
  if (is_dir_exists(path_name)) {
    return true;
  }
  return boost::filesystem::create_directories(path_name);
}

bool is_file_exist(const std::string& file_name) {
  if (boost::filesystem::exists(file_name) &&
      boost::filesystem::is_regular_file(file_name)) {
    return true;
  }
  return false;
}

bool createNewFile(const std::string& file_name) {
  if (is_file_exist(file_name)) {
    return true;
  }
  boost::filesystem::ofstream file(file_name);
  file.close();
  return is_file_exist(file_name);
}

int main() {

  test_mkdir("./llog");
  test_mkdir("/home/steve/llog");
  return 0;
}
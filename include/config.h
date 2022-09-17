//
// Created by steve on 9/16/22.
//
/**
 * @todo multiple json and yaml
 * @todo hybrid
 */

#ifndef IIPLIB__CONFIG_H_
#define IIPLIB__CONFIG_H_

#include "json.hpp"
#include <yaml-cpp/yaml.h>

namespace iiplib {

enum ConfigMode {
  SINGLE_JSON = 0,
  SINGLE_YAML,
  SINGLE_BYBRID,
  MODE_NUM
};

class Config {
 public:
  Config();
  ~Config();
  /**
   * @brief print json details to std
   */
  void print();

  bool json_from_file(const char* file_name, nlohmann::json& json);
  bool json_to_file(const char* file_name, const nlohmann::json& json);

  bool yaml_from_file(const char* file_name, YAML::Node& yaml);
  bool yaml_to_file(const char* file_name, const YAML::Node& yaml);

  void init(const char* file_name);
  void init(const nlohmann::json& json); // TODO
  void init(const YAML::Node& yaml); // TODO
  void init(const YAML::Node& yaml, const nlohmann::json& json); // TODO

  void set_mode(ConfigMode mode);

 private:
  ConfigMode mode_ = ConfigMode::SINGLE_JSON;
  nlohmann::json json_;
  YAML::Node yaml_;
};


}


#endif //IIPLIB__CONFIG_H_

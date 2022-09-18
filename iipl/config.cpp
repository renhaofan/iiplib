//
// Created by steve on 9/17/22.
//

#include "config.h"
#include "log.h"
#include <fstream>

using namespace iiplib;
Config::Config() {}
Config::~Config() {}

void Config::print() {
  switch (mode_) {
    case SINGLE_JSON:
      std::cout << "\n"<< __FILE__ << ", Line " << __LINE__  << ", print config:\n"
                << this->json_ << "\n\n";
      break;
    case SINGLE_YAML:
      std::cout << "\n"<< __FILE__ << ", Line " << __LINE__  << ", print config:\n"
                << this->yaml_ << "\n\n";
      break;
    case SINGLE_BYBRID:
      // TODO
      break;
    default:
      LOG_FATAL_I("Undefined config mode: ", mode_);
      break;
  }
}

bool Config::json_from_file(const char *file_name, nlohmann::json &json) {
  try {
    std::ifstream file(file_name);
    file >> json;
    file.close();
    return true;
  } catch(std::exception const& e){
    LOG_ERROR_I("There was an error: ", e.what());
    return false;
  }
}

// TODO
bool Config::json_to_file(const char *file_name, const nlohmann::json &json) {}

bool Config::yaml_from_file(const char *file_name, YAML::Node& yaml) {
  try{
    yaml = YAML::LoadFile(file_name);
    return true;
  } catch(YAML::BadFile &e) {
    return false;
  }
}

// TODO
bool Config::yaml_to_file(const char *file_name, const YAML::Node& yaml) {}

void Config::init(const char* file_name) {
  LOG_INFO_I("Config mode: ", mode_);
  switch (mode_) {
    case SINGLE_JSON:
      if (!json_from_file(file_name, this->json_)) {
        LOG_ERROR_I("Failed to set json from file: ", file_name);
      }
      break;
    case SINGLE_YAML:
      if (!yaml_from_file(file_name, this->yaml_)) {
        LOG_ERROR_I("Failed to set yaml from file: ", file_name);
      }
      break;
    case SINGLE_BYBRID:
      // TODO
      break;
    default:
      LOG_FATAL_I("Undefined config mode: ", mode_);
      break;
  }
}

void Config::set_mode(ConfigMode mode) {
  mode_ = mode;
}

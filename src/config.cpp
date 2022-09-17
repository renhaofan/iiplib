//
// Created by steve on 9/17/22.
//

#include "../include/config.h"

using namespace iiplib;
Config::Config() {}
Config::~Config() {}

void Config::print() {}

bool Config::json_from_file(const char *file_name, const nlohmann::json &j) {}
bool Config::json_to_file(const char *file_name) {}

bool Config::yaml_from_file(const char *file_name) {}
bool Config::yaml_to_file(const char *file_name, YAML::Node yaml) {}

void Config::init() {}
void Config::set_mode(ConfigMode mode) {}

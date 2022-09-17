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
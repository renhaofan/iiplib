//
// Created by steve on 9/16/22.
//

#ifndef IIPL_LOG_TIMER_H_
#define IIPL_LOG_TIMER_H_

#include <iostream>
#include <chrono>
#include "log.h"

//std::cout << "Timer " << #NAME <<  ": " << (d) * 1000 <<  "ms" << "\n"; \

#define log_tic(NAME) \
  std::chrono::steady_clock::time_point __TIMER##NAME##_START = std::chrono::steady_clock::now();

#define log_toc(NAME) \
  std::chrono::steady_clock::time_point __TIMER##NAME##_END = std::chrono::steady_clock::now(); \
  { \
    auto d = std::chrono::duration_cast<std::chrono::duration<double>>( __TIMER##NAME##_END - __TIMER##NAME##_START ).count(); \
    LOG_INFO_IV("Timer ", #NAME, ": ", (d) * 1000, "ms"); \
  }

#endif //IIPL_LOG_TIMER_H_

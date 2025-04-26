#include "bindings.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

int main() {
  init();
  sleep_for(1000ns);

  set_pwm_freq_hz(50);
  pwm_enable(true);

  int center = 1500;
  int max = 1900;
  int min = 1100;

  PwmChannel pwms[4] = {PwmChannel::Ch1, PwmChannel::Ch2, PwmChannel::Ch3, PwmChannel::Ch4};
  for (auto i: pwms){
    set_pwm_channel_value(i, min);
  }

  for (auto i: pwms){
    set_pwm_channel_value(i, max);
  }

  for (auto i: pwms){
    set_pwm_channel_value(i, center);
  }
}

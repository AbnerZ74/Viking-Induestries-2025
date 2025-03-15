#include "bindings.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  init();

  set_pwm_freq_hz(50);
  pwm_enable(true);

  int center = 1500;
  int max = 1900;
  int min = 1100;

  PwmChannel pwms[3] = {PwmChannel::Ch1, PwmChannel::Ch2, PwmChannel::Ch3};
  for (auto i: pwms){
    set_pwm_channel_value(i, center);
  }
}

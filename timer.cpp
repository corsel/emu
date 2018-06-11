#include "timer.h"

Timer::Timer(void)
: startTime(millis()) {}

unsigned long int Timer::getDelta(void) const
{
  return (millis() - startTime);
}

void Timer::reset(void)
{
  startTime = millis();
}
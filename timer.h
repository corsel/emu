#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <Arduino.h>

class Timer
{
private:
  unsigned long int startTime;
  
public:
  Timer(void);
  unsigned long int getDelta(void) const;
  void reset(void);
};

#endif // TIMER_H_INCLUDED
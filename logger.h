#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include "config.h"
#include "timer.h"
#include <Arduino.h>

typedef unsigned long long int BigInt;

enum LoggerStatusEnum
{
  LoggerStatus_RUNNING, 
  LoggerStatus_FLUSH
};  

class Logger
{
private:
  int period;
  int current;
  BigInt total;
  double average;
  BigInt maximum;
  BigInt maxBuffer;
  unsigned long int deltaTime;
  Timer timer;
  
public:
  Logger(int argPeriod);
  LoggerStatusEnum getSample(void);
  double getAverage(void);
  BigInt getMax(void);
  unsigned long int getDeltaTime(void);
};

#endif // LOGGER_H_INCLUDED
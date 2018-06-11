#include "logger.h"

Logger::Logger(int argPeriod)
: period(argPeriod), current(0), deltaTime(0)
{
  timer.reset();
}

LoggerStatusEnum Logger::getSample(void)
{
  if (current < period)
  {
    int data = analogRead(SENSOR_READ_PIN);
    // totalSquare += data * data;
    total += data; // Test
    if (maximum < data) 
      maximum = data;
    current++;
    return LoggerStatus_RUNNING;
  }
  else
  {
    average = (double)total / (double)period; // Test
    deltaTime = timer.getDelta();
    timer.reset();
    current = 0;
    total = 0;
    maxBuffer = maximum;
    maximum = 0;
    timer.reset();
    return LoggerStatus_FLUSH;
  }
}

double Logger::getAverage(void)
{
  double temp = average;
  average = 0.0;
  return temp;
}

BigInt Logger::getMax(void)
{
  BigInt temp = maxBuffer;
  maxBuffer = 0;
  return temp;
}

unsigned long int Logger::getDeltaTime(void)
{
  unsigned long int temp = deltaTime;
  deltaTime = 0;
  return temp;
}
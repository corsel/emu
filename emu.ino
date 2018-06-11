#include "logger.h"
#include "timer.h"
#include <Arduino.h>

int count;
Logger* logger;

void setup() {
  logger = new Logger(LOGGER_PERIOD);
  count = 0;
  
}

void loop() {
  if (logger->getSample() == LoggerStatus_FLUSH)
  {
    double myAverage = logger->getAverage();
    unsigned long int myMax = logger->getMax();
    unsigned long int timeData = logger->getDeltaTime();
    Serial.println("Average value is \n\t");
    Serial.println(myAverage);
    Serial.println("Maximum value is \n\t");
    Serial.println(myMax);
    Serial.println("Delta time value is \n\t");
    Serial.println(timeData);
  }
}

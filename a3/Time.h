/*
 * Class: Time
 * Purpose: Stores a time and provides operations for comparing and printing that time
 *
 * Data members:
 *   hours   - Hour component
 *   minutes - Minute component
 *
 * Member functions:
 *   Time()          - Initializes the hours and minutes
 *   greaterThan()   - Reports whether this time occurs after another time
 *   print()         - Prints the time in hours and minutes format
 *   convertToMins() - Converts the time into a total number of minutes
 */
#ifndef TIME_H
#define TIME_H

#include "defs.h"

class Time {
public:
  Time(int = 0, int = 0);
  bool greaterThan(Time *);
  void print();

private:
  int hours;
  int minutes;
  int convertToMins();
};

#endif // TIME_H

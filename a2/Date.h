/*
 * Class: Date
 * Purpose: Stores a calendar date and provides operations for setting, comparing, and printing that date
 *
 * Data members:
 *   day_   - Day component
 *   month_ - Month component
 *   year_  - Year component
 *
 * Member functions:
 *   Date()          - Initializes the date
 *   ~Date()         - Cleans up the date
 *   setDate()       - Replaces the stored day, month, and year
 *   print()         - Prints the date in year-month-day format
 *   greaterThan()   - Reports whether this date occurs after another date
 *   equals()        - Reports whether this date is equal to another date
 *   lastDayInMonth()- Returns the last valid day in a month
 *   leapYear()      - Reports whether the given year is a leap year
 */
#ifndef DATE_H
#define DATE_H

class Date {
public:
  Date(int = 0, int = 0, int = 2000);
  ~Date();
  void setDate(int, int, int);
  void print();
  bool greaterThan(const Date *d);
  bool equals(const Date *d);

private:
  int day_;
  int month_;
  int year_;
  int lastDayInMonth(int, int);
  bool leapYear(int);
};

#endif // DATE_H

/*
 * Class: Date
 * Purpose: Stores a calendar date and provides operations for setting, comparing, and printing that date
 *
 * Data members:
 *   year_  - year component
 *   month_ - Month component
 *   day_   - Day component
 *
 * Member functions:
 *   Date()     - Initializes an empty or specified date
 *   setDate()  - Replaces the stored year, month, and day
 *   print()    - Prints the date in year-month-day format
 *   lessThan() - Reports whether this date occurs before another date
 */
#ifndef DATE_H
#define DATE_H

class Date {
  public:
    Date();
    Date(int y, int m, int d);
    void setDate(int y, int m, int d);
    void print();
    bool lessThan(Date& date);

  private:
      int year_;
      int month_;
      int day_;
};

#endif // DATE_H

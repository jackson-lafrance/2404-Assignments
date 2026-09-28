#include "date.h"
#include <iostream>

Date::Date() {
  year = 0;
  month = 0;
  day = 0;
}

Date::Date(int y, int m, int d) {
  year = y;
  month = m;
  day = d;
}

void Date::print() {
  std::cout << day << "-" << month << "-" << year << std::endl;
}

bool Date::lessThan(Date& d) {
  if (d.year == year) {
    if (d.month == month) {
      if (d.day == day) {
        return false;
      }
      
      return d.day > day;
    }

    return d.month > month;
  } 

  return d.year > year;
}

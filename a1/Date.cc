#include "Date.h"
#include <iostream>

Date::Date() {
  year_ = 0;
  month_ = 0;
  day_ = 0;
}

Date::Date(int y, int m, int d) {
  year_ = y;
  month_ = m;
  day_ = d;
}

void Date::setDate(int y, int m, int d) {
  year_ = y;
  month_ = m;
  day_ = d;
}

void Date::print() {
  std::cout << year_ << "-" << month_ << "-" << day_ << std::endl;
}

bool Date::lessThan(Date &d) {
  if (d.year_ == year_) {
    if (d.month_ == month_) {
      if (d.day_ == day_) {
        return false;
      }

      return d.day_ > day_;
    }

    return d.month_ > month_;
  }

  return d.year_ > year_;
}

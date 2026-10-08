#include "Date.h"
#include <iomanip>
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
  std::cout << std::setfill('0') << std::setw(4) << year_ << "-" << std::setw(2)
            << month_ << "-" << std::setw(2) << day_ << std::setfill(' ');
}

bool Date::lessThan(Date &d) {
  if (d.year_ != year_) return year_ < d.year_;
  if (d.month_ != month_) return month_ < d.month_;
  if (d.day_ != day_) return day_ < d.day_;
  return false;
}

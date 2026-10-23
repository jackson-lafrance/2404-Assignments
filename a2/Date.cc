#include <iomanip>
#include <iostream>
using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y) { setDate(d, m, y); }

Date::~Date() {}

void Date::setDate(int d, int m, int y) {
  year_ = ((y > 0) ? y : 0);
  month_ = ((m > 0 && m <= 12) ? m : 0);
  day_ = ((d > 0 && d <= lastDayInMonth(m, y)) ? d : 0);
}

void Date::print() {
  cout << setfill('0') << setw(4) << year_ << "-" << setfill('0') << setw(2)
       << month_ << "-" << setfill('0') << setw(2) << day_ ;
}

int Date::lastDayInMonth(int m, int y) {
  switch (m) {
  case 2:
    if (leapYear(y))
      return 29;
    else
      return 28;
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    return 31;
  default:
    return 30;
  }
}

bool Date::leapYear(int y) {
  if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
    return true;
  else
    return false;
}

bool Date::greaterThan(const Date *d) {
  if (d->year_ != year_)
    return year_ > d->year_;
  if (d->month_ != month_)
    return month_ > d->month_;
  if (d->day_ != day_)
    return day_ > d->day_;
  return false;
}

bool Date::equals(const Date *d) {
  return d->year_ == year_ && d->month_ == month_ && d->day_ == day_;
}

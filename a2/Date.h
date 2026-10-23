#ifndef DATE_H
#define DATE_H

class Date {
public:
  Date(int = 0, int = 0, int = 2000);
  ~Date();
  void setDate(int, int, int);
  void print();

private:
  int day_;
  int month_;
  int year_;
  int lastDayInMonth(int, int);
  bool leapYear(int);
  bool greaterThan(const Date *d);
  bool equals(const Date *d);
};

#endif // DATE_H

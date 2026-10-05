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

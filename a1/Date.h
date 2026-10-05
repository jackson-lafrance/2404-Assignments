#ifndef DATE_H
#define DATE_H

class Date {
  public:
    Date();
    Date(int y, int m, int d);
    void setDate(int y, int m, int d);
    void print();
    bool lessThan(Date&);

  private:
      int year;
      int month;
      int day;
}

#endif // DATE_H

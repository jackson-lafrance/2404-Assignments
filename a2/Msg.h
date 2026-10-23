#ifndef MSG_H
#define MSG_H

#include "Date.h"
#include "Time.h"
#include <string>

class Msg {
public:
  // birth day and time
  Msg(int day = 5, int month = 6, int year = 2007, int hours = 10,
      int mins = 30, const std::string &src = "613 296 4155",
      const std::string &dest = "613 324 8204");
  ~Msg();
  bool greaterThan(Msg *msg);
  void print();

private:
  std::string src_;
  std::string dest_;
  Date *date_;
  Time *time_;
};

#endif // MSG_H

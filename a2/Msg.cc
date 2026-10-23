#include "Msg.h"
#include <iostream>

Msg::Msg(int day, int month, int year, int hours, int mins,
         const std::string &src, const std::string &dest)
    : src_(src), dest_(dest), date_(new Date(day, month, year)),
      time_(new Time(hours, mins)) {}

Msg::~Msg() {
  delete date_;
  delete time_;
}

bool Msg::greaterThan(Msg *msg) const {
  if (date_->equals(msg->date_))
    return time_->greaterThan(msg->time_);
  return date_->greaterThan(msg->date_);
}

void Msg::print() const {
  date_->print();
  std::cout << " @ ";
  time_->print();
  std::cout << ":  From: " << src_;
  std::cout << "  To: " << dest_;
  std::cout << std::endl;
}

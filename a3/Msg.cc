#include "Msg.h"
#include <iostream>

Msg::Msg(int day, int month, int year, int hours, int mins)
    : date_(new Date(day, month, year)), time_(new Time(hours, mins)) {}

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
  std::cout << "  ";
  time_->print();
}

void Msg::printSimple() const {
  date_->print();
  std::cout << " @ ";
  time_->print();
}

std::string Msg::src() const { return ""; }
std::string Msg::dest() const { return ""; };

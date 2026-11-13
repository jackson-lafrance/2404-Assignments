#include "InternMsg.h"

InternMsg::InternMsg(int day, int month, int year, int hours, int mins,
                     Subscriber *src, Subscriber *dest)
    : Msg(day, month, year, hours, mins), src_(src), dest_(dest) {};

void InternMsg::print() const {
  Msg::print();
  std::cout << " I-Msg From: " << src();
  std::cout << " To: " << dest();
  std::cout << std::endl;
}

void InternMsg::printSimple() const {
  Msg::printSimple();
  std::cout << ":  From: " << src();
  std::cout << " To: " << dest();
  std::cout << std::endl;
}

std::string InternMsg::src() const { return src_->phoneNum(); };
std::string InternMsg::dest() const { return dest_->phoneNum(); };

#include "ExternMsg.h"

ExternMsg::ExternMsg(int day, int month, int year, int hours, int mins,
                     const std::string &src, const std::string &dest)
    : Msg(day, month, year, hours, mins), src_(src), dest_(dest) {};

void ExternMsg::print() const {
  Msg::print();
  std::cout << " E-Msg From: " << src();
  std::cout << " To: " << dest();
  std::cout << std::endl;
}

void ExternMsg::printSimple() const {
  Msg::printSimple();
  std::cout << ":  From: " << src();
  std::cout << " To: " << dest();
  std::cout << std::endl;
}

std::string ExternMsg::src() const { return src_; };
std::string ExternMsg::dest() const { return dest_; };

#include "ExternMsg.h"

ExternMsg::ExternMsg(int day, int month, int year, int hours, int mins,
                     const std::string &src, const std::string &dest)
    : Msg(day, month, year, hours, mins), src_(src), dest_(dest) {};

void ExternMsg::print() const {
  // this is not very good and makes you have to change how msg print works
  Msg::print();
  // if you have to call your own getters and setters from within your class's
  // own functions it it usually means your class is too complicated
  // so why do we have to do it? its a bad habit 
  std::cout << ":  From: " << src();
  std::cout << "  To: " << dest();
  std::cout << std::endl;
}

std::string ExternMsg::src() const { return src_; };
std::string ExternMsg::dest() const { return dest_; };

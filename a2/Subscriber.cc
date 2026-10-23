#include "Subscriber.h"
#include <string>
#include <iostream>

Subscriber::Subscriber(const std::string &phoneNum) : phoneNum_(phoneNum) {}

const std::string &Subscriber::phoneNum() const { return phoneNum_; }
MsgArray &Subscriber::inc() { return inc_; }
MsgArray &Subscriber::out() { return out_; }

void Subscriber::addIncoming(Msg *msg) { inc_.add(msg); }

void Subscriber::addOutgoing(Msg *msg) { out_.add(msg); }

void Subscriber::print() const {
  std::cout << "Subscriber: " << phoneNum_ << std::endl;

  MsgArray tmp(inc_);
  tmp.add(out_);
  tmp.print();
}

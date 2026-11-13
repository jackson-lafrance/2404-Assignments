#include "Subscriber.h"
#include <iostream>
#include <string>

std::size_t Subscriber::nextId = 2001;

Subscriber::Subscriber(const std::string &phoneNum)
    : phoneNum_(phoneNum), id_(nextId++) {}

const std::string &Subscriber::phoneNum() const { return phoneNum_; }

void Subscriber::print() const {
  std::cout << "Subscriber :: " << id_ << " :: " << phoneNum_ << std::endl;
}

#include <iostream>

#include "MsgArray.h"
#include "defs.h"

MsgArray::MsgArray() : size_(0) {}
MsgArray::MsgArray(const MsgArray &msgArray) : size_(0) { add(msgArray); }
MsgArray::~MsgArray() {}

bool MsgArray::add(const MsgArray &msgArray) {
  for (int i{0}; i < msgArray.size_; ++i)
    if (!add(msgArray.elements_[i]))
      return false;

  return true;
}

void MsgArray::cleanup() {
  for (int i = 0; i < size_; ++i)
    delete elements_[i];
}

bool MsgArray::add(Msg *msg) {
  if (size_ >= MAX_ARR_SIZE)
    return false;

  for (int i{size_ - 1}; i >= 0; --i) {
    if (!msg->greaterThan(elements_[i])) {
      elements_[i + 1] = msg;
      ++size_;
      return true;
    }
    elements_[i + 1] = elements_[i];
  }

  elements_[0] = msg;
  ++size_;
  return true;
}

void MsgArray::print() const {
  if (size_ == 0)
    std::cout << "No messages" << std::endl;
  for (int i = 0; i < size_; ++i)
    elements_[i]->print();
  std::cout << std::endl;
}

int MsgArray::size() const { return size_; }

Msg *MsgArray::get(int index) const {
  return size_ > index && index >= 0 ? elements_[index] : nullptr;
}

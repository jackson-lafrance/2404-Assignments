#include <iostream>

#include "SubArray.h"
#include "defs.h"

SubArray::SubArray() : size_(0) {}

SubArray::SubArray(const SubArray &subArray) : size_(0) {
  add(subArray);
}

SubArray::~SubArray() {}

bool SubArray::add(const SubArray &subArray) {
  for (int i = 0; i < subArray.size_; ++i) {
    if (!add(subArray.elements_[i]))
      return false;
  }

  return true;
}

void SubArray::cleanup() {
  for (int i = 0; i < size_; ++i)
    delete elements_[i];

  size_ = 0;
}

bool SubArray::add(Subscriber *subscriber) {
  if (subscriber == nullptr || size_ >= MAX_ARR_SIZE)
    return false;

  elements_[size_++] = subscriber;
  return true;
}

void SubArray::print() const {
  if (size_ == 0) {
    std::cout << "No subscribers" << std::endl;
    return;
  }

  for (int i = 0; i < size_; ++i)
    elements_[i]->print();

  std::cout << std::endl;
}

int SubArray::size() const { return size_; }

Subscriber *SubArray::get(int index) const {
  return index >= 0 && index < size_ ? elements_[index] : nullptr;
}

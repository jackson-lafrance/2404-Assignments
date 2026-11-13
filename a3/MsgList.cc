#include "MsgList.h"
#include <iostream>

MsgList::MsgList() : head_(nullptr), size_(0) {}

MsgList::~MsgList() {
  Node *current = head_;

  while (current != nullptr) {
    Node *next = current->next_;

    delete current;

    current = next;
  }

  head_ = nullptr;
  size_ = 0;
}

std::size_t MsgList::size() const { return size_; }

void MsgList::add(Msg *msg) {
  if (msg == nullptr)
    return;

  Node *new_node = new Node;
  new_node->next_ = nullptr;
  new_node->prev_ = nullptr;
  new_node->data_ = msg;

  if (head_ == nullptr) {
    head_ = new_node;
    ++size_;
    return;
  }

  Node *current = head_;
  Node *prev = nullptr;
  while (current != nullptr) {
    if (new_node->data_->greaterThan(current->data_)) {
      if (prev != nullptr) {
        new_node->prev_ = prev;
        prev->next_ = new_node;
      } else {
        head_ = new_node;
      }

      new_node->next_ = current;
      current->prev_ = new_node;
      ++size_;
      return;
    }
    prev = current;
    current = current->next_;
  }

  prev->next_ = new_node;
  new_node->prev_ = prev;
  ++size_;
}

void MsgList::copySubset(const std::string &phoneNum, MsgList &origList) {
  Node *current = origList.head_;

  while (current != nullptr) {
    if (current->data_->src() == phoneNum || current->data_->dest() == phoneNum)
      add(current->data_);

    current = current->next_;
  }
}

void MsgList::cleanup() {
  Node *current = head_;

  while (current != nullptr) {
    Node *next = current->next_;

    delete current->data_;
    delete current;

    current = next;
  }

  head_ = nullptr;
  size_ = 0;
}

void MsgList::print() {
  if (head_ == nullptr) {
    std::cout << "No messages" << std::endl;
    return;
  }

  Node *current = head_;
  while (current != nullptr) {
    current->data_->print();
    if (current->next_ == nullptr)
      break;
    current = current->next_;
  }

  while (current != nullptr) {
    current->data_->print();
    if (current->prev_ == nullptr)
      break;
    current = current->prev_;
  }
}

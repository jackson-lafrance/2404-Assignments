#ifndef MSG_LIST_H
#define MSG_LIST_H

#include "Msg.h"
#include <cstddef>

class MsgList {
private:
  class Node {
    friend MsgList;

  private:
    Node *next_;
    Node *prev_;
    Msg *data_;
  };

public:
  MsgList();
  ~MsgList();

  std::size_t size() const;
  void add(Msg *msg);
  void copySubset(const std::string &phoneNum, MsgList &origList);
  void cleanup();
  void print();

private:
  Node *head_;
  std::size_t size_;
};

#endif // MSG_LIST_H

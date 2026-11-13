/*
 * Class: MsgList
 * Purpose: Stores message pointers in a doubly linked list in descending date and time order.
 *
 * Data members:
 *   head_ - Pointer to the first node in the list
 *   size_ - Number of nodes currently stored
 *
 * Member functions:
 *   MsgList()             - Initializes an empty list
 *   ~MsgList()            - Deletes list nodes without deleting shared messages
 *   size()                - Returns the number of messages in the list
 *   add()                 - Inserts a message in descending date and time order
 *   copySubset()          - Copies messages involving a phone number
 *   copySources()         - Copies messages sent by a phone number
 *   copyDestinations()    - Copies messages received by a phone number
 *   cleanup()             - Deletes every message and node in the list
 *   print()               - Prints the list forward and backward
 *   printSimple()         - Prints each message once in the frequent format
 */
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
  void copySubset(const std::string &phoneNum, const MsgList &origList);
  void copySources(const std::string &phoneNum, const MsgList &origList);
  void copyDestinations(const std::string &phoneNum,
                        const MsgList &origList);

  // i dont think this is a good idea because it lets temporary message lists
  // call cleanup and kill the main guys pointers
  void cleanup();
  void print() const;
  void printSimple() const;

private:
  Node *head_;
  std::size_t size_;
};

#endif // MSG_LIST_H

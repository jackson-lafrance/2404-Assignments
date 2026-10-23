/*
 * Class: MsgArray
 * Purpose: Stores a collection of message pointers in descending date and time order
 *
 * Data members:
 *   elements_ - Primitive array containing message pointers
 *   size_     - Number of message pointers currently stored
 *
 * Member functions:
 *   MsgArray() - Initializes an empty message collection
 *   ~MsgArray()- Leaves the shared messages unchanged
 *   cleanup()  - Cleans up every message in the collection
 *   add()      - Adds one message or every message from another collection
 *   print()    - Prints every message in the collection
 *   size()     - Returns the number of messages
 *   get()      - Returns the message at a given index
 */
#ifndef MSGARRAY_H
#define MSGARRAY_H

#include "Date.h"
#include "Msg.h"
#include "defs.h"

class MsgArray {
public:
  MsgArray();
  MsgArray(const MsgArray &msgArray);
  ~MsgArray();
  void cleanup();
  bool add(Msg *msg);
  bool add(const MsgArray &msgArray);
  void print() const;
  int size() const;
  Msg *get(int index) const;

private:
  Msg *elements_[MAX_ARR_SIZE];
  int size_; // number of elements
};

#endif // MSGARRAY_H

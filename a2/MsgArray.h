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
  void print();
  int size();
  Msg *get(int index);

private:
  Msg *elements_[MAX_ARR_SIZE];
  int size_; // number of elements
};

#endif // MSGARRAY_H

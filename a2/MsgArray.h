#ifndef MSGARRAY_H
#define MSGARRAY_H

#include "Date.h"
#include "Msg.h"
#include "defs.h"

class Array {
public:
  Array();
  ~Array();
  void add(Msg *d);
  void print();

private:
  Msg *elements[MAX_ARR_SIZE];
  int size; // number of elements
};

#endif // MSGARRAY_H

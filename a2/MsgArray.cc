#include <iostream>

#include "MsgArray.h"

Array::Array() { size = 0; }

Array::~Array() {
  for (int i = 0; i < size; ++i)
    delete elements[i];
}

void Array::add(Msg *d) {
  if (size >= MAX_ARR_SIZE)
    return;

  elements[size++] = d;
}

void Array::print() {
  cout << endl << "MSG:" << endl;
  for (int i = 0; i < size; ++i)
    elements[i]->print();
  cout << endl;
}

#ifndef VIEW_H
#define VIEW_H

#include "defs.h"

class View {
public:
  void showMenu(int &);
  void printStr(std::string);
  void readInt(int &);
  void readStr(std::string &);
};

#endif // VIEW_H

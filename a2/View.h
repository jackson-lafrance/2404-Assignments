/*
 * Class: View
 * Purpose: Manages all the input and output between the program and the user
 *
 * Data members:
 *   None
 *
 * Member functions:
 *   showMenu() - Prints the main menu and reads the user's selection
 *   printStr() - Prints a string
 *   readInt()  - Reads an integer from the user
 *   readStr()  - Reads a string from the user
 */
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

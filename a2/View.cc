#include "View.h"

void View::showMenu(int &choice) {
  int numOptions = 3;

  std::cout << std::endl;
  std::cout << "What would you like to do:" << std::endl;
  std::cout << "  (1) Compute most frequent sender" << std::endl;
  std::cout << "  (2) Compute most frequent receiver" << std::endl;
  std::cout << "  (3) Print subscribers" << std::endl;
  std::cout << "  (0) Exit" << std::endl << std::endl;

  std::cout << "Enter your selection: ";
  std::cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > numOptions) {
    std::cout << "Enter your selection: ";
    std::cin >> choice;
  }
}

void View::printStr(std::string str) { std::cout << str; }
void View::readInt(int &n) { std::cin >> n; }
void View::readStr(std::string &str) { std::cin >> str; }

#include "Account.h"

#include <iomanip>
#include <iostream>

Account::Account(int i, int c, float b) {
  id_ = i;
  customer_id_ = c;
  balance_ = b;
}

int Account::id() { return id_; }

bool Account::credit(float amount) {
  if (amount <= 0) {
    return false;
  }

  balance_ += amount;
  return true;
}

bool Account::debit(float amount) {
  if (amount <= 0 || amount > balance_) {
    return false;
  }

  balance_ -= amount;
  return true;
}

void Account::print() {
  std::cout << std::setw(6) << id_;
  std::cout << std::setw(6) << customer_id_ << ":  ";
  std::cout << "$" << std::setw(8) << balance_ << std::endl;
  return;
}

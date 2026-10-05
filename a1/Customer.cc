#include "Customer.h"

#include <iomanip>

Customer::Customer(int i, std::string n) {
  id_ = i;
  name_ = n;
  num_accounts_ = 0;
}

int Customer::id() { return id_; }

bool Customer::addAccount(int acct_id, float init_bal) {
  if (acct_id < 0) {
    std::cout << "ACCOUNT ID CANNOT BE NEGATIVE";
  }

  if (init_bal < 0) {
    std::cout << "ACCOUNT BALANCE CANNOT BE NEGATIVE";
  }

  if (num_accounts_ >= MAX_ARR_SIZE) {
    std::cout << "CUSTOMER " << id_ << " IS AT MAX ACCOUNT CAPACITY!!!!!";
    return false;
  }

  accounts_[num_accounts_++] = Account(acct_id, id_, init_bal);
  return true;
}

bool Customer::containsAccount(int acct_id) {
  for (int i = 0; i < num_accounts_; ++i) {
    if (acct_id == accounts_[i].id()) {
      return true;
    }
  }

  return false;
}

Account &Customer::findAccount(int acct_id) {
  for (int i = 0; i < num_accounts_; ++i) {
    if (acct_id == accounts_[i].id()) {
      return accounts_[i];
    }
  }

  std::cout << "TERMINAL ERROR: ACCOUNT NOT FOUND!!!!!";
  exit(1);
}

void Customer::print() { std::cout << "customer print"; }

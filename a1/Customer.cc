#include "Customer.h"

#include <iomanip>
#include <iostream>

Customer::Customer(int i, std::string n) {
  id_ = i;
  name_ = n;
  num_accounts_ = 0;
}

int Customer::id() { return id_; }

bool Customer::addAccount(int acct_id, float init_bal) {
  if (acct_id < 0) {
    std::cout << "MAYBE WE SHOULD'VE MADE ID A SIZE_T... ID MUST BE >= 0"
              << std::endl;
    return false;
  }

  if (containsAccount(acct_id)) {
    std::cout << "DEMENTIA ERROR!!! ACCOUNT ALREADY EXISTS" << std::endl;
    return false;
  }

  if (init_bal < 0) {
    std::cout << "WE DON'T OFFER LOANS HERE BUDDY!!! BALANCE MUST BE >= 0"
              << std::endl;
    return false;
  }

  if (num_accounts_ >= MAX_ARR_SIZE) {
    std::cout << "YOU REALLY NEED THAT MANY ACCOUNTS??? ACCOUNT ARRAY FULL"
              << std::endl;
    return false;
  }
  Account newAccount(acct_id, id_, init_bal);
  accounts_[num_accounts_++] = newAccount;
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
  for (int i{0}; i < num_accounts_; ++i)
    if (acct_id == accounts_[i].id())
      return accounts_[i];

  std::cout << "I SWEAR I WAS JUST LOOKING AT IT!!! ACCOUNT NOT FOUND ERROR"
            << std::endl;
  exit(1);
}

void Customer::print() {
  std::cout << "==" << std::setw(6) << id_ << "  " << name_ << std::endl;
  if (num_accounts_ == 0)
    std::cout << std::setw(20) << "-- NO ACCOUNTS" << std::endl;
  for (int i{0}; i < num_accounts_; ++i) {
    accounts_[i].print();
  }
}

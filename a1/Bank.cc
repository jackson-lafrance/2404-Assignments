#include "Bank.h"

Bank::Bank(std::string bank_name)
    : name_(bank_name), num_customers_(0), num_pending_transactions_(0),
      num_logged_transactions_(0) {};

void Bank::name(std::string bank_name) {
  name_ = bank_name;
  return;
}

bool Bank::addCustomer(int cust_id, std::string cust_name) {
  if (cust_id < 0) {
    std::cout << "STOP BEING SO NEGATIVE!!! CUSTOMER ID MUST BE >= 0"
              << std::endl;
    return false;
  }

  if (containsCustomer(cust_id)) {
    std::cout << "DEMENTIA ERROR!!! CUSTOMER ALREADY EXISTS" << std::endl;
    return false;
  }

  if (num_customers_ >= MAX_ARR_SIZE) {
    std::cout
        << "THIS TOWN AIN'T BIG ENOUGH FOR BOTH OF US!!! CUSTOMER ARRAY FULL"
        << std::endl;
    return false;
  }
  Customer newCustomer(cust_id, cust_name);
  customers_[num_customers_++] = newCustomer;
  return true;
};

bool Bank::containsCustomer(int cust_id) {
  for (int i{0}; i < num_customers_; ++i)
    if (customers_[i].id() == cust_id)
      return true;
  return false;
}

Customer &Bank::findCustomer(int cust_id) {
  for (int i{0}; i < num_customers_; ++i)
    if (customers_[i].id() == cust_id)
      return customers_[i];

  std::cout << "YOU LOST HIM THAT FAST??? CUSTOMER NOT FOUND ERROR"
            << std::endl;
  exit(1);
}

bool Bank::addAccount(int acct_id, int cust_id, float init_bal) {
  if (acct_id < 0) {
    std::cout
        << "PLEASE STOP IT WITH THE NEGATIVE IDS!!! ACCOUNT ID MUST BE >= 0"
        << std::endl;
    return false;
  }

  if (containsCustomer(cust_id)) {
    if (containsAccount(acct_id)) {
      std::cout << "ACCOUNT " << acct_id << " ALREADY EXISTS!!!" << std::endl;
      return false;
    } else {
      return findCustomer(cust_id).addAccount(acct_id, init_bal);
    }
  }

  std::cout << "CUSTOMER: " << cust_id << " NOT FOUND!!!" << std::endl;
  return false;
}

bool Bank::containsAccount(int acct_id) {
  for (int i{0}; i < num_customers_; ++i)
    if (customers_[i].containsAccount(acct_id))
      return true;
  return false;
}

Account &Bank::findAccount(int acct_id) {
  for (int i{0}; i < num_customers_; ++i)
    if (customers_[i].containsAccount(acct_id))
      return customers_[i].findAccount(acct_id);

  std::cout << "HOPE YOU DIDN'T HAVE ANYTHING IMPORTANT THERE... ACCOUNT NOT "
               "FOUND ERROR"
            << std::endl;
  exit(1);
}

void Bank::addToTrArray(Transaction *arr, int &num_tr, Transaction &new_tr) {
  if (num_tr >= MAX_ARR_SIZE) {
    std::cout << "OKAY BIG BALLER!!! THAT'S TOO MANY TRANSACTIONS!!! "
                 "TRANSACTION ARRAY FULL"
              << std::endl;
    return;
  }

  Date &newDate = new_tr.date();
  for (int i{0}; i < num_tr; ++i) {
    Date &existingDate = arr[i].date();

    if (newDate.lessThan(existingDate)) {
      for (int j{num_tr}; j > i; --j)
        arr[j] = arr[j - 1];
      arr[i] = new_tr;
      ++num_tr;
      return;
    }
  }

  arr[num_tr] = new_tr;
  ++num_tr;
  return;
}

bool Bank::addTransaction(TransactionType t, int acct_id, float amt, int y,
                          int m, int d) {
  if (!containsAccount(acct_id)) {
    std::cout << "ACCOUNT " << acct_id << " NOT FOUND" << std::endl;
    return false;
  }

  if (t != TR_CREDIT && t != TR_DEBIT) {
    std::cout << "ILLEGAL TRANSACTION TYPE" << std::endl;
    return false;
  }

  if (num_pending_transactions_ >= MAX_ARR_SIZE) {
    std::cout << "CAN WE PROCESS SOME OF THESE??? "
                 "PENDING TRANSACTION ARRAY FULL"
              << std::endl;
    return false;
  }

  Transaction new_tr(t, acct_id, amt, y, m, d);
  addToTrArray(pending_transactions_, num_pending_transactions_, new_tr);
  return true;
}

void Bank::processTransactions() {
  int c_year;
  int c_month;
  int c_day;
  currentDate(c_year, c_month, c_day);
  Date c_date(c_year, c_month, c_day);
  int j{0};

  for (int i{0}; i < num_pending_transactions_; ++i) {

    Transaction tr = pending_transactions_[i];
    Date &tr_date = tr.date();

    if (!c_date.lessThan(tr_date)) {
      int acct_id = tr.account_id();

      if (containsAccount(acct_id)) {
        if (num_logged_transactions_ > MAX_ARR_SIZE) {
          std::cout << "LOGGED TRANSACTION ARRAY FULL" << std::endl;
        } else if (tr.process(findAccount(acct_id))) {
          addToTrArray(logged_transactions_, num_logged_transactions_, tr);
        }
      } else
        std::cout << "ACCOUNT " << acct_id << " NOT FOUND!!" << std::endl;
    } else {
      pending_transactions_[j++] = tr;
    }
  }

  num_pending_transactions_ = j;
}

void Bank::printCustomers() {
  if (num_customers_ == 0)
    std::cout << std::setw(20) << "-- NO CUSTOMERS" << std::endl;
  for (int i{0}; i < num_customers_; ++i)
    customers_[i].print();
};

void Bank::printTransactions(Transaction *arr, int num_tr) {
  if (num_tr == 0)
    std::cout << std::setw(20) << "-- NO TRANSACTIONS" << std::endl;
  for (int i{0}; i < num_tr; ++i)
    arr[i].print();
};

void Bank::printPendingTr() {
  printTransactions(pending_transactions_, num_pending_transactions_);
}

void Bank::printLoggedTr() {
  printTransactions(logged_transactions_, num_logged_transactions_);
};

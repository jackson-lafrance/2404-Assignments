#include "Transaction.h"
#include "defs.h"

Transaction::Transaction(TransactionType t, int i, float a, int y, int m, int d)
    : date_(y, m, d) {
  account_id_ = i;
  amount_ = a;
  transaction_type_ = t;
}

int Transaction::account_id() { return account_id_; }

Date Transaction::date() { return date_; }

bool Transaction::process(Account &acct_id) {
  if (transaction_type_ == TR_CREDIT) {
    if (acct_id.credit(amount_)) {
      return true;
    }

    std::cout << "I DON'T THINK YOU WANNA DO THAT!!! CREDIT AMOUNT MUST BE > 0"
              << std::endl;
  }

  if (transaction_type_ == TR_DEBIT) {
    if (acct_id.debit(amount_)) {
      return true;
    }

    std::cout << "NICE TRY BUDDY!!! DEBIT AMOUNT MUST BE <= BALANCE AND > 0"
              << std::endl;
  }

  return false;
}

void Transaction::print() {
  std::cout << account_id_;
  std::cout << " :: ";
  std::cout << (transaction_type_ == TR_DEBIT    ? "Debit "
                : transaction_type_ == TR_CREDIT ? "Credit"
                                                 : "Other ")
            << std::setw(5) << ":: ";
  date_.print();
  std::cout << " :: $" << std::setw(8) << amount_ << endl;
  ;
}

include "Transaction.h"

Transaction::Transaction(TransactionType t, int i, float a, int y, int m, int d) : date_(y, m, d) {
	account_id_ = i;
	amount_ = a;
}

int Transaction::account_id() {
	return account_id_;
}

Date Transaction::date() {
	return date_;
}

bool Transaction::process(Account& acct_id) {
	return (transaction_type_ == TR_CREDIT && acct_id.credit(amount_)) || (transaction_type_ == TR_DEBIT && acct_id.debit(amount_));
}

void Transaction::print() {
	std::cout << "transaction print";
}

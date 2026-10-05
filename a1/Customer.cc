#include "Customer.h"

#include <iomanip>

Customer::Customer(int i, std::string n) {
	id_ = i;
	name_ = n;
	num_accounts_ = 0;
}

int Customer::id() {
	return id_;
}

bool Customer::addAccount(int acctId, float acctBalance) {
	if (acctId < 0) {
		std::cout << "ACCOUNT ID CANNOT BE NEGATIVE";
	}

	if (acctBalance < 0) {
		std::cout << "ACCOUNT BALANCE CANNOT BE NEGATIVE";
	}

	if (num_accounts >= MAX_ARR_SIZE) {
		std::cout << "CUSTOMER " << id_ << " IS AT MAX ACCOUNT CAPACITY!!!!!";
		return false;
	}

	accounts_[num_accounts++] = Account(acctId, id_, acctBalance);
	return true;
}

bool Customer::contains(int acctId) {
	for (int i = 0; i < num_accounts; ++i) {
		if (acctId == accounts_[i].id) {
			return true;
		}
	}

	return false;
}

Account& Customer::findAccount(int acctId) {
	for (int i = 0; i < num_accounts; ++i) {
		if (acctId == accounts_[i].id) {
			return accounts_[i]
		}
	}

	std::cout << "TERMINAL ERROR: ACCOUNT NOT FOUND!!!!!";
	exit(1);
}

void Customer::print() {
	std::cout << "customer print"
}

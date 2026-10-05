#include "Account.h"

#include <iostream>
#include <iomanip>

Account::Account(int i, int c, float b) {
	id_ = i;
	customer_id_ = c;
	balance_ = b;
}

int Account::id() {
	return id_;
}

bool Account::credit(float amt) {
	if (amt <= 0) {
		std::cout << "CREDIT AMOUNT MUST BE POSITIVE!!!!!";
		return false;
	}
	balance_ += amt;
	return true;
}	

bool Account::debit(float amt) {
	if (amt <= 0) {
		std::cout << "DEBIT AMOUNT MUST BE POSITIVE!!!!!";
		return false;
	}

	if (amt > balance) {
		std::cout << "BALANCE TOO LOW!!!!!";
	}
	balance_ -= amt;
	return true;
}

void Account::print() {
	std::cout << "balls";
	return;
}

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

bool Account::credit(float amount) {
	if (amount <= 0) {
		std::cout << "CREDIT AMOUNT MUST BE POSITIVE!!!!!";
		return false;
	}
	balance_ += amount;
	return true;
}	

bool Account::debit(float amount) {
	if (amount <= 0) {
		std::cout << "DEBIT AMOUNT MUST BE POSITIVE!!!!!";
		return false;
	}

	if (amount > balance_) {
		std::cout << "BALANCE TOO LOW!!!!!";
		return false;
	}
	balance_ -= amount;
	return true;
}

void Account::print() {
	std::cout << "Account print";
	return;
}

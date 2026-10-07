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
		std::cout << "I DON'T THINK YOU WANNA DO THAT!!! CREDIT AMOUNT MUST BE > 0" << std::endl;
		return false;
	}

	balance_ += amount;
	return true;
}	

bool Account::debit(float amount) {
	if (amount <= 0) {
		std::cout << "NICE TRY BUDDY!!! DEBIT AMOUNT MUST BE > 0" << std::endl;
		return false;
	}

	if (amount > balance_) {
		std::cout << "I DON'T THINK YOU CAN AFFORD THAT!!! DEBIT AMOUNT MUST BE <= BALANCE" << std::endl;
		return false;
	}

	balance_ -= amount;
	return true;
}

void Account::print() {
	std::cout << "Account print" << std::endl;
	return;
}

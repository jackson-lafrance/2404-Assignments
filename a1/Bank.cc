#include "Bank.h"

Bank::Bank(std::string bank_name) : num_customers(0), num_pending_transactions_(0), num_logged_transactions_(0), name_(bank_name);

void Bank::name(std::string bank_name) {
	name_ = bank_name;
	return void;
}

bool Bank::addCustomer(int cust_id, std::string cust_name) {
	if (cust_id < 0) {
		std::cout << "STOP BEING SO NEGATIVE!!! CUSTOMER ID >= 0";
		return false;
	}

	if (num_customers_ >= MAX_ARR_SIZE_ {
		std::cout << "THIS TOWN AIN'T BIG ENOUGH FOR BOTH OF US!!! CUSTOMER ARRAY FULL";
		return false;
	}

	customers_[num_customers_++] = Customer(cust_id, cust_name);
	return true;
};

bool Bank::containsCustomer(int cust_id) {
	for (int i{0}; i < num_customers_; ++i)
		if (customers_[i].id() == cust_id)
			return true;
	return false;
}

Customer& Bank::findCustomer(int cust_id) {
	for (int i{0}; i < num_customers_; ++i)
		if (customers_[i].id() == cust_id)
			return customers_[i];
	
	std::cout << "YOU LOST HIM THAT FAST??? CUSTOMER NOT FOUND ERROR";
	exit(1);
}


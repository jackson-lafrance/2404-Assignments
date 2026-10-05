#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "Account.h"
#include "defs.h"

class Customer {
	public:
		Customer(int i = 0, std::string n = "");
		int id();
		bool addAccount(int acct_id, float init_bal);
		bool containsAccount(int acct_id);
		Account &findAccount(int acct_id);
		void print();
	private:
		int id_;
		std::string name_;
		Account accounts_[MAX_ARR_SIZE];
		int num_accounts_;
};

#endif // CUSTOMER_H

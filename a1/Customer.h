/*
 * Class: Customer
 * Purpose: Represents a bank customer and the collection of accounts owned by that customer
 *
 * Data members:
 *   id_           - Id of the customer
 *   name_         - Customer's name
 *   accounts_     - Array containing the customer's accounts
 *   num_accounts_ - Number of accounts currently stored in accounts_.
 *
 * Member functions:
 *   Customer()       - Sets up the customer's identifier and name
 *   id()             - Returns the customer identifier
 *   addAccount()     - Creates and appends an account
 *   containsAccount() - Says whether the customer owns an account
 *   findAccount()    - Gives a reference to a requested account
 *   print()          - Prints the customer and all owned accounts
 */
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "Account.h"
#include "defs.h"

class Customer {
	public:
		Customer(int i = 0, const std::string &n = "");
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

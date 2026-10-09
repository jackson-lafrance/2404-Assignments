/*
 * Class: Account
 * Purpose: Represents one bank account owned by a customer. 
 *
 * Data members:
 *   id_          - Id of the account
 *   customer_id_ - Id of the customer who owns the account
 *   balance_     - Current account balance
 *
 * Member functions:
 *   Account() - Initializes the account identifiers and balance
 *   id()      - Returns the account identifier
 *   credit()  - Adds a positive amount to the balance
 *   debit()   - Subtracts an amount when sufficient funds are available
 *   print()   - Prints all account information
 */
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
	public:
		Account(int i = 0, int c = 0, float b = 0);
		int id();
		bool credit(float amount);
		bool debit(float amount);
		void print();
	private:
		int id_;
		int customer_id_;
		float balance_;
};

#endif // ACCOUNT_H

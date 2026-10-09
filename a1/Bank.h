/*
 * Class: Bank
 * Purpose: Manages the bank's customers, their accounts, and the collections of pending and logged transactions
 *
 * Data members:
 *   name_                     - Name of the bank
 *   customers_                - Primitive array of bank customers
 *   num_customers_            - Number of customers currently stored
 *   pending_transactions_     - Date-ordered array of unprocessed transactions
 *   num_pending_transactions_ - Number of pending transactions currently stored
 *   logged_transactions_      - Date-ordered array of processed transactions
 *   num_logged_transactions_  - Number of logged transactions currently stored
 *
 * Member functions:
 *   Bank()                - Initializes the bank and its collection counts
 *   name()                - Sets the bank's name
 *   addCustomer()         - Creates and appends a customer
 *   containsCustomer()    - Reports whether a customer belongs to the bank
 *   findCustomer()        - Returns a reference to a requested customer
 *   addAccount()          - Adds an account to an existing customer
 *   containsAccount()     - Reports whether an account belongs to the bank
 *   findAccount()         - Returns a reference to a requested account
 *   addToTrArray()        - Inserts a transaction in ascending date order
 *   addTransaction()      - Creates and stores a pending transaction
 *   processTransactions() - Processes all transactions dated today or earlier
 *   printCustomers()      - Prints every customer and account
 *   printTransactions()   - Prints the transactions in a supplied array
 *   printPendingTr()      - Prints all pending transactions
 *   printLoggedTr()       - Prints all logged transactions
 */
#ifndef BANK_H
#define BANK_H

#include <iostream>
#include "Customer.h"
#include "Transaction.h"
#include "defs.h"

class Bank {
	public:
		Bank(const std::string &bank_name = "");
		void name(const std::string &bank_name);

		bool addCustomer(int cust_id, const std::string &cust_name);
		bool containsCustomer(int cust_id);
		Customer& findCustomer(int cust_id);

		bool addAccount(int acct_id, int cust_id, float init_bal);
		bool containsAccount(int acct_id);
		Account& findAccount(int acct_id);

		void addToTrArray(Transaction* arr, int& num_tr, Transaction& new_tr);
		bool addTransaction(TransactionType t, int acct_id, float amt, int y, int m, int
d);
		void processTransactions();

		void printCustomers();
		void printTransactions(Transaction* arr, int num_tr);
		void printPendingTr();
		void printLoggedTr();
	private:
		std::string name_;
		Customer customers_[MAX_ARR_SIZE];
		int num_customers_;

		Transaction pending_transactions_[MAX_ARR_SIZE];
		int num_pending_transactions_;

		Transaction logged_transactions_[MAX_ARR_SIZE];
		int num_logged_transactions_;
};

#endif // BANK_H

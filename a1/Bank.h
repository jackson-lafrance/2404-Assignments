#ifndef BANK_H
#define BANK_H

#include <iostream>
#include "Customer.h"
#include "Transaction.h"
#include "defs.h"

class Bank {
	public:
		Bank(std::string bank_name = "");
		void name(std::string bank_name);

		bool addCustomer(int cust_id, std::string cust_name);
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

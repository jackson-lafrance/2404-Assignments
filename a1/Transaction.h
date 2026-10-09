/*
 * Class: Transaction
 * Purpose: Represents a dated credit or debit operation to be performed on one bank account.
 *
 * Data members:
 *   transaction_type_ - Indicates whether the operation is a credit or debit
 *   account_id_       - Identifier of the affected account
 *   amount_           - Amount of the transaction
 *   date_             - Date on which the transaction is scheduled
 *
 * Member functions:
 *   Transaction() - Initializes the type, account, amount, and date
 *   account_id()  - Returns the affected account's identifier
 *   date()        - Returns a reference to the transaction date
 *   process()     - Applies the credit or debit to a supplied account
 *   print()       - Prints all transaction information
 */
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "defs.h"
#include "Date.h"
#include "Account.h"

class Transaction {
	public:
		Transaction(TransactionType t = TR_OTHER, int i = 0, float a = 0, int y = 2007, int m = 6, int d = 5);
		int account_id();
		Date &date();
		bool process(Account& account);
		void print();
	private:
		TransactionType transaction_type_;
		int account_id_;
		float amount_;
		Date date_;
};

#endif // TRANSACTION_H

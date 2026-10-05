#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "defs.h"
#include "Date.h"

class Transaction {
	public:
		Transaction(TransactionType t = TR_OTHER, int i = 0, float a = 0, int y = 2007, int m = 6, int d = 5);
		int account_id();
		Date date();
		bool process(Account&);
		void print();
	private:
		TransactionType transaction_type_;
		int account_id_;
		float amount_;
		Date date_;
}

#endif // TRANSACTION_H

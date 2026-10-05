#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
	public:
		Account(int i = 0, int c = 0, float b = 0);
		int id();
		bool credit(float);
		bool debit(float);
		void print();
	private:
		int id_;
		int customer_id_;
		float balance_;
}

#endif // ACCOUNT_H

#include "Bank.h"
#include "defs.h"

int main() {
  Bank riverBank("River Bank");

  loadCustomerData(riverBank);
  loadTransactionData(riverBank);

  int choice = -1;
  while (choice != 0) {
    printMenu(choice);

    switch (choice) {
    case 1:
      riverBank.printCustomers();
      break;
    case 2: {
      int type = -1;
      while (type != 1 || type != 2) {
        cout << endl << "NEW TRANSACTION" << endl;
        cout << "  (1) Credit" << endl;
        cout << "  (2) Debit" << endl;
        cout << "Please select the transaction type: ";
        cin >> type;
      }

      int acct_id = -1;
      while (!riverBank.containsAccount(acct_id)) {
        cout << endl << "NEW TRANSACTION" << endl;
        cout << "Please enter your account id: ";
        cin >> acct_id;
      }

      int amt = -1;
      while (amt <= 0) {
        cout << endl << "NEW TRANSACTION" << endl;
        cout << "Please enter the amount you wish to "
             << (type == 1 ? "credit" : "debit") << ": ";
        cin >> amt;
      }

      int y;
      int m;
      int d;
      currentDate(y, m, d);

      if (riverBank.addTransaction(type == 1 ? TR_CREDIT : TR_DEBIT, acct_id,
                                   amt, y, m, d))
        cout << "SUCCESSFULLY ADDED TRANSACTION";
      else
        cout << "FAILED TO ADD TRANSACTION";

      break;
    }
    case 3:
      riverBank.processTransactions();
      break;
    case 4:
      riverBank.printPendingTr();
      break;
    case 5:
      riverBank.printLoggedTr();
      break;
    }
  }

  return 0;
}

void printMenu(int &choice) {
  int c = -1;
  int numOptions = 5;

  cout << endl << "MAIN MENU" << endl;
  cout << "  (1) Print customers" << endl;
  cout << "  (2) New transaction" << endl;
  cout << "  (3) Process transactions" << endl;
  cout << "  (4) Print pending transactions" << endl;
  cout << "  (5) Print logged transactions" << endl;
  cout << "  (0) Exit" << endl << endl;

  cout << "Please enter your selection: ";
  cin >> c;

  if (c == 0) {
    choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    cout << "Please enter your selection: ";
    cin >> c;
  }

  choice = c;
}

void loadCustomerData(Bank &currBank) {
  int custId = 1001;

  currBank.addCustomer(custId++, "Bill");
  currBank.addCustomer(custId++, "Laura");
  currBank.addCustomer(custId++, "D'Anna");
  currBank.addCustomer(custId++, "Kara");
  currBank.addCustomer(custId++, "Lee");
  currBank.addCustomer(custId++, "Six");
  currBank.addCustomer(custId++, "Ellen");
  currBank.addCustomer(custId++, "Sharon");
  currBank.addCustomer(custId++, "Sam");
  currBank.addCustomer(custId++, "Galen");

  currBank.addAccount(200120, 1010, 33.4f);
  currBank.addAccount(200121, 1001, 100.34f);
  currBank.addAccount(200122, 1007, 540.22f);
  currBank.addAccount(200123, 1005, 2323.44f);
  currBank.addAccount(200124, 2001, 99.99f);
  currBank.addAccount(200125, 1005, 344.89f);
  currBank.addAccount(200126, 1007, 74.43f);
  currBank.addAccount(200127, 1003, 1783.55f);
  currBank.addAccount(200128, 1003, 98.77f);
  currBank.addAccount(200129, 1004, 5.89f);
  currBank.addAccount(200130, 1002, 77.77f);
  currBank.addAccount(200131, 1002, 98.8f);
  currBank.addAccount(200132, 1007, 234.54f);
  currBank.addAccount(200133, 1007, 789.11f);
  currBank.addAccount(200134, 1008, 53.21f);
  currBank.addAccount(200135, 1008, 1010.88f);
  currBank.addAccount(200136, 1005, 831.43f);
  currBank.addAccount(200137, 1001, 2545.76f);
  currBank.addAccount(200138, 1002, 987.00f);
  currBank.addAccount(200139, 1008, 11.65f);
}

void loadTransactionData(Bank &currBank) {
  currBank.addTransaction(TR_DEBIT, 200127, 50.00f, 2026, 9, 22);
  currBank.addTransaction(TR_DEBIT, 200155, 150.00f, 2026, 9, 23);
  currBank.addTransaction(TR_DEBIT, 200129, 250.00f, 2026, 9, 15);
  currBank.addTransaction(TR_DEBIT, 200121, 100.00f, 2026, 9, 13);
  currBank.addTransaction(TR_DEBIT, 200120, 5.00f, 2026, 9, 14);
  currBank.addTransaction(TR_DEBIT, 200138, 43.88f, 2026, 9, 23);
  currBank.addTransaction(TR_DEBIT, 200138, 245.98f, 2026, 10, 1);
  currBank.addTransaction(TR_DEBIT, 200139, 15.00f, 2026, 9, 19);
  currBank.addTransaction(TR_DEBIT, 200133, 388.23f, 2026, 10, 10);
  currBank.addTransaction(TR_DEBIT, 200132, 100.00f, 2026, 10, 3);
  currBank.addTransaction(TR_DEBIT, 200130, 5.00f, 2026, 9, 21);
  currBank.addTransaction(TR_DEBIT, 200130, -10.00f, 2026, 9, 30);

  currBank.addTransaction(TR_CREDIT, 200122, -8.99f, 2026, 9, 14);
  currBank.addTransaction(TR_CREDIT, 200124, 88.79f, 2026, 9, 16);
  currBank.addTransaction(TR_CREDIT, 200129, 88.79f, 2026, 10, 24);
  currBank.addTransaction(TR_CREDIT, 200126, 223.12f, 2026, 9, 12);
  currBank.addTransaction(TR_CREDIT, 200125, 786.09f, 2026, 10, 5);
  currBank.addTransaction(TR_CREDIT, 200125, 433.12f, 2026, 10, 13);
}

void currentDate(int &year, int &month, int &day) {
  time_t t = time(0);
  tm *now = localtime(&t);

  year = now->tm_year + 1900;
  month = now->tm_mon + 1;
  day = now->tm_mday;
}

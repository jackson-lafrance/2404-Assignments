CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

a1: main.o Account.o Bank.o Customer.o Date.o Transaction.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cc Account.h Bank.h Customer.h Date.h Transaction.h
	$(CXX) $(CXXFLAGS) -c main.cc

Account.o: Account.cc Account.h
	$(CXX) $(CXXFLAGS) -c Account.cc

Bank.o: Bank.cc Bank.h Customer.h Transaction.h
	$(CXX) $(CXXFLAGS) -c Bank.cc

Customer.o: Customer.cc Customer.h Account.h defs.h
	$(CXX) $(CXXFLAGS) -c Customer.cc

Date.o: Date.cc Date.h
	$(CXX) $(CXXFLAGS) -c Date.cc

Transaction.o: Transaction.cc Transaction.h Date.h defs.h
	$(CXX) $(CXXFLAGS) -c Transaction.cc

run: a1
	./a1

clean: 
	rm -f *.o a1 

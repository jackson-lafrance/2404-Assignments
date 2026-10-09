CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

a1: Account.o Bank.o Customer.o Date.o main.o Transaction.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: Account.h Bank.h Customer.h Date.h defs.h main.cc Transaction.h
	$(CXX) $(CXXFLAGS) -c main.cc

Account.o: Account.cc Account.h
	$(CXX) $(CXXFLAGS) -c Account.cc

Bank.o: Account.h Bank.cc Bank.h Customer.h Date.h defs.h Transaction.h
	$(CXX) $(CXXFLAGS) -c Bank.cc

Customer.o: Account.h Customer.cc Customer.h defs.h
	$(CXX) $(CXXFLAGS) -c Customer.cc

Date.o: Date.cc Date.h
	$(CXX) $(CXXFLAGS) -c Date.cc

Transaction.o: Account.h Date.h defs.h Transaction.cc Transaction.h
	$(CXX) $(CXXFLAGS) -c Transaction.cc

run: a1
	./a1

clean: 
	rm -f *.o a1 

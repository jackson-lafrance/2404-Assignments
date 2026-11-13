/*
 * Class: InternMsg
 * Purpose: Represents a message between two telco subscribers.
 *
 * Data members:
 *   src_  - Pointer to the subscriber who sent the message
 *   dest_ - Pointer to the subscriber who received the message
 *
 * Member functions:
 *   InternMsg() - Initializes the message and subscriber pointers
 *   src()      - Returns the source subscriber's phone number
 *   dest()     - Returns the destination subscriber's phone number
 *   print()       - Prints the message and phone numbers
 *   printSimple() - Prints the message in the frequent-message format
 */
#ifndef INTERN_MSG_H
#define INTERN_MSG_H

#include "Msg.h"
#include "Subscriber.h"

class InternMsg : public Msg {
public:
  InternMsg(int day = 5, int month = 6, int year = 2007, int hours = 10,
            int mins = 30, Subscriber *src = nullptr,
            Subscriber *dest = nullptr);

  // why are we using virtual at the start instead of override at the end
  // which makes it clear that this is the sub classes function
  virtual std::string src() const;
  virtual std::string dest() const;
  virtual void print() const;
  virtual void printSimple() const;

private:
  Subscriber *src_;
  Subscriber *dest_;
};

#endif // INTERN_MSG_H

/*
 * Class: Msg
 * Purpose: Represents a text message with a date and time.
 *
 * Data members:
 *   date_ - Pointer to the date the message was sent
 *   time_ - Pointer to the time the message was sent
 *
 * Member functions:
 *   Msg()         - Initializes the message date and time
 *   ~Msg()        - Cleans up the date and time
 *   greaterThan() - Reports whether this message was sent later
 *   print()       - Prints the date and time with message details
 *   printSimple() - Prints the date and time in the frequent-message format
 *   src()         - Returns the source phone number
 *   dest()        - Returns the destination phone number
 */
#ifndef MSG_H
#define MSG_H

#include "Date.h"
#include "Time.h"
#include <string>

class Msg {
public:
  // Why would we want to have a constructor? shouldnt it be private msg should
  // be an abstract clas
  Msg(int day = 5, int month = 6, int year = 2007, int hours = 10,
      int mins = 30);

  virtual ~Msg();
  virtual bool greaterThan(Msg *msg) const;
  virtual void print() const;
  virtual void printSimple() const;
  // if these are going to be overriden anyways why would we implement them here
  // since theres no actual src_ or dest_ in our class this means i cant make the
  // function return a const reference and we have to return a copy of a string
  virtual std::string src() const;
  virtual std::string dest() const;

private:
  Date *date_;
  Time *time_;
};

#endif // MSG_H

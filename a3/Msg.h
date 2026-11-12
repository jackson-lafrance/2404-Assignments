/*
 * Class: Msg
 * Purpose: Represents one text message sent from one phone number to another
 *
 * Data members:
 *   src_  - Phone number that sent the message
 *   dest_ - Phone number that received the message
 *   date_ - Pointer to the date the message was sent
 *   time_ - Pointer to the time the message was sent
 *
 * Member functions:
 *   Msg()         - Initializes the phone numbers, date, and time
 *   ~Msg()        - Cleans up the dynamically allocated date and time
 *   greaterThan() - Reports whether this message was sent after another message
 *   print()       - Prints all message information
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
  virtual std::string src() const;
  virtual std::string dest() const;

private:
  Date *date_;
  Time *time_;
};

#endif // MSG_H

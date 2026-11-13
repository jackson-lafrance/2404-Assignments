/*
 * Class: ExternMsg
 * Purpose: Represents a message between a subscriber and a non-subscriber.
 *
 * Data members:
 *   src_  - Source phone number
 *   dest_ - Destination phone number
 *
 * Member functions:
 *   ExternMsg() - Initializes the message and phone numbers
 *   src()      - Returns the source phone number
 *   dest()     - Returns the destination phone number
 *   print()       - Prints the message and phone numbers
 *   printSimple() - Prints the message in the frequent-message format
 */
#ifndef EXTERN_MSG_H
#define EXTERN_MSG_H

#include "Msg.h"

class ExternMsg : public Msg {
public:
  ExternMsg(int day = 5, int month = 6, int year = 2007, int hours = 10,
            int mins = 30, const std::string &src = "613-324-8204",
            const std::string &dest = "613-721-3331");

  // why are we using virtual at the start instead of override at the end
  // which makes it clear that this is the sub classes function
  virtual std::string src() const;
  virtual std::string dest() const;
  // this is not very good and makes you have to change how msg print works
  // if you have to call your own getters and setters from within your class's
  // own functions it it usually means your class is too complicated
  // so why do we have to do it? its a bad habit
  virtual void print() const;
  virtual void printSimple() const;

private:
  std::string src_;
  std::string dest_;
};

#endif // EXTERN_MSG_H

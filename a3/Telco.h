/*
 * Class: Telco
 * Purpose: Manages the telco subscribers and all of its messages.
 *
 * Data members:
 *   name_     - Name of the telco
 *   subs_     - Collection of subscriber pointers
 *   messages_ - Collection of all telco message pointers
 *
 * Member functions:
 *   Telco()          - Initializes the telco name and collections
 *   ~Telco()         - Cleans up messages and subscribers
 *   addSub()         - Dynamically allocates and adds a subscriber
 *   addMsg()         - Dynamically allocates and adds a message
 *   printMessages()  - Prints all telco messages
 *   printSubscribers()- Prints every subscriber and their messages
 *   printByActivity()- Prints subscribers by total message activity
 *   printFrequent()  - Prints subscribers by sent or received messages
 *   findSub()        - Finds a subscriber by phone number
 */
#ifndef TELCO_H
#define TELCO_H

#include "MsgList.h"
#include "SubArray.h"
#include "Subscriber.h"
#include "defs.h"
#include <string>

class Telco {
public:
  Telco(const std::string &name = "Jackson's telco co.");
  ~Telco();
  void addSub(const std::string &phone_number);
  void addMsg(const std::string &src_num, const std::string &dest_num, int year, int month,
              int day, int hours, int mins);
  void printMessages() const;
  void printSubscribers() const;
  // i feel like by now we should be using size_t always instead of integers
  // there are osm any antipatterns that we learn :(
  void printByActivity() const;
  void printFrequent(SubscriberType subType) const;

private:
  std::string name_;

  SubArray subs_;
  MsgList messages_;

  bool findSub(const std::string &phone_num, Subscriber **sub);
  bool findSub(const std::string &phone_num);
};

#endif // TELCO_H

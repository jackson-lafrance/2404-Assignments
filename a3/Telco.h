/*
 * Class: Telco
 * Purpose: Manages the telco subscribers and the primary collection of all messages
 *
 * Data members:
 *   name_           - Name of the telco
 *   numSubscribers_ - Number of subscribers currently stored
 *   subscribers_    - Primitive array containing subscriber pointers
 *   messages_       - Primary collection containing all telco messages
 *
 * Member functions:
 *   Telco()          - Initializes the telco name and subscriber count
 *   ~Telco()         - Cleans up all messages and subscribers
 *   addSub()         - Dynamically allocates and adds a subscriber
 *   addMsg()         - Dynamically allocates and adds a message
 *   printSubscribers()- Prints every subscriber and their messages
 *   printFrequent()  - Prints subscribers in order of message frequency
 *   findSub()        - Finds whether a phone number belongs to a subscriber
 */
#ifndef TELCO_H
#define TELCO_H

#include "Subscriber.h"
#include "defs.h"
#include <string>

class Telco {
public:
  Telco(const std::string &name = "Hannah Montana");
  ~Telco();
  void addSub(std::string phoneNumber);
  void addMsg(std::string srcNum, std::string destNum, int year, int month,
              int day, int hours, int mins);
  void printSubscribers() const;
  void printFrequent(SubscriberType subType) const;

private:
  std::string name_;
  int numSubscribers_;

  Subscriber *subscribers_[MAX_ARR_SIZE];
  MsgArray messages_;

  bool findSub(std::string phoneNum, Subscriber **sub);
  bool findSub(std::string phoneNum);
};

#endif // TELCO_H

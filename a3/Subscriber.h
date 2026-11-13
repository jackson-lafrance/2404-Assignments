/*
 * Class: Subscriber
 * Purpose: Represents one subscriber in the telco.
 *
 * Data members:
 *   nextId    - Next identifier assigned to a subscriber
 *   phoneNum_ - Phone number belonging to the subscriber
 *   id_       - Unique identifier belonging to the subscriber
 *
 * Member functions:
 *   Subscriber() - Initializes the subscriber phone number and identifier
 *   print()      - Prints the subscriber information
 *   phoneNum()  - Returns the subscriber phone number
 */
#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Msg.h"
#include <string>

class Subscriber {
public:
  static std::size_t nextId;
  Subscriber(const std::string &phoneNum = "613-716-4222");
  void print() const;
  const std::string &phoneNum() const;

private:
  std::string phoneNum_;
  std::size_t id_;
};

#endif // SUBSCRIBER_H

/*
 * Class: Subscriber
 * Purpose: Represents one telco subscriber and their incoming and outgoing messages
 *
 * Data members:
 *   phoneNum_ - Phone number belonging to the subscriber
 *   inc_      - Collection of messages received by the subscriber
 *   out_      - Collection of messages sent by the subscriber
 *
 * Member functions:
 *   Subscriber() - Initializes the subscriber phone number
 *   addIncoming()- Adds a message to the incoming collection
 *   addOutgoing()- Adds a message to the outgoing collection
 *   print()      - Prints the subscriber and all their messages
 *   phoneNum()   - Returns the subscriber phone number
 *   inc()        - Returns a reference to the incoming collection
 *   out()        - Returns a reference to the outgoing collection
 */
#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Msg.h"
#include "MsgArray.h"
#include <string>

class Subscriber {
public:
  Subscriber(const std::string &phoneNum = "613-716-4222");
  void addIncoming(Msg *msg);
  void addOutgoing(Msg *msg);
  void print() const;
  const std::string &phoneNum() const;
  MsgArray &inc();
  MsgArray &out();

private:
  std::string phoneNum_;
  MsgArray inc_;
  MsgArray out_;
};

#endif // SUBSCRIBER_H

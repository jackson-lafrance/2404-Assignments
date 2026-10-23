#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Msg.h"
#include <string>

class Subscriber {
public:
  void addIncoming(Msg *msg);
  void addOutgoing(Msg *msg);
  void print();

private:
  std::string phoneNum;
};

#endif // SUBSCRIBER_H

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

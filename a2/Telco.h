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

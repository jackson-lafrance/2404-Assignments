#ifndef TELCO_H
#define TELCO_H

#include "Subscriber.h"
#include "defs.h"
#include <string>

class Telco {
public:
  void addSub(std::string phoneNumber);
  void addMsg(std::string srcNum, std::string destNum, int year, int month,
              int day, int hours, int mins);
  void printFrequent(SubscriberType subType);

private:
  std::string name;
  int numSubscribers;
  bool findSub(std::string phoneNum, Subscriber **sub);
};

#endif // TELCO_H

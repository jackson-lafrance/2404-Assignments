#include "Telco.h"
#include <string>

Telco::Telco(const std::string &name) : name_(name), numSubscribers_(0) {};

Telco::~Telco() {
  messages_.cleanup();
  for (int i{0}; i < numSubscribers_; ++i)
    delete subscribers_[i];
};

void Telco::addSub(std::string phoneNumber) {
  if (numSubscribers_ >= MAX_ARR_SIZE || findSub(phoneNumber))
    return;

  subscribers_[numSubscribers_++] = new Subscriber(phoneNumber);
};

void Telco::addMsg(std::string srcNum, std::string destNum, int year, int month,
                   int day, int hours, int mins) {
  Subscriber *src;
  Subscriber *dest;

  if (!findSub(srcNum, &src) && !findSub(destNum, &dest))
    return;

  Msg *msg = new Msg(day, month, year, hours, mins, srcNum, destNum);

  messages_.add(msg);

  if (src != nullptr)
    src->addOutgoing(msg);

  if (dest != nullptr)
    dest->addIncoming(msg);
}

void Telco::printSubscribers() const {
  for (int i{0}; i < numSubscribers_; ++i)
    subscribers_[i]->print();
}

void Telco::printFrequent(SubscriberType subType) const {
  int indexes[MAX_ARR_SIZE];
  int msgAmounts[MAX_ARR_SIZE];

  for (int i = 0; i < numSubscribers_; ++i) {
    indexes[i] = i;
    msgAmounts[i] = subType == SubscriberType::C_RECEIVER
                        ? subscribers_[i]->inc().size()
                        : subscribers_[i]->out().size();
  }

  selectionSort(numSubscribers_, msgAmounts, indexes);

  for (int i = 0; i < numSubscribers_; ++i) {
    std::cout << "subscriber: " << subscribers_[indexes[i]]->phoneNum()
              << std::endl;
    subType == SubscriberType::C_RECEIVER
        ? subscribers_[indexes[i]]->inc().print()
        : subscribers_[indexes[i]]->out().print();
  }
}

bool Telco::findSub(std::string phoneNum, Subscriber **sub) {
  for (int i{0}; i < numSubscribers_; ++i)
    if (subscribers_[i]->phoneNum() == phoneNum) {
      *sub = subscribers_[i];
      return true;
    }

  return false;
}

bool Telco::findSub(std::string phoneNum) {
  for (int i{0}; i < numSubscribers_; ++i)
    if (subscribers_[i]->phoneNum() == phoneNum)
      return true;

  return false;
}

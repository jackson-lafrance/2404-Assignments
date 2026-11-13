#include "Telco.h"
#include "ExternMsg.h"
#include "InternMsg.h"
#include <iostream>
#include <string>

Telco::Telco(const std::string &name) : name_(name) {};

Telco::~Telco() {
  messages_.cleanup();
  subs_.cleanup();
};

void Telco::addSub(const std::string &phoneNumber) {
  if (subs_.size() >= MAX_ARR_SIZE || findSub(phoneNumber))
    return;

  subs_.add(new Subscriber(phoneNumber));
};

void Telco::addMsg(const std::string &src_num, const std::string &dest_num,
                   int year,
                   int month, int day, int hours, int mins) {
  Subscriber *src_sub = nullptr;
  Subscriber *dest_sub = nullptr;
  Msg *msg = nullptr;

  if (findSub(src_num, &src_sub) && findSub(dest_num, &dest_sub))
    msg = new InternMsg(day, month, year, hours, mins, src_sub, dest_sub);
  else
    msg = new ExternMsg(day, month, year, hours, mins, src_num, dest_num);

  if (msg == nullptr)
    return;

  messages_.add(msg);
}

void Telco::printMessages() const {
  std::cout << "TELCO " << name_ << " MESSAGES:" << std::endl;
  messages_.print();
}

void Telco::printSubscribers() const {
  std::cout << "TELCO " << name_ << " SUBSCRIBERS:" << std::endl;

  for (int i = 0; i < subs_.size(); ++i) {
    Subscriber *subscriber = subs_.get(i);
    MsgList subscriberMessages;

    subscriberMessages.copySubset(subscriber->phoneNum(), messages_);
    subscriber->print();
    subscriberMessages.print();
  }
}

void Telco::printByActivity() const {
  std::cout << "==> MOST ACTIVE SUBSCRIBERS:" << std::endl;

  int indexes[MAX_ARR_SIZE];
  int totals[MAX_ARR_SIZE];
  MsgList activityLists[MAX_ARR_SIZE];

  for (int i = 0; i < subs_.size(); ++i) {
    indexes[i] = i;
    activityLists[i].copySubset(subs_.get(i)->phoneNum(), messages_);
    totals[i] = static_cast<int>(activityLists[i].size());
  }

  selectionSort(subs_.size(), totals, indexes);

  for (int i = 0; i < subs_.size(); ++i) {
    Subscriber *subscriber = subs_.get(indexes[i]);
    std::cout << "Subscriber " << subscriber->phoneNum() << ":"
              << std::endl;
    activityLists[indexes[i]].print();
  }
}

void Telco::printFrequent(SubscriberType subType) const {
  if (subType == SubscriberType::C_SENDER)
    std::cout << "==> MOST FREQUENT SENDING SUBSCRIBERS:" << std::endl;
  else
    std::cout << "==> MOST FREQUENT RECEIVING SUBSCRIBERS:" << std::endl;

  int indexes[MAX_ARR_SIZE];
  int totals[MAX_ARR_SIZE];
  MsgList frequentLists[MAX_ARR_SIZE];

  for (int i = 0; i < subs_.size(); ++i) {
    indexes[i] = i;

    if (subType == SubscriberType::C_SENDER)
      frequentLists[i].copySources(subs_.get(i)->phoneNum(), messages_);
    else
      frequentLists[i].copyDestinations(subs_.get(i)->phoneNum(), messages_);

    totals[i] = static_cast<int>(frequentLists[i].size());
  }

  selectionSort(subs_.size(), totals, indexes);

  for (int i = 0; i < subs_.size(); ++i) {
    Subscriber *subscriber = subs_.get(indexes[i]);

    if (subType == SubscriberType::C_SENDER)
      std::cout << "FROM: ";
    else
      std::cout << "TO: ";

    std::cout << subscriber->phoneNum() << ":" << std::endl;
    frequentLists[indexes[i]].printSimple();
  }
}

bool Telco::findSub(const std::string &phoneNum, Subscriber **sub) {
  *sub = nullptr;

  for (int i = 0; i < subs_.size(); ++i)
    if (subs_.get(i)->phoneNum() == phoneNum) {
      *sub = subs_.get(i);
      return true;
    }

  return false;
}

bool Telco::findSub(const std::string &phoneNum) {
  for (int i = 0; i < subs_.size(); ++i)
    if (subs_.get(i)->phoneNum() == phoneNum)
      return true;

  return false;
}

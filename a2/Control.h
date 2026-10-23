#ifndef CONTROL_H
#define CONTROL_H

#include "Telco.h"

class Control {
public:
  void launch();

private:
  void initData(Telco *telco);
  void initSubscribers(Telco *telco);
  void initMsgs(Telco *telco);
};

#endif // CONTROL_H

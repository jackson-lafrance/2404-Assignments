#ifndef CONTROL_H
#define CONTROL_H

#include "Telco.h"
#include "View.h"

class Control {
public:
  Control();
  ~Control();
  void launch();

private:
  void initData(Telco *telco);
  void initSubscribers(Telco *telco);
  void initMsgs(Telco *telco);

  Telco* telco_;
  View view_;
};

#endif // CONTROL_H

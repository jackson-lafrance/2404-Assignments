/*
 * Class: Control
 * Purpose: Controls the program flow and communication between the telco and the user
 *
 * Data members:
 *   telco_ - Pointer to the telco being managed
 *   view_  - View object used for user input and output
 *
 * Member functions:
 *   Control()         - Dynamically allocates the telco
 *   ~Control()        - Cleans up the telco
 *   launch()          - Initializes the data and controls the main menu
 *   initData()        - Initializes all the telco data
 *   initSubscribers() - Initializes the telco subscribers
 *   initMsgs()        - Initializes the telco messages
 */
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

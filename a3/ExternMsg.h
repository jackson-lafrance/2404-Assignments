#ifndef EXTERN_MSG_H
#define EXTERN_MSG_H

#include "Msg.h"

class ExternMsg : public Msg {
public:
  ExternMsg(int day = 5, int month = 6, int year = 2007, int hours = 10,
            int mins = 30, const std::string &src = "613-324-8204",
            const std::string &dest = "613-721-3331");

  // why are we using virtual at the start instead of override at the end
  // which makes it clear that this is the sub classes function
  virtual std::string src() const;
  virtual std::string dest() const;
  virtual void print() const;

private:
  std::string src_;
  std::string dest_;
};

#endif // EXTERN_MSG_H

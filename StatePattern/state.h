#ifndef state_h
#define state_h
#include <iostream>

class IContext;

class IState {
    public:
        virtual void set_context(IContext *alarm) = 0;
        virtual ~IState() {
  }
};

class AlarmState : public IState {
 protected:
    Alarm *alarm_;

 public:
  virtual ~AlarmState() {
  }

  virtual void set_context(Alarm *alarm) {
    this->alarm_ = alarm;
  }

  virtual void activate(int hh, int mm, Alarm* alarm) = 0;
  virtual void verifyTime(Alarm* alarm) = 0;
  virtual void pause(int hh, int mm, Alarm* alarm) = 0;
  virtual void desactivate(Alarm* alarm) = 0;

};

#endif // state_h

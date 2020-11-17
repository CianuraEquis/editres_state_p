#ifndef context_h
#define context_h
#include <typeinfo>
#include "state.h"

class IContext {
 public:
  virtual void TransitionTo(IState *alarmstate) = 0;

  virtual ~IContext(){};
};

class Alarm : public IContext {
 private:
  AlarmState *alarmstate_;
  int hour;
  int minutes;

 public:
  Alarm(IState *alarmstate) : alarmstate_(nullptr) {
    this->TransitionTo(alarmstate);
  }
  virtual ~Alarm() {
    delete alarmstate_;
  }

  virtual void TransitionTo(IState *alarmstate) {
    std::cout << "Context: Transition to " << typeid(*alarmstate).name() << ".\n";
    if (this->alarmstate_ != nullptr)
      delete this->alarmstate_;
    this->alarmstate_ = alarmstate;
    this->alarmstate_->set_context(this);
  }

    virtual void set_time(int h, int mm){
        hour = h;
        minutes = mm;
    }

    virtual int get_hour(){
        return hour;
    }
    virtual int get_minutes(){
        return minutes;
    };

  void activate(int h, int mm) {
      hour = h;
      minutes = mm;
      this->alarmstate_->activate(hour, minutes, this);
  }
  void verifyTime() {
    this->alarmstate_->verifyTime(this);
  }
};

#endif


#ifndef concretestates_h
#define concretestates_h
#include "state.h"

class Activated : public AlarmState {
 public:

  virtual void startRinging(){
    std::cout<<"RIIIIIIIINGGGGGGGGGGG!!!!"<<std::endl;
    this->alarm_->TransitionTo(new Ringning);
    }
  };

  virtual void verifyDateTime(Alarm* alarm){
    this->alarm_->set_hour();
    this->alarm_->set_minute();
  }
};

class Desactivated : public AlarmState {
 public:
    virtual void activate(Alarm* alarm, int h, int mm){
        this->alarm_ = alarm;
        this->alarm_->hour = h;
        this->alarm_->minutes = mm;
        this->alarm_->TransitionTo(new Activated);
    }
};

class Ringing : public AlarmState {
 public:
    virtual void desactivate(Alarm* alarm){
        this->alarm_ = alarm;
        this->alarm_->TransitionTo(new Desactivated);
    }

    virtual void pause(int mm, Alarm* alarm){
        this->alarm_ = alarm;
        this->minutes = mm;
    }
};





void Ringing::Handle1() {
    std::cout << "ConcreteStateA handles request1.\n";
    std::cout << "ConcreteStateA wants to change the state of the context.\n";

    this->alarm_->TransitionTo(new ConcreteStateB);
  }
}

#endif

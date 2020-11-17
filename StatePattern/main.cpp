#include "context.h"
#include "concretestates.h"
#include <time.h>

int main() {
  Alarm *alarm = new Alarm(new Desactivated);
  alarm->Request1();
  alarm->Request2();
  delete alarm;
  return 0;
}

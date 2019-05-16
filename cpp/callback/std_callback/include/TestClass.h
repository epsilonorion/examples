#include "EventHandler.h"

class TestClass
{
public:
  TestClass();

  void ConfigureCallback();
  void Callback(int x);

private:
  int private_x;
  EventHandler *handler;
};

#include <functional>
#include <iostream>
#include <thread>

class EventHandler
{
public:
  EventHandler();

  void AddHandler(std::function<void(int)> callback);

private:
  std::function<void(int)>_callback;

  std::thread callbackThread;

  void ThreadRunner();
};

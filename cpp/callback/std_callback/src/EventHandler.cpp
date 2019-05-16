#include "EventHandler.h"
#include <iostream>
#include <chrono>         // Used for this_thread sleep_for

EventHandler::EventHandler()
{
  callbackThread = std::thread( &EventHandler::ThreadRunner, this );
}

void EventHandler::AddHandler(std::function<void(int)> callback)
{
  std::cout << "Handler added..." << std::endl;

  _callback = callback;
}

void EventHandler::ThreadRunner()
{
  while (true)
  {
    if (_callback)
    {
      _callback(1);
    }

    std::cout << "Looping" << std::endl;

    std::this_thread::sleep_for(std::chrono::microseconds(1000000));
  }
}

#include <vector>

#ifndef STACKTEMPLATE_H
#define STACKTEMPLATE_H

template <class T>
class Stack
{
private:
  std::vector<T> elements;

public:
  void push(T const &);
  void pop();
  T top();
  bool empty();
};

template <class T>
void Stack<T>::push(T const &elem)
{
    elements.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
  if (elements.empty())
  {
    throw std::out_of_range("Stack<>::pop(): empty stack");
  }
  else
  {
     elements.pop_back();
  }
}

template <class T>
T Stack<T>::top()
{
  if (empty())
  {
    throw std::out_of_range("Stack<>::top(): empty stack");
  }
  return elements.back();
}

template <class T>
bool Stack<T>::empty()
{
  return elements.empty();
}


#endif

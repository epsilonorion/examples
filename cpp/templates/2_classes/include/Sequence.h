#ifndef SEQUENCETEMPLATE_H
#define SEQUENCETEMPLATE_H

template <class T, int N>
class Sequence
{
  T memblock [N];
public:
  void setmember (int x, T value);
  T getmember (int x);
};

template <class T, int N>
void Sequence<T,N>::setmember (int x, T value)
{
  memblock[x]=value;
}

template <class T, int N>
T Sequence<T,N>::getmember (int x)
{
  return memblock[x];
}

#endif

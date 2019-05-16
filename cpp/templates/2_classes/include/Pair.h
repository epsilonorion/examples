#ifndef PAIRTEMPLATE_H
#define PAIRTEMPLATE_H

template <class T>
class Pair
{
  T a, b;
public:
  Pair (T first, T second)
    {a=first; b=second;}
  T getmax ();
  T getmin ();
};

template <class T>
T Pair<T>::getmax ()
{
  T retval;
  retval = a>b? a : b;
  return retval;
}

template <class T>
T Pair<T>::getmin ()
{
  T retval;
  retval = a<b? a : b;
  return retval;
}

#endif

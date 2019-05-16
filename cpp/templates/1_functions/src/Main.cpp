#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline T const& Max (T const& a, T const& b)  {
  return a < b ? b:a;
}

template<typename T>
T Add(T n1, T n2)
{
  T result;
  result = n1 + n2;

  return result;
}

template<typename T>
double GetAverage(T tArray[], int nElements)
{
  T tSum = T(); // tSum = 0

  for (int nIndex = 0; nIndex < nElements; ++nIndex)
  {
    tSum += tArray[nIndex];
  }

  // Whatever type of T is, convert to double
  return double(tSum) / nElements;
}


int main ()
{
  cout << "*********************************************" << endl;
  cout << "Get maximum of two values" << endl << endl;
  int i = 39;
  int j = 20;
  cout << "Max(i, j): " << Max(i, j) << endl;

  double f1 = 13.5;
  double f2 = 20.7;
  cout << "Max(f1, f2): " << Max(f1, f2) << endl;

  string s1 = "Hello";
  string s2 = "World";
  cout << "Max(s1, s2): " << Max(s1, s2) << endl;

  cout << "*********************************************" << endl;
  cout << "Get addition of two values" << endl << endl;

  cout << "Add(i, j): " << Add(i, j) << endl;

  cout << "Add(f1, f2): " << Add(f1, f2) << endl;


  cout << "*********************************************" << endl;
  cout << "Get average of array of values" << endl << endl;

  int  IntArray[5] = {100, 200, 400, 500, 1000};
  cout << "GetAverage(i, 5): " << GetAverage(IntArray,5) << endl;

  float FloatArray[3] = { 1.55f, 5.44f, 12.36f};
  cout << "GetAverage(f, 3): " << GetAverage(FloatArray,3) << endl;

  return 0;
}

#include <iostream>
#include <vector>

#include "../includes/3DCS_01.h"

using std::cout;
using std::endl;

int main() {
  std::vector<float> v{5.0f, 6.0f, 7.0f};
  CS3D::Vector<float> vect(v);

  vect = vect + vect;

  cout << "Size of vect is " << vect.Size() << endl;
  vect.Print();

  return 0;
}

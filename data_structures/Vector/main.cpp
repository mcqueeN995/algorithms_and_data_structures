#include <iostream>
#include "Vector.h"
#include <cstdlib>

int main() {
  int n;
  std::cin >> n;
  double arr[n];
  for (int i = 0; i < n; i++){
    arr[i] = rand()%100 + 10;
  }
  Vector v1(arr, n, 2.0);
  v1.Print();
  Vector v2(v1);
  v2.Print();
  Vector v3;
  v3 = v1;
  v3.Print();
  std::cout << std::endl;
  std::cout << "vector befor add 5 to end:" << std::endl;
  v3.pushBack(5);
  v3.Print();
  std::cout << std::endl;
  std::cout << "vector after add 6 to front:" << std::endl;
  v3.pushFront(6);
  v3.Print();
  std::cout << std::endl;
  std::cout << "vector after add 7 to 2 pos:" << std::endl;
  v3.insert(71, 2);
  v3.Print();
  std::cout << std::endl;

  double values[] = {2, 3, 4};
  v3.insert(values, 3, 1);
  std::cout << "vector after insert array {2, 3, 4}:" << std::endl;
  v3.Print();

  int k;
  std::cin >> k;
  srand(time(0));
  double *array = new double[n];
  for (int i = 0; i < n; i++){
    array[i] = rand()%100 + 10;
  }

  Vector v4(array, n);
  v4.Print();
  double mass[] = {2, 3, 4};
  Vector v5(mass, 3);
  v4.insert(v5, 2);
  std::cout << "vector after insert Vector {2, 3, 4}:" << std::endl;
  v4.Print();

  v4.popBack();
  std::cout << "vector after popBack:" << std::endl;
  v4.Print();

  v4.popFront();
  std::cout << "vector after popFront:" << std::endl;
  v4.Print();

  std::cout << std::endl;

  v4.erase(2, 3);
  Vector v6(array, n);
  std::cout << "vector after erase:" << std::endl;
  v4.Print();

  v6.erase(3, 9);
  std::cout << "vector after erase [pos, size)" <<  std::endl;
  v6.Print();

  std::cout << std::endl;

  Vector v7(array, n);
  v7.Print();
  std::cout << "vector after eraseBetween:" << std::endl;
  v7.eraseBetween(1, 2);
  v7.Print();

  std::cout << std::endl;

  Vector v8(array, n);
  v8.Print();
  std::cout << "vector after eraseBetween [BeginPos, size):" << std::endl;
  v8.eraseBetween(1, 10);
  v8.Print();

  return 0;
}
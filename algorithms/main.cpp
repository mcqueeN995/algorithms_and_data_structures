#include <iostream>
#include "header.h"

int main(){

	int size;
	std::cin >> size;

	int* array1 = new int[size];

	for (int i = 0; i < size; i++) {
		std::cin >> array1[i];
	}

	int* new_array1 = buble_sort(array1, size);

    std::cout << "Buble sorted array is: ";

	for (int i = 0; i < size; i++) {
		std::cout << new_array1[i] << " ";
	}

	std::cout << std::endl;

//_________________________________________________________________________________________

	int n;
	std::cin >> n;
	int *array2 = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> array2[i];
	}
	array2 = choose_sort(array2, n);

	std::cout << "Choose sorted array is: ";
	for (int i = 0; i < n; i++) {
		std::cout << array2[i] << " ";
	}
	std::cout << std::endl;

//_________________________________________________________________________________________

	std::cin >> n;
    int *array3 = new int[n];
    for (int i = 0; i < n; i++) {
      std::cin >> array3[i];
    }
    array3 = insertion_sort(array3, n);

    std::cout << "Insertion sorted array is: ";
	for (int i = 0; i < n; i++) {
		std::cout << array3[i] << " ";
	}
	std::cout << std::endl;

//_________________________________________________________________________________________

    std::cin >> n;
    int *array4 = new int[n];
    for (int i = 0; i < n; i++) {
      std::cin >> array4[i];
    }
	array4 = quick_sort(array4, n);
   	std::cout << "Quick sorted array is: ";
	for(int i = 0; i < n; i++){
		std::cout<<array4[i]<<" ";
	}
	std::cout << std::endl;

//_________________________________________________________________________________________

    std::cin >> n;
    int *array5 = new int[n];
    for (int i = 0; i < n; i++) {
      std::cin >> array5[i];
    }

    array5 = merge_sort(array5, n);
    std::cout << "Merge sorted array is: ";
    for (int i = 0; i < n; i++) {
      std::cout << array5[i] << " ";
    }
	std::cout << std::endl;

//_________________________________________________________________________________________

    std::cin >> n;
    int *array6 = new int[n];
    for (int i = 0; i < n; i++) {
      std::cin >> array6[i];
    }
    array6 = radix_sort(array6, n);
    std::cout << "Radix sorted array is: ";
    for (int i = 0; i < n; i++) {
      std::cout << array6[i] << " ";
    }
	std::cout << std::endl;


	delete[] array1;
    delete[] array2;
    delete[] array3;
    delete[] array4;
    delete[] array5;
    delete[] array6;
    return 0;
}

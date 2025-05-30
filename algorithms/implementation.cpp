#include <iostream>
#include "header.h"
#include <algorithm>

int* buble_sort(int* array, int size){
	bool flag = true;
	for (int i = 1; i < size; i++){
		for (int j = 0; j < size - 1; j++){
			if (array[j] > array[j + 1]){
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = false;
			}
		}
		if (flag == true){
			std::cout << "array already sorted" << std::endl;
			break;
		}
	}
	return array;
}


int* choose_sort(int* array, int length) {
	for (int i = 0; i < length; i++) {
		int min_index = i;
		for (int j = i + 1; j < length; j++) {
			if (array[j] < array[min_index]) {
				min_index = j;
			}
		}
		std::swap(array[i], array[min_index]);
	}
	return array;
}

int* insertion_sort(int* array, int length) {
	for (int i = 1; i < length; i++) {
		int key = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
	return array;
}

int partition(int* array, int p, int r){
	int x = array[r];
	int i = p - 1;
	for(int j = p; j < r; j++){
		if(array[j] <= x){
			i = i + 1;
			std::swap(array[i], array[j]);
		}
	}
	std::swap(array[i + 1], array[r]);
	return i + 1;
}

void quick_sort_helper(int* arr, int p, int r) {
	if (p < r) {
		int pivot_index = partition(arr, p, r);
		quick_sort_helper(arr, p, pivot_index - 1);
		quick_sort_helper(arr, pivot_index + 1, r);
	}
}

int* quick_sort(int* array, int length){
  quick_sort_helper(array, 0, length - 1);
  return array;
}

void merge(int* array, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1; i++) L[i] = array[left + i];
	for (int j = 0; j < n2; j++) R[j] = array[mid + 1 + j];
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			array[k++] = L[i++];
		} else {
			array[k++] = R[j++];
		}
	}
	while (i < n1) array[k++] = L[i++];
	while (j < n2) array[k++] = R[j++];
	delete[] L;
	delete[] R;
}

void merge_sort(int* array, int left, int right) {
	if (left >= right) return;
	int mid = left + (right - left) / 2;
	merge_sort(array, left, mid);
	merge_sort(array, mid + 1, right);
	merge(array, left, mid, right);
}

int* merge_sort(int* array, int length) {
	merge_sort(array, 0, length - 1);
	return array;
}

int get_max(int* array, int length) {
	return *std::max_element(array, array + length);
}

void counting_sort(int* array, int length, int exp) {
	int* output = new int[length];
	int count[10] = {0};
	for (int i = 0; i < length; i++) {
		int digit = (array[i] / exp) % 10;
		count[digit]++;
	}
	for (int i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}
	for (int i = length - 1; i >= 0; i--) {
		int digit = (array[i] / exp) % 10;
		output[count[digit] - 1] = array[i];
		count[digit]--;
	}
	for (int i = 0; i < length; i++) {
		array[i] = output[i];
	}
	delete[] output;
}


int* radix_sort(int* array, int length) {
	if (length <= 0) return array;
	int max_num = get_max(array, length);
	for (int exp = 1; max_num / exp > 0; exp *= 10) {
		counting_sort(array, length, exp);
	}

	return array;
}


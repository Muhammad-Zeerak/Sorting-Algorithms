#pragma once

#include"swap.cpp"

template <class X>
inline int partition(X arr[], int i, int j, int order) {

	int key = i;
	while (i < j) {
		if (order == 1) {
			while (arr[i] <= arr[key])
				i++;
			while (arr[j] > arr[key])
				j--;
		}
		else {
			while (arr[i] >= arr[key])
				i++;
			while (arr[j] < arr[key])
				j--;
		}
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	swap<X>(&arr[j], &arr[key]);
	return j;
}

template <class X>
inline void quickSort(X arr[], int low, int high, int order) {

	if (low < high) {

		int pivot = partition(arr, low, high, order);
		quickSort(arr, low, pivot - 1, order);
		quickSort(arr, pivot + 1, high, order);
	}
}
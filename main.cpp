#include<iostream>
#include<string>

#include"mergeSort.cpp"
#include"quickSort.cpp"
#include"radixSort.cpp"
#include"selectionSort.cpp"

using namespace std;

template <class X>
void printArray(X arr[], int n) {

	for (int i = 0;i < n;i++)
		cout << arr[i]<<" ";
}

template <class X>
void selectSort() {

	int order, sortType, size;
	cout << "1. Quick sort\n2. Merge sort\n3. Radix sort\n4. Selection sort\n5. All\n\nChoice: ";
	cin >> sortType;
	cout << "1. Ascending\n 2. Descending\n\nChoice: ";
	cin >> order;
	cout << "Enter the size of the array: ";
	cin >> size;

}

int main() {

	/*int choice;
	cout << "1. Long\n2. Float\n3. String\n\nChoice: ";
	cin >> choice;
	switch (choice) {
	case 1:
		selectSort<long>();
		break;
	case 2:
		selectSort<float>();
		break;
	case 3:
		selectSort<string>();
		break;
	default:
		cout << "Invalid choice. Try again.\n";
	} */
	
	int arr[] = {4,2,5,1};
	quickSort(arr, 0, 3, 2);
	printArray(arr, 4);
}


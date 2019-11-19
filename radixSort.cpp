#include <iostream>
#include <list>
#include <time.h>
#include <string>
#define radix 10 // base of decimal number
#define Size 100 // max size

using namespace std;

// for long and float
// for long max = 3 and for float max = 6 in radixSort function as 3rd argument
template <class X>
inline void radixSort(X *arr, int n, int max) // n is size and max is max num of digits in array (1-100 means max is 3 i.e 100)
{
	int i, j, m, p = 1, index, temp, count = 0;
	list<X> list[radix];

	for (i = 0; i < max; i++)
	{
		m = pow(radix, i + 1);
		p = pow(radix, i);

		for (j = 0; j < n; j++)
		{
			temp = (int)arr[j] % m;
			index = temp / p;      //find index for list array
			list[index].push_back(arr[j]);
		}

		count = 0;

		for (j = 0; j < 10; j++)
		{
			//delete from linked lists and store to array
			while (!list[j].empty())
			{
				arr[count] = *(list[j].begin());
				list[j].erase(list[j].begin());
				count++;
			}
		}
	}
}

size_t getMax(string arr[], int n)
{
	size_t max = arr[0].size();
	for (int i = 1; i < n; i++)
	{
		if (arr[i].size() > max)
			max = arr[i].size();
	}
	return max;
}

void countSort(string a[], int size, size_t k)
{
	string* b = NULL; int* c = NULL;
	b = new string[size];
	c = new int[257];

	for (int i = 0; i < 257; i++)
		c[i] = 0;
	for (int j = 0; j < size; j++)
		c[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;

	for (int f = 1; f < 257; f++)
		c[f] += c[f - 1];

	for (int r = size - 1; r >= 0; r--)
	{
		b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
		c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
	}

	for (int l = 0; l < size; l++)
		a[l] = b[l];

	// avold memory leak
	delete[] b;
	delete[] c;
}

void radixSort(string b[], int r)
{
	size_t max = getMax(b, r);
	for (size_t digit = max; digit > 0; digit--)
		countSort(b, r, digit - 1);
}
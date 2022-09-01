#include<stdio.h>

void swap(int* pArray, int i, int j)
{
	int temp = pArray[i];
	pArray[i] = pArray[j];
	pArray[j] = temp;
}

int Partition(int* pArray, int low, int high)
{
	if (pArray == nullptr || low < 0 || high < 1 || low > high) return -1;

	int* array = pArray;
	int privot = array[high], privotIndex = high;
	for (int j = high - 1; j >= low; j--)
	{
		if (array[j] > privot) {
			high--;
			swap(pArray, j, high);
		}
	}
	swap(pArray, high, privotIndex);
	return high;
}

void QuickSort(int* pArray, int low, int high)
{
	if (pArray == nullptr || low < 0 || high < 1 || low > high) return;

	if (low == high) return;

	int newPrivotIndex = Partition(pArray, low, high);
	QuickSort(pArray, low, newPrivotIndex - 1);
	QuickSort(pArray, newPrivotIndex + 1, high);
}

void PrintArray(const char* printDescription, int* array, int length)
{
	printf(printDescription);
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	//array = 0x0093f87c {3, 4, 1, 2}
	int array[8] = {3, 4, 1, 2, 8, 9, 2, 5};
	PrintArray("Original array:\n", array, 8);
	QuickSort(array, 0, 7);
	PrintArray("QuickSort array:\n", array, 8);
	return 0;
}
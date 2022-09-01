#include<stdio.h>
#include<string.h>

#define MAXLEN 1000
static int index = 0;

void PrintStrArray(const char* printDescription, char** pStrArray)
{
	printf(printDescription);
	for (int i = 0; i < index; i++)
	{
		printf("%s\n", pStrArray[i]);
	}
}

void swap(char** i, char** j)
{
	char* temp = *i;
	*i = *j;
	*j = temp;
}

/*
quick sort:
Divide and Conquer sort
*/
int Partition(char** pArray, int low, int high)
{
	if (pArray == nullptr || low < 0 || high < 1 || low == high) return -1;

	char* pivot = pArray[high];
	int pivotIndex = high;
	for (int j = high - 1; j >= low; j--)
	{
		if (strcmp(*(pArray + j), pivot) > 0) {
			high--;
			swap(pArray + j, pArray + high);
		}
	}
	swap(pArray + high, pArray + pivotIndex);
	return high;
}

void SortSuffixArray(char** pStrPointerArray, int low, int high)
{
	if (*pStrPointerArray == nullptr || low < 0 || high < 1 || low > high) return;

	if (low == high) return;

	char* pivot = *(pStrPointerArray + high);
	int newPrivotIndex = Partition(pStrPointerArray, low, high);

	SortSuffixArray(pStrPointerArray, low, newPrivotIndex - 1);
	SortSuffixArray(pStrPointerArray, newPrivotIndex + 1, high);
}

/*
principal:
suffix array
*/

int main()
{
	char str[MAXLEN];
	char* pStrArray[MAXLEN];

	char ch;
	while ((ch = getchar()) != '\n')
	{
		str[index] = ch;
		pStrArray[index] = (str + index);
		index++;
	}
	str[index] = '\0';

	PrintStrArray("Original str array:\n", pStrArray);
	SortSuffixArray(pStrArray, 0, index - 1);
	PrintStrArray("Sort str array:\n", pStrArray);


	return 0;
}

/*
Array 的意思就是 第一个元素的地址
关于指针的一点思考：
本来所有的指针都是存储某一变量的地址，从大小来说的确都是一样的，但是只有大小功能好像有点单薄
所以引入属性，char int只是为了满足 * 取内容的用处，所以强转指针后就意味着属性的改变
*/
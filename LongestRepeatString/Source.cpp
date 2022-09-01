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
Array ����˼���� ��һ��Ԫ�صĵ�ַ
����ָ���һ��˼����
�������е�ָ�붼�Ǵ洢ĳһ�����ĵ�ַ���Ӵ�С��˵��ȷ����һ���ģ�����ֻ�д�С���ܺ����е㵥��
�����������ԣ�char intֻ��Ϊ������ * ȡ���ݵ��ô�������ǿתָ������ζ�����Եĸı�
*/
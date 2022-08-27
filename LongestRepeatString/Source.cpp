#include<stdio.h>
#include<string.h>

#define MAXLEN 1000
static int index = 0;

void PrintStrArray(const char** pStrArray)
{
	for (int i = 0; i < index; i++)
	{
		printf("%s\n", pStrArray[i]);
	}
}

/*
quick sort:
Divide and Conquer sort
*/
int Partition(char** pArray, int low, int high, char* pivot)
{
	char* array = *pArray;
	for (int j = high - 1; j >= low; j--)
	{
		if (strcmp(array + j, pivot) > 0) {
			high--;
			char* temp = array[high];
			*(array + high) = *(array + j);

		}
	}
}

void QuickSort(char** pArray, int low, int high)
{
	char* array = *pArray;
	char* pivot = array + high;
	char* newPivot = Partition()
}

void SortSuffixArray(const char** pStrArray)
{
	for (int i = 0; i < index; i++)
	{
		strcmp((*pStrArray) + i, (*pStrArray));
	}
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

	sort()

	printf("Print suffix array:\n");
	PrintStrArray((const char**)pStrArray);

	return 0;
}

/*
Array ����˼���� ��һ��Ԫ�صĵ�ַ
����ָ���һ��˼����
�������е�ָ�붼�Ǵ洢ĳһ�����ĵ�ַ���Ӵ�С��˵��ȷ����һ���ģ�����ֻ�д�С���ܺ����е㵥��
�����������ԣ�char intֻ��Ϊ������ * ȡ���ݵ��ô�������ǿתָ������ζ�����Եĸı�
*/
#include<stdio.h>

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
principal:
suffix array
*/

int main()
{
	char str[MAXLEN];
	char* pStrArray[MAXLEN];

	char ch;
	while ((ch = getchar()) != EOF)
	{
		str[index++] = ch;
		pStrArray[index++] = &ch;

	}
	str[index] = '\0';

	PrintStrArray((const char**)pStrArray);

	return 0;
}

/*
Array 的意思就是 第一个元素的地址
关于指针的一点思考：
本来所有的指针都是存储某一变量的地址，从大小来说的确都是一样的，但是只有大小功能好像有点单薄
所以引入属性，char int只是为了满足 * 取内容的用处，所以强转指针后就意味着属性的改变
*/
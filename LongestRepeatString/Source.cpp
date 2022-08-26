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
Array ����˼���� ��һ��Ԫ�صĵ�ַ
����ָ���һ��˼����
�������е�ָ�붼�Ǵ洢ĳһ�����ĵ�ַ���Ӵ�С��˵��ȷ����һ���ģ�����ֻ�д�С���ܺ����е㵥��
�����������ԣ�char intֻ��Ϊ������ * ȡ���ݵ��ô�������ǿתָ������ζ�����Եĸı�
*/
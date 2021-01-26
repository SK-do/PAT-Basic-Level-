#include <stdio.h>
#include <string.h>

/*
读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：(1234567890987654321123456789)
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10^100

输出格式：(yi san wu)
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
*/

int main()
{
	char n[200];
	int sum=0,length; 
	int count[100],i=0,j;
	char *str[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	scanf("%s",&n);
	length = strlen(n);
	for(i=0; i<length; i++)
	{
		sum += n[i] - '0';
	}
//	printf("%d", sum);
	while(sum >= 1)
	{
		count[i] = sum%10;
		sum = sum/10;
		i++;
	}
	for(j=i-1; j>0; j--)
	{
		printf("%s ",str[count[j]]);
	}
	printf("%s",str[count[0]]);
	return 0;
}

#include<stdio.h>

/*
让我们用字母 B 来表示“百”、字母 S 表示“十”，用 12...n 来表示不为零的个位数字 n（<10），换个格式来输出任一个不超过 3 位的正整数。例如 234 应该被输出为 BBSSS1234，因为它有 2 个“百”、3 个“十”、以及个位的 4。

输入格式：(234) (23) 
每个测试输入包含 1 个测试用例，给出正整数 n（<1000）。

输出格式：(BBSSS1234) (SS123)
每个测试用例的输出占一行，用规定的格式输出 n。
*/ 

int main()
{
	int n,b,s,g;
//	printf("请输入一个不超过3位的正整数：");
	scanf("%d",&n);
	if(n/1000 >= 1){
		printf("输入错误！");
		return 0;
	}
	else{
		g = n%10;
		n = n/10;
		s = n%10;
		n = n/10;
		b = n;
	}
	for(int i=0; i<b; i++)
		printf("B");
	for(int i=0; i<s; i++)
		printf("S");
	for(int i=0; i<g; i++)
		printf("%d",i+1);
	return 0;
} 

#include<stdio.h>
#include<math.h>

/*
令 Pi表示第 i 个素数。现任给两个正整数 M≤N≤10^4，请输出 Pm到 Pn的所有素数。

输入格式：
输入在一行中给出 M 和 N，其间以空格分隔。
输入样例：
5 27

输出格式：
输出从 Pm到 Pn的所有素数，每 10个数字占 1 行，其间以空格分隔，但行末不得有多余空格。
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/ 

//判断素数
int isPrime(int a)
{
	int t = (int)sqrt(a);
	for(int i=2; i<=t; i++)
	{
		if(a%i == 0)
			return 0;
	}
	return 1;
} 

int main()
{
	int pi[10000];
	int m,n,k=0,j=0;
	if(scanf("%d",&m) <= scanf("%d",&n))
	{
		for(int i=2; k<=n; i++)   //统计素数 p1 - pn 
		{
			if(isPrime(i))  //i是素数
			{
				pi[k] = i; 
				k++;
			}
		}
		for(int i=m-1; i<n-1; i++)  //输出pm - pn 
		{
			j++;  //统计此时输出的素数个数 
			if(j%10 == 0)
				printf("%d\n",pi[i]);
			else
				printf("%d ",pi[i]);
		}
		printf("%d\n",pi[n-1]);
	}
	return 0;
} 

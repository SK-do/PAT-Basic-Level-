#include <stdio.h>
#include <stdlib.h>

/*
给定一个正整数数列，和正整数 p，设这个数列中的最大值是 M，最小值是 m，如果 M≤mp，则称这个数列是完美数列。
现在给定参数 p 和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：
输入第一行给出两个正整数 N 和 p，其中 N（≤10^5）是输入的正整数的个数，p（≤10^9）是给定的参数。
第二行给出 N 个正整数，每个数不超过 10^9。
输入样例：
10 8
2 3 20 4 5 1 6 7 8 9

输出格式：
在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。
输出样例：
8
*/

/*设定i,j记录符合的数组中，当前最小最大值的位置；count记录符合要求的中间数字的个数，初始为0；i从0~n，j从i+count开始，
找到符合要求的j时（M≤mp），计算j-i+1与count的大小，比count大就进行更新。
---大佬的巧妙思路： 
https://blog.csdn.net/zhanshen112/article/details/84783394
*/

//快排的比较函数（升序）
int cmp(const void *a, const void *b)
{
	return (*(double *)a-*(double *)b);
} 

int main()
{
	int N,count=0;  //count记录符合要求的中间数字的个数 
	double p,n[100001];
	int i,j;
	scanf("%d %lf",&N,&p);
	for(i=0; i<N; i++)
		scanf("%lf",&n[i]);
	qsort(n,N,sizeof(n[0]),cmp);  //快排
	for(i=0; i<N; i++)
	{
		for(j=i+count; j<N; j++)
		{
			if(n[j] > n[i]*p)  //M>mp，即不满足完美数列要求
				break;
			if(j-i+1 > count)  //实时更新count值，同时可减少循环次数
				count = j-i+1; 
		}
	} 
	printf("%d\n",count);
	return 0;
} 

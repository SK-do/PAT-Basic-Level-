#include<stdio.h>

/*
正整数 A 的“DA（为 1 位整数）部分”定义为由 A 中所有 DA组成的新整数 PA。
例如：给定 A=3862767，DA=6，则 A 的“6 部分”PA是 66，因为 A 中有 2 个 6。
现给定 A、DA、B、DB，请编写程序计算 PA +PB。

输入格式：(3862767 6 13530293 3) (3862767 1 13530293 8)
输入在一行中依次给出 A、DA、B、DB，中间以空格分隔，其中 0<A,B<10^10。

输出格式：(399) (0)
在一行中输出 PA+PB的值。
*/ 

int main()
{
	int A,Da,B,Db,Pa=0,Pb=0;
	int a=1,b=1;
	if(scanf("%d",&A)>0 && scanf("%d",&Da)<10 && scanf("%d",&B)>0 && scanf("%d",&Db)<10)
	{
		while(A > 0)
		{
			if((A%10) == Da)
			{
				Pa = Pa+Da*a;
				a *= 10;
			} 
			A /= 10;
		}
		while(B > 0)
		{
			if((B%10) == Db)
			{
				Pb = Pb+Db*b;
				b *= 10;
			} 
			B /= 10;
		}
	}
	printf("%d\n",Pa+Pb); 
	return 0;
} 

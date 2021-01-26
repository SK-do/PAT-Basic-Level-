#include<stdio.h>

/*
输入两个非负 10 进制整数 A 和 B (≤2^30-1)，输出 A+B 的 D (1<D≤10)进制数。

输入格式：(123 456 8)
输入在一行中依次给出 3 个整数 A、B 和 D。

输出格式：(1103)
输出 A+B 的 D 进制数。
*/ 

int main()
{
	int a,b,sum,D,res[1000],i=0,j;
	if(scanf("%d",&a)>0 && scanf("%d",&b)>0 && scanf("%d",&D)<=10)
	{
		sum = a+b;
//		while(sum > 0)  //测试点3未过  ！未考虑 0 0 任意进制  输出为0 的情况！ 
//		{
//			res[i++] = sum%D;
//			sum /= D;			
//		} 
		do
		{
			res[i++] = sum%D;
			sum /= D;
		}while(sum > 0);
		for(j=i-1; j>=0; j--)
			printf("%d",res[j]);
		printf("\n");
	}
	return 0;
} 

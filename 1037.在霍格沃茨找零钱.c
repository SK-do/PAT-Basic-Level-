#include <stdio.h>

/*
如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：
“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”
现在，给定哈利应付的价钱 P 和他实付的钱 A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：(10.16.27 14.1.28) (14.1.28 10.16.27)
输入在 1 行中分别给出 P 和 A，格式为 Galleon.Sickle.Knut，其间用 1 个空格分隔。
这里 Galleon 是 [0, 10^7] 区间内的整数，Sickle 是 [0, 17) 区间内的整数，Knut 是 [0, 29) 区间内的整数。

输出格式：(3.2.1) (-3.2.1)
在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。
*/ 

void pay(int ag,int as,int ak,int bg,int bs,int bk)
{
	int g,s,k;
	if(ak >= bk)  //计算应找的纳特（Knut） 
	{
		k = ak-bk;		
	}
	else
	{
		k = ak+29-bk;
		as--;
	}
	if(as >= bs)  //计算应找的西可（Sickle）
	{
		s = as-bs;
	} 
	else
	{
		s = as+17-bs;
		ag--;
	}
	g = ag-bg;
	printf("%d.%d.%d\n",g,s,k);
} 

int main()
{
	int pg,ps,pk,ag,as,ak;
	int i,j;
	scanf("%d.%d.%d %d.%d.%d",&pg,&ps,&pk,&ag,&as,&ak);
	if(pg<ag || (pg==ag && ps<as) || (pg==ag && ps==as && pk<=ak))  //钱足够支付 
		pay(ag,as,ak,pg,ps,pk);
	else  //没带够钱，输出负数 
	{
		printf("-");
		pay(pg,ps,pk,ag,as,ak); 
	}
	return 0;
}

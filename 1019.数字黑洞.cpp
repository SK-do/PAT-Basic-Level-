#include<stdio.h>

/*
给定任一个各位数字不完全相同的 4 位正整数，如果我们先把 4 个数字按非递增排序，再按非递减排序，然后用第 1 个数字减第 2 个数字，将得到一个新的数字。
一直重复这样做，我们很快会停在有“数字黑洞”之称的 6174，这个神奇的数字也叫 Kaprekar 常数。
例如，我们从6767开始，将得到
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...
现给定任意 4 位正整数，请编写程序演示到达黑洞的过程。

输入格式：
输入给出一个 (0,10^4) 区间内的正整数 N。
输入样例 1：
6767
输入样例 2：
2222

输出格式：
如果 N 的 4 位数字全相等，则在一行内输出 N - N = 0000；否则将计算的每一步在一行内输出，直到 6174 作为差出现，输出格式见样例。
注意每个数字按 4 位数格式输出。
输出样例 1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输出样例 2：
2222 - 2222 = 0000
*/ 

//非递增排序
int increase(int n)
{
	int z[4]={0}, i=0, max, res;
	while(n > 0)
	{
		z[i++] = n%10;
		n = n/10;
	} 
	for(int a=0; a<4; a++)
	{			
		max = z[3];
		for(int b=2; b>=a; b--)
		{
			if(z[b] >= max)
				max = z[b];
			else
			{
				z[b+1] = z[b];
				z[b] = max;
			}
		}
	}
	res = z[0]*1000+z[1]*100+z[2]*10+z[3];
	return res;
} 

//非递减排序 
int decrease(int n)
{
	int d[4]={0}, i=0, min, res;
	while(n > 0)
	{
		d[i++] = n%10;
		n = n/10;
	} 
	for(int a=0; a<4; a++)
	{			
		min = d[3];
		for(int b=2; b>=a; b--)
		{
			if(d[b] <= min)
				min = d[b];
			else
			{
				d[b+1] = d[b];
				d[b] = min;
			}
		}
	}
	res = d[0]*1000+d[1]*100+d[2]*10+d[3];
	return res;
}

int main()
{
	int n,z,d,res=0;
	if(scanf("%d",&n) < 10000)
	{
		z = increase(n);
		d = decrease(n);
		while(res != 6174)
		{
			res = z-d;
			printf("%04d - %04d = %04d\n",z,d,res);
			z = increase(res);
			d = decrease(res);
			if(res == 0)
				return 0;
		}
	}
	return 0;
} 

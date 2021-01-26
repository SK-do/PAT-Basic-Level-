#include<stdio.h>
#include<math.h> 

/*
让我们定义dn为：dn = Pn+1-Pn,其中Pi是第i个素数。显然有d1 = 1，且对于n>1有dn是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
现给定任意正整数N(<10^5)，请计算不超过N的满足猜想的素数对的个数。

输入格式:(20) 
输入在一行给出正整数N。

输出格式:(4)
在一行中输出不超过N的满足猜想的素数对的个数。
*/

//判断一个数是否为素数
int isPrime(int a)
{
	int i;
	int k = (int)sqrt(a);
	for(i=2; i<=k; i++)
	{
		if(a%i == 0)   //不只被1和自身整除 
			return 0;
	}
	return 1;
} 

int main()
{
	int n,count=0;  //count记录满足猜想的素数对个数
	int i; 
	if(scanf("%d",&n) > 0)
	{
		for(i=5; i<=n; i=i+2)  //2为素数 
		{
			if(isPrime(i) && isPrime(i-2))  //相邻且差为2的素数 
			{
//				printf("%d %d\n",i,i-2);
				count++;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}

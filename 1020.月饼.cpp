#include<stdio.h>
#include<stdlib.h>

/*
现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。
注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有 3 种月饼，其库存量分别为 18、15、10 万吨，总售价分别为 75、72、45 亿元。
如果市场的最大需求量只有 20 万吨，那么我们最大收益策略应该是卖出全部 15 万吨第 2 种月饼、以及 5 万吨第 3 种月饼，获得 72 + 45/2 = 94.5（亿元）。

输入格式：
每个输入包含一个测试用例。
每个测试用例先给出一个不超过 1000 的正整数 N 表示月饼的种类数、以及不超过 500（以万吨为单位）的正整数 D 表示市场最大需求量。
随后一行给出 N 个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出 N 个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。
输入样例：
3 20
18 15 10
75 72 45

输出格式：
对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后 2 位。
输出样例：
94.50
*/

//需求量可能为0，也可能大于所有月饼的总库存量 

int main()
{
	//n为月饼种类数，d为市场最大需求量，k[]为库存量，s[]为总售价，m[]为单价 
	int n,index;
	float d,k[1001],s[1001],m[1001],m2[1001],max,money=0.00;
	if(scanf("%d",&n)<=1000 && scanf("%f",&d)<=500) 
	{
		for(int i=0; i<n; i++)
			if(scanf("%f",&k[i])>=0);
		for(int i=0; i<n; i++)
			if(scanf("%f",&s[i])>=0);
		for(int i=0; i<n; i++)  //计算出每种月饼的单价 
		{
			if(k[i] > 0)
			{
				m[i] = s[i]/k[i];
				m2[i] = s[i]/k[i];
			}
			else
			{
				m[i] = 0.00;
				m2[i] = 0.00;				
			}
		}
//		for(int i=0; i<n; i++)
//			printf("%f ",m[i]);
		for(int i=0; i<n; i++)   
		{
			max = m[n-1];
			for(int j=n-2; j>=i; j--)  //依次找到单价最高的月饼种类并计算收益
			{
				if(m[j] >= max)
				{
					max = m[j];
				}
				else 
				{
					m[j+1] = m[j];
					m[j] = max;
				} 
			}
			for(int a=0; a<n; a++)  //记录最高单价的原本下标，以便定位对应库存量和总售价 
			{
				if(max == m2[a])
					index = a;
			}
			if(d>0 && k[index]>0)
			{
				if(k[index] >= d)  //库存大于需求量时，收益=需求量*单价 
				{
					money += d*m[i];
//					printf("1、index=%d,%.2f,d=%.2f\n",index,money,d); 
				}
				else  //库存小于需求量时，收益=总售价 
				{
					money += (float)s[index];
//					printf("2、index=%d,%.2f,d=%.2f\n",index,money,d); 
				} 
			}	
			else
			{				
				printf("%.2f\n",money); 
				return 0;
			}			
			d -= k[index];
		}
		printf("%.2f\n",money); 
	}
	return 0;
} 

/*
//结构体
typedef struct MCake{
	float num;  //月饼库存量 
	float account;  //月饼总售价
	float price;  //月饼单价 
}MoonCake;

//快排所需的比较函数 
int cmp(const void *a, const void *b)
{
	MCake *aa = (MCake *)a;
	MCake *bb = (MCake *)b;
	return (((bb->price)>(aa->price))?1:-1);
}

int main()
{
	MoonCake cake[1001];
	int n;  //n为月饼种类数 
	float d,money=0.00;  //d为市场最大需求量 
	if(scanf("%d",&n)<=1000 && scanf("%f",&d)<=500) 
	{
		for(int i=0; i<n; i++)
			scanf("%f",&cake[i].num);
		for(int i=0; i<n; i++)
			scanf("%f",&cake[i].account);
		for(int i=0; i<n; i++)  //计算每种月饼的单价（亿元/万吨） 
		{
			if(cake[i].num > 0)
				cake[i].price = cake[i].account/cake[i].num;
			else
				cake[i].price = 0.00;
		}
		
		qsort(cake,n,sizeof(cake[0]),cmp);  //快排
		
		for(int i=0; i<n; i++)
		{
			if(d > 0)
			{
				if(d >= cake[i].num)
					money += cake[i].account;
				else
					money += d*cake[i].price;				
				d -= cake[i].num;
			}
			else
			{
				printf("%.2f\n",money);
				return 0;
			}
		} 
		printf("%.2f\n",money);
	}
	return 0;
} 
*/

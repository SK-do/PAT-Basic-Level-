#include<stdio.h>

/*
给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：
A1 = 能被 5 整除的数字中所有偶数的和；
A2 = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n1-n2+n3-n4...; 
A3 = 被 5 除后余 2 的数字的个数；
A4 = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
A5 = 被 5 除后余 4 的数字中最大数字。

输入格式：(13 1 2 3 4 5 6 7 8 9 10 20 16 18) (8 1 2 4 5 6 7 9 16)
每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。

输出格式：(30 11 2 9.7 9) (N 11 2 N 9)
对给定的 N 个正整数，按题目要求计算 A1 ~ A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出 N。
*/ 

int main()
{
	int n,num[1000];
	int a1[1000],a2[1000],a3[1000],a4[1000],a5[1000];
	int count1=0,count2=0,count3=0,count4=0,count5=0;
	if(scanf("%d",&n) <= 1000)
	{
		for(int i=0; i<n; i++)
		{
			if(scanf("%d",&num[i]) <= 1000);
			{
				if(num[i]%5 == 0)
				{
					a1[count1] = num[i];
					count1++;
				}
				if(num[i]%5 == 1)
				{
					a2[count2] = num[i];
					count2++;
				}
				if(num[i]%5 == 2)
				{
					a3[count3] = num[i];
					count3++;
				}
				if(num[i]%5 == 3)
				{
					a4[count4] = num[i];
					count4++;
				}
				if(num[i]%5 == 4)
				{
					a5[count5] = num[i];
					count5++;
				}
			}
		}
	}
	//1、能被5整除的数字中所有偶数的和
	int even_sum=0; 
	for(int i=0; i<count1; i++)
	{
		if(a1[i]%2 == 0)
			even_sum += a1[i];
	}
	//可能有奇数存在 
	if(even_sum == 0)
		printf("N ");
	else
		printf("%d ",even_sum);
	
	//2、将被5除后余1的数字按给出顺序进行交错求和，即计算 n1-n2+n3-n4...
	int sum=0;
	for(int i=0; i<count2; i++)
	{
		if((i+1)%2 == 0)
			sum -= a2[i];
		else
			sum += a2[i];
	}
	//交错求和的值可能为0 
	if(count2 == 0)
		printf("N ");
	else
		printf("%d ",sum);
	
	//3、被5除后余2的数字的个数 -- count3
	if(count3 == 0)
		printf("N ");
	else
		printf("%d ",count3);
	
	//4、被5除后余3的数字的平均数，精确到小数点后1位
	int ave=0;
	double average;
	for(int i=0; i<count4; i++)
	{
		ave += a4[i];
	}
//	printf("\nave=%d,count4=%d\n",ave,count4);
	average = (double)ave/count4;
	if(count4 == 0)
		printf("N ");
	else
		printf("%.1lf ",average);
	
	//5、被5除后余4的数字中最大数字 
	int max=a5[0];
	for(int i=1; i<count5; i++)
	{
		if(a5[i] > max)
			max = a5[i];
	}
	if(count5 == 0)
		printf("N\n");
	else
		printf("%d\n",max);
	return 0;
} 

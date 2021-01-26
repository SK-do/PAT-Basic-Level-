#include<stdio.h>
#include<string.h>

/*
请编写程序统计每种不同的个位数字出现的次数。例如：给定 N=100311，则有 2 个 0，3 个 1，和 1 个 3。

输入格式：
每个输入包含 1 个测试用例，即一个不超过 1000 位的正整数 N。
输入样例：
100311

输出格式：
对 N 中每一种不同的个位数字，以 D:M 的格式在一行中输出该位数字 D 及其在 N 中出现的次数 M。要求按 D 的升序输出。
输出样例：
0:2
1:3
3:1
*/ 

int main()
{
	char num[1001];  //输入不超过1000位的正整数 -- 只能转化成字符串输入 
	int len, M[10]={0},i;
	scanf("%s",num);
	len = strlen(num);
//	printf("%s %d\n",num,len);
	for(i=0; i<len; i++)
	{
//		switch (num[i]){
//			case '0':	M[0]++;    break;
//			case '1':	M[1]++;    break;
//			case '2':	M[2]++;    break;
//			case '3':	M[3]++;    break;
//			case '4':	M[4]++;    break;
//			case '5':	M[5]++;    break;
//			case '6':	M[6]++;    break;
//			case '7':	M[7]++;    break;
//			case '8':	M[8]++;    break;
//			case '9':	M[9]++;    break;			
//		}
		M[num[i]-'0']++;
	}
	for(i=0; i<=9; i++)
	{
		if(M[i] != 0)
			printf("%d:%d\n",i,M[i]);
	}
	return 0;
}

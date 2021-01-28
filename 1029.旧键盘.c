#include <stdio.h>
#include <string.h> 

/*
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

输入格式：
输入在 2 行中分别给出应该输入的文字、以及实际被输入的文字。题目保证 2 个字符串均非空。
每段文字是不超过 80 个字符的串，由字母 A-Z（包括大、小写）、数字 0-9、以及下划线 _（代表空格）组成。
输入样例：
7_This_is_a_test
_hs_s_a_es

输出格式：
按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有 1 个坏键。
输出样例：
7TI
*/
 
int main()
{
	char a[81],b[81],res[81],r[81];
	int len_a,len_b,i,j, t=0, k=0, flag=0;
	scanf("%s",a);
	scanf("%s",b);
	len_a = strlen(a);
	len_b = strlen(b);
	for(i=0; i<len_a; i++)  //找出所有坏键 
	{
		flag = 0; 
		for(j=0; j<len_b; j++)
		{
			if(a[i] == b[j])
				flag = 1;
		}
		if(flag == 0)
			r[t++] = a[i];
	}
//	printf("len_a=%d,len_b=%d,t=%d\n",len_a,len_b,t);
	res[k++] = r[0];
	for(i=1; i<t; i++)  //r[]去重 
	{
		flag = 0;
		for(j=0; j<k; j++)
		{
			if(r[i]==res[j])  //有相同字符 
				flag = 1;
			if(r[i]>=65 && r[i]<=90 && r[i]+32==res[j])  //r[]的大写字母在res[]中有相同的小写字母 
				flag = 1;
			if(r[i]>=97 && r[i]<=122 && r[i]-32==res[j])  //r[]的小写字母在res[]中有相同的大写字母 
				flag = 1;
		} 
		if(flag == 0)
			res[k++] = r[i]; 
	} 
	for(i=0; i<k; i++)
	{
		if((res[i]>='0' && res[i]<='9') || (res[i]>=65 && res[i]<=90))  //0~9,A~Z,直接输出
			printf("%c",res[i]);
		if(res[i]>=97 && res[i]<=122)  //a~z 输出为 A~Z
			printf("%c",res[i]-32);
		if(res[i] == '_')  // _ 代表空格,仍输出为 _
			printf("%c",res[i]);
	}
    printf("\n");
//		printf("%c",res[i]);
	return 0;
} 

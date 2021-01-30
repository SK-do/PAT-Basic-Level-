#include <stdio.h>
#include <string.h>

/*
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。
现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

输入格式：
输入在 2 行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过 10^5个字符的串。
可用的字符包括字母 [a-z, A-Z]、数字 0-9、以及下划线 _（代表空格）、','、'.'、'-'、'+'（代表上档键）。题目保证第 2 行输入的文字串非空。
注意：如果上档键坏掉了，那么大写的英文字母无法被打出。
输入样例：
7+IE.
7_This_is_a_test.

输出格式：
在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。
输出样例：
_hs_s_a_tst
*/

int main()
{
	char fail[100001],in[100001];
	int i,j,len_f,len_in,flag=0;
//	if(scanf("%s",fail) && scanf("%s",in))
	if(gets(fail) && gets(in))  //gets可读取空格 
	{
		len_f = strlen(fail);
		len_in = strlen(in);
		for(i=0; i<len_in; i++)  //遍历输入的文字串 
		{
			flag = 0;
			for(j=0; j<len_f; j++)  //遍历坏键，判断当前文字能否被输出
			{
				if(in[i] == fail[j])  //是坏键不能输出 
				{
					flag = 1;
					continue;
				}
				if(in[i]<='z' && in[i]>='a' && in[i]-32==fail[j])  //字母键坏掉 
				{
					flag = 1;
					continue;
				}
				if(fail[j]=='+' && in[i]<='Z' && in[i]>='A')  //+(上档键)坏掉，不能输出大写字母 
				{
					flag = 1;
					continue;
				}
				if(fail[j]==' ' && in[i]=='_')  //空格键坏掉，不能输出“_ ” 
				{
					flag = 1;
					continue;
				}
			} 
			if(flag == 0)
				printf("%c",in[i]);
		}
		printf("\n");
	}
	return 0;
} 

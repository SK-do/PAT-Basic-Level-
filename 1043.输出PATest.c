#include <stdio.h>

/*
给定一个长度不超过 10^4的、仅由英文字母构成的字符串。请将字符重新调整顺序，按 PATestPATest.... 这样的顺序输出，并忽略其它字符。
当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按 PATest 的顺序打印，直到所有字符都被输出。

输入格式：(redlesPayBestPATTopTeePHPereatitAPPT)
输入在一行中给出一个长度不超过 10^4的、仅由英文字母构成的非空字符串。

输出格式：(PATestPATestPTetPTePePee)
在一行中按题目要求输出排序后的字符串。题目保证输出非空。
*/

int main()
{
	char c;
	int count[127]={0},i;
	while((c=getchar()) != '\n')  //按ASCII码存储输入的各个字符个数 
		count[(int)c]++;
	while(count['P']>0 || count['A']>0 || count['T']>0 || count['e']>0 || count['s']>0 || count['t']>0)  //输出所有的PATest字符 
	{
		if(count['P'] > 0)
		{
			printf("P");
			count['P']--;
		}
		if(count['A'] > 0)
		{
			printf("A");
			count['A']--;
		}
		if(count['T'] > 0)
		{
			printf("T");
			count['T']--;
		}
		if(count['e'] > 0)
		{
			printf("e");
			count['e']--;
		}
		if(count['s'] > 0)
		{
			printf("s");
			count['s']--;
		}
		if(count['t'] > 0)
		{
			printf("t");
			count['t']--;
		}
	} 
	printf("\n");
	return 0;
} 

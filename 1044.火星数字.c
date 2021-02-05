#include <stdio.h>
#include <string.h>

/*
火星人是以 13 进制计数的：
1、地球人的 0 被火星人称为 tret。
2、地球人数字 1 到 12 的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
3、火星人将进位以后的 12 个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字 29 翻译成火星文就是 hel mar；而火星文 elo nov 对应地球数字 115。
为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：
输入第一行给出一个正整数 N（<100），随后 N 行，每行给出一个 [0, 169) 区间内的数字 —— 或者是地球文，或者是火星文。
输入样例：
4
29
5
elo nov
tam

输出格式：
对应输入的每一行，在一行中输出翻译后的另一种语言的数字。
输出样例：
hel mar
may
115
13
*/

//用两个字符数组分离两个火星文，测试点4一直有 运行时错误 ，未找到原因。 
//借鉴大佬思路换成了strncmp函数按位比较。 

int main()
{
	char a[13][5]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};  //保存低位对应的火星文
	char b[13][4]={"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};  //保存高位对应的火星文
	int n,i,j,len,num=0,l_high=0,l_low=0,res=0;
	char c,s[10],high[5],low[5];
	scanf("%d",&n);
	while(getchar()!='\n');  //清除scanf产生的碎片 
	for(i=0; i<n; i++)
	{
//		gets(s);
		c = getchar();
		for(j=0; c!='\n'; j++)
		{
			s[j] = c; 
			c = getchar();
		}
		s[j] = '\0';  //注意需要手动添加字符串结束符
		len = strlen(s);
		if(s[0]>='0' && s[0]<='9')  //输入为地球数字 
		{
			num = 0;
			for(j=0; j<len; j++)  //将字符串转化为数字 
				num = num*10+(s[j]-'0');
//			printf("num = %d\n",num);
			if(num/13 != 0)   //有进位
			{
				if(num%13 == 0)  //整除13
					printf("%s\n",b[num/13]);
				else  //有余数 
					printf("%s %s\n",b[num/13],a[num%13]);
			}
			else if(num%13 != 0)  //没有进位 
				printf("%s\n",a[num%13]);
			else if(num == 0)
				printf("tret\n");
		}
		else  //输入为火星文
		{
			res = 0; 
			if(len == 3)  //只有一个火星文 
			{
				for(j=1; j<13; j++)
				{
					if(strcmp(s,a[j]) == 0)  //是低位 
						res = j;
					if(strcmp(s,b[j]) == 0)  //是高位 
						res = j*13;
				}				
				printf("%d\n",res);
			}
			else if(len == 4)  //为0
				printf("0\n");
			else  //有两个火星文 
			{
				for(j=0; j<13; j++)
				{
					if(strncmp(s,b[j],3) == 0)  //比较字符串前3位 
						res += j*13;
				}
				strcpy(s,&s[4]);  //把第2位复制到第1位处覆盖
				for(j=0; j<13; j++)
				{
					if(strncmp(s,a[j],3) == 0)
						res += j;
				}
//				for(j=0; j<len; j++)  //分离出高位 
//				{
//					if(s[j] != ' ')
//						high[l_high++] = s[j];
//					else
//						break;
//				} 
//				for(j=l_high+1; j<len; j++)  //分离出低位 
//					low[l_low++] = s[j];
//				for(j=0; j<13; j++)
//				{
//					if(strcmp(high,b[j]) == 0)
//						res += j*13;
//					if(strcmp(low,a[j]) == 0)
//						res += j;	
//				}
				printf("%d\n",res);
			} 
		} 
	}
	return 0;
}

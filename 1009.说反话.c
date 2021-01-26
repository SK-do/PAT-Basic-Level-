#include<stdio.h>

/*
给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：(Hello World Here I Come)
测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。

输出格式：(Come I Here World Hello)
每个测试用例的输出占一行，输出倒序后的句子。
*/ 

int main()
{
	//二维数组存储输入的字符串 
	char t[100][100];
	int n=0,count[100];
	int i;
	while(scanf("%s",t[n])!=EOF)
		n++;
	for(i=n-1; i>0; i--)
	{
		printf("%s ",t[i]);
	} 
	printf("%s\n",t[0]); 
	return 0;
} 

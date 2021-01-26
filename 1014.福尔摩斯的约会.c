#include<stdio.h>
#include<string.h>

/*
大侦探福尔摩斯接到一张奇怪的字条：我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间星期四 14:04，
1、因为前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 D，代表星期四；
2、第 2 对相同的字符是 E ，那是第 5 个英文字母，代表一天里的第 14 个钟头（于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 A到N表示）；
3、后面两字符串第 1 对相同的英文字母 s 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。
现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：
输入在 4 行中分别给出 4 个非空、不包含空格、且长度不超过 60 的字符串。
输入样例：
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm

输出格式：
在一行中输出约会的时间，格式为 DAY HH:MM，其中 DAY 是某星期的 3 字符缩写，
即 MON 表示星期一，TUE 表示星期二，WED 表示星期三，THU 表示星期四，FRI 表示星期五，SAT 表示星期六，SUN 表示星期日。
题目输入保证每个测试存在唯一解。
输出样例：
THU 14:04
*/

int main()
{
	char d1[60],d2[60],t1[60],t2[60];
	char day,hour;
	int time,count=0,flag=0;  //flag用于判断是否找到符合条件的第一对字母 
	int len_d1,len_d2,len_t1,len_t2,len1,len2;
	int i;
	scanf("%s %s %s %s",&d1,&d2,&t1,&t2);
	len_d1 = strlen(d1);
	len_d2 = strlen(d2);
	len_t1 = strlen(t1);
	len_t2 = strlen(t2);
//	printf("%d %d ",len_d1,len_d2);
	if(len_d1 >= len_d2)
		len1 = len_d2;
	else
		len1 = len_d1;
	if(len_t1 >= len_t2)
		len2 = len_t2;
	else
		len2 = len_t1;
	for(i=0; i<len1; i++)
	{
		if(d1[i]==d2[i] && flag==0 && d1[i]>='A' && d1[i]<='G')
		{
			day = d1[i];
			flag = 1;
			switch(day){
				case 'A':	printf("MON ");    break;
				case 'B':	printf("TUE ");    break;
				case 'C':	printf("WED ");    break;
				case 'D':	printf("THU ");    break;
				case 'E':	printf("FRI ");    break;
				case 'F':	printf("SAT ");    break;
				case 'G':	printf("SUN ");    break;
			}
			continue;
		}
		if(d1[i]==d2[i] && flag==1)
		{
			if((d1[i]>='A' && d1[i]<='N') || (d1[i]>='0' && d1[i]<='9'))
			{
				hour = d1[i];
				break;
			}
		}
	}
	for(i=0; i<len2; i++)
	{
		if(t1[i] == t2[i])
		{
			if(t1[i]>='A' && t1[i]<='Z')
			{
				time = i;
				break;				
			}
			if(t1[i]>='a' && t1[i]<='z')
			{
				time = i;
				break;				
			}
		}
	}
//	for(int i=0; i<strlen(d); i++)
//		printf("%c ",d[i]);				
//	switch(hour){
//		case '0':	printf("00:");	  break;
//		case '1':	printf("01:");	  break;
//		case '2':	printf("02:");	  break;
//		case '3':	printf("03:");    break;
//		case '4':	printf("04:");	  break;
//		case '5':	printf("05:");	  break;
//		case '6':	printf("06:");	  break;
//		case '7':	printf("07:");	  break;
//		case '8':	printf("08:");	  break;
//		case '9':	printf("09:");	  break;
//		case 'A':	printf("10:");    break;
//		case 'B':	printf("11:");    break;
//		case 'C':	printf("12:");    break;
//		case 'D':	printf("13:");    break;
//		case 'E':	printf("14:");    break;
//		case 'F':	printf("15:");    break;
//		case 'G':	printf("16:");    break;
//		case 'H':	printf("17:");    break;
//		case 'I':	printf("18:");    break;
//		case 'J':	printf("19:");    break;
//		case 'K':	printf("20:");    break;
//		case 'L':	printf("21:");    break;
//		case 'M':	printf("22:");    break;
//		case 'N':	printf("23:");    break;
//	}
	if(hour>='0' && hour<='9')
		printf("0%c:",hour);
	else
		printf("%d:",hour-'A'+10);  //利用ASCII码输出 
	printf("%02d\n",time);   //数据宽度不足2位时用0填补
//	printf("\n%c %c %d\n",day,hour,time);
	return 0;
}

#include<stdio.h>

/*
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 ——只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。
得到“答案正确”的条件是： 
1、字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
2、任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3、如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式：
每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。
输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

输出格式：
每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。 
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO
*/
 
/*要求：
1、只存在'P', 'A', 'T'三种字符；
2、'P', 'T'只能出现一次并且按照该顺序先后出现；
3、P&T之间不能没有A；
4、T之后A的数量 = P之前A的数量 × P&T中间A的数量。
*/ 

int main()
{
	char s;  
	int num;  //需检测的字符串个数
	int i;
	scanf("%d",&num);
	while(getchar() != '\n');  //来清除scanf缓存中的垃圾数据,getchar每次读入一个字符 
	for(i=0; i<num; i++)
	{
		int pos=0,count[3]={0,0,0};  //记录每行字符串的A在不同位置的个数
		while((s=getchar()) != '\n')
		{
			if(s == 'A')  //记录P字符之前的A字符个数 
				count[pos]++;
			else if(s == 'P')  //记录P,T之间的A的个数 
				pos = 1;
			else if(s == 'T')  //记录T之后的A的个数 
				pos = 2; 
			else break;  //出现其他字符 
		} 
		if(s=='\n' && pos==2 && count[1] && count[2]==count[0]*count[1])
			puts("YES");  //puts自带换行符
		else
			puts("NO");
		if(s != '\n')  //清除剩余未读取字符，进入下一行字符串检测 
			while(getchar() != '\n');  		
	}
	return 0;
} 

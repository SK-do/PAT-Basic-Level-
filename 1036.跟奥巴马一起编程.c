#include <stdio.h>

/*
美国总统奥巴马不仅呼吁所有人都学习编程，甚至以身作则编写代码，成为美国历史上首位编写计算机代码的总统。
2014 年底，为庆祝“计算机科学教育周”正式启动，奥巴马编写了很简单的计算机代码：在屏幕上画一个正方形。
现在你也跟他一起画吧！

输入格式：
输入在一行中给出正方形边长 N（3≤N≤20）和组成正方形边的某种字符 C，间隔一个空格。
输入样例：
10 a

输出格式：
输出由给定字符 C 画出的正方形。但是注意到行间距比列间距大，所以为了让结果看上去更像正方形，
我们输出的行数实际上是列数的 50%（四舍五入取整）。
输出样例：
aaaaaaaaaa
a        a
a        a
a        a
aaaaaaaaaa
*/

int main()
{
	float n;
	int a,b,i,j;
	char c;
	if(scanf("%f",&n) && getchar() && scanf("%c",&c))  //getchar读取空格 
	{		
		a = (int)n;
		b = (int)(n/2+0.5);  //四舍五入 
		for(i=0; i<a; i++)  //第一行 j=0
			printf("%c",c);
		printf("\n");
		for(j=1; j<b-1; j++)
		{
			printf("%c",c);
			for(i=1; i<a-1; i++)
				printf(" ");
			printf("%c\n",c);
		}
		for(i=0; i<a; i++)  //第n行 j=n-1 
			printf("%c",c);
		printf("\n");
	}
	return 0;
} 

#include <stdio.h>
#include <stdlib.h>

/*
某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。
这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过 200 岁的老人，而今天是 2014 年 9 月 6 日，
所以超过 200 岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：
输入在第一行给出正整数 N，取值在(0,10^5]；随后 N 行，每行给出 1 个人的姓名（由不超过 5 个英文字母组成的字符串）、
以及按 yyyy/mm/dd（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。
输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20

输出格式：
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。
输出样例：
3 Tom John
*/

//注意：输入的日期可能均不合理，此时只需输出一个 0 即可 

typedef struct{
	char name[5];
	int year,month,day;
}people;

int cmp(const void *a, const void *b)
{
	people *aa = (people *)a;
	people *bb = (people *)b;
	if(aa->year != bb->year)  //不同年出生 
		return (aa->year)-(bb->year);
	else if(aa->month != bb->month)  //不同月出生 
		return (aa->month)-(bb->month);
	else  
		return (aa->day)-(bb->day); 
}

int main()
{
	int n,l=0,i;
	people t,p[100001];
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		scanf("%s %d/%d/%d",t.name,&t.year,&t.month,&t.day);  //name yyyy/mm/dd
		 //超过200岁的生日和未出生的生日不合理 
		if(t.year<2014 && t.year>1814)
			p[l++] = t;
		else if((t.year==2014 && t.month<9) || (t.year==1814 && t.month>9))
			p[l++] = t;
		else if((t.year==2014 && t.month==9 && t.day<=6) || (t.year==1814 && t.month==9 && t.day>=6))
			p[l++] = t;
	}
	qsort(p,l,sizeof(people),cmp);
    if(l > 0)
	    printf("%d %s %s\n",l,p[0].name,p[l-1].name);
    else  //输入的日期均不合理
        printf("%d\n",l);
	return 0;
}

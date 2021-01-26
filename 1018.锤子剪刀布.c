#include<stdio.h>

/*
大家应该都会玩“锤子剪刀布”的游戏：
两人同时给出手势，现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第 1 行给出正整数 N（≤10^5），即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，
即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第 1个字母代表甲方，第 2个代表乙方，中间有1个空格
输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J

输出格式：
输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。
第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解
输出样例：
5 3 2
2 3 5
B B
*/

//计算获胜次数最多的手势
int function(int t[])
{
	int index=0,max=t[0],i;
	for(i=1; i<3; i++)
	{
		if(t[i] > max)
		{
			max = t[i];
			index = i;
		}
	}
	return index;
} 

int main()
{
	int n,more_a[3]={0},more_b[3]={0};  //0-B; 1-C; 2-J
	char a,b,more[3]={'B','C','J'};
	int win_a=0,win_b=0,ave_a=0,ave_b=0,fal_a=0,fal_b=0;
	int i;
	if(scanf("%d",&n) <= 100000)
	{
		for(i=0; i<n; i++)
		{
			while(getchar()!='\n');  //清除scanf的残余数据，不然scanf会读取到换行符 
			scanf("%c %c",&a,&b);
//			printf("%c %c\n",a,b);
			if(a=='C' && b=='J')  //甲方 C 胜 
			{
				win_a++;
				fal_b++;
				more_a[1]++; 
			}
			if(a=='J' && b=='B')  //甲方 J 胜 
			{
				win_a++;
				fal_b++;
				more_a[2]++; 
			}
			if(a=='B' && b=='C')  //甲方 B 胜 
			{
				win_a++;
				fal_b++;
				more_a[0]++; 
			}
			if((a=='C'&&b=='C') || (a=='J'&&b=='J') || (a=='B'&&b=='B'))  //平局
			{
				ave_a++;
				ave_b++;
			} 
			if(a=='J' && b=='C')  //乙方 C 胜 
			{
				win_b++;
				fal_a++;
				more_b[1]++; 
			}
			if(a=='B' && b=='J')  //乙方 J 胜 
			{
				win_b++;
				fal_a++;
				more_b[2]++; 
			}
			if(a=='C' && b=='B')  //乙方 B 胜 
			{
				win_b++;
				fal_a++;
				more_b[0]++; 
			}
		}
	}
	printf("%d %d %d\n",win_a,ave_a,fal_a);
	printf("%d %d %d\n",win_b,ave_b,fal_b);
	printf("%c %c\n",more[function(more_a)],more[function(more_b)]);
	return 0;
} 

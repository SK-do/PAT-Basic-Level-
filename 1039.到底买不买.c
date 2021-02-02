#include <stdio.h>
#include <string.h>

/*
1039 到底买不买 (20分)
小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。
于是小红要你帮忙判断一下，某串珠子里是否包含了全部自己想要的珠子？如果是，那么告诉她有多少多余的珠子；
如果不是，那么告诉她缺了多少珠子。为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。

输入格式：
每个输入包含 1 个测试用例。每个测试用例分别在 2 行中先后给出摊主的珠串和小红想做的珠串，两串都不超过 1000 个珠子。
输入样例 1：
ppRYYGrrYBR2258
YrR8RrY
输入样例 2：
ppRYYGrrYB225
YrR8RrY

输出格式：
如果可以买，则在一行中输出 Yes 以及有多少多余的珠子；如果不可以买，则在一行中输出 No 以及缺了多少珠子。
其间以 1 个空格分隔。
输出样例 1：
Yes 8
输出样例 2：
No 2
*/

int main()
{
	char shop[1001],want[1001];
	int len_s,len_w,succ=0;
	int i,j;
	if(scanf("%s %s",shop,want))
	{
		len_s = strlen(shop);
		len_w = strlen(want);
		for(i=0; i<len_w; i++)  //遍历小红想做的珠串
		{
			for(j=0; j<len_s; j++)  //遍历摊主的珠串
			{
				if(want[i] == shop[j])
				{
					succ++;
					shop[j] = -1;  //将匹配的珠串设为-1，避免后面重复匹配 
					break;
				}
			}  
		} 
		if(succ == len_w)
			printf("Yes %d\n",len_s-succ);
		else
			printf("No %d\n",len_w-succ);
	}
	return 0;
}

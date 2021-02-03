#include <stdio.h>
#include <string.h>

/*
字符串 APPAPT 中包含了两个单词 PAT，其中第一个 PAT 是第 2 位(P)，第 4 位(A)，第 6 位(T)；
第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。现给定字符串，问一共可以形成多少个 PAT？

输入格式：(APPAPT)
输入只有一行，包含一个字符串，长度不超过10^5，只包含 P、A、T 三种字母。

输出格式：(2)
在一行中输出给定字符串中包含多少个 PAT。由于结果可能比较大，只输出对 1000000007 取余数的结果。
*/ 

//本题最后两个测试点数据应该很大，如果直接多重循环求解，会超时，而且必须在统计过程中对10000000007取余！ 
//百度了一下，下面是大佬的思路，超级巧思！ 
/*要想知道构成多少个PAT，那么遍历字符串后对于每一A，它前面的P的个数和它后面的T的个数的乘积就是能构成的PAT的个数。
然后把对于每一个A的结果相加即可，只需要先遍历字符串数一数有多少个T，然后每遇到一个T就countt--;每遇到一个P就countp++;
然后一遇到字母A就立即countt * countp，把这个结果累加到res中，最后别忘记要对10000000007取余！*/ 

int main()
{
	char pat[100001];
	int len,count_p,count_t,res,i;
	count_p=count_t=res=0;
	if(scanf("%s",pat))
	{
		len = strlen(pat);
		for(i=0; i<len; i++)  //先遍历一遍统计输入了多少 T  
		{
			if(pat[i] == 'T')
				count_t++;
		}
		for(i=0; i<len; i++)  //重新遍历字符串，统计每一个 A 前面的 P 和后面的 T 
		{
			if(pat[i] == 'P')
				count_p++;
			if(pat[i] == 'A')  //count_p*count_t为当前的A能构成的PAT个数，累加所有的A构成的PAT即得结果 
				res = (res+count_p*count_t)%1000000007;  //每次计算均需对 1000000007 取余数 
			if(pat[i] == 'T')  // A后面的T = T的总数 - A前面的T 
				count_t--;
		}
		printf("%d\n",res);
	}
	return 0;
}

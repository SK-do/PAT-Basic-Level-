#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

/*
本题要求读入 N 名学生的成绩，将获得某一给定分数的学生人数输出。

输入格式：
输入在第 1 行给出不超过 10^5的正整数 N，即学生总人数。随后一行给出 N 名学生的百分制整数成绩，中间以空格分隔。
最后一行给出要查询的分数个数 K（不超过 N 的正整数），随后是 K 个分数，中间以空格分隔。
输入样例：
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88

输出格式：
在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。
输出样例：
3 2 0
*/ 

/*看似简单，但是最后一个测试点会超时，即使先进行排序，统计完人数就结束循环，还是会超时；
百度了一下，借鉴了大佬的思路，输入学生成绩时，将每个分数的数量存在count[101]对应位置，避免了查找的双重循环！
*/

//int cmp(const void *a, const void *b)
//{
//	return *(int *)a-*(int *)b;  //升序 
//}

int main()
{
	int n,score[MAX],k,check;
	int i,j,ret[MAX]={0},count[101]={0};
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&score[i]);
		count[score[i]]++;
	}
//	qsort(score,n,sizeof(score[0]),cmp);  //将score[]升序排序 
	scanf("%d",&k);
	for(i=0; i<k-1; i++)
	{
		scanf("%d",&check);
		printf("%d ",count[check]);
//		for(j=0; j<n; j++)
//		{
//			if(check == score[j])
//				ret[i]++;
//			if(check < score[j])  //找到所有check即结束遍历 
//				break;
//		}
	}
	scanf("%d",&check);
	printf("%d\n",count[check]);
//	for(i=0; i<k-1; i++)
//		printf("%d ",ret[i]);
//	printf("%d\n",ret[k-1]);
	return 0;
}

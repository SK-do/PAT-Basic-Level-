#include <stdio.h>

/*
给定一个常数 K 以及一个单链表 L，请编写程序将 L 中每 K 个结点反转。
例如：给定 L 为 1→2→3→4→5→6，K 为 3，则输出应该为 3→2→1→6→5→4；
如果 K 为 4，则输出应该为 4→3→2→1→5→6，即最后不到 K 个元素不反转。

输入格式：
每个输入包含 1 个测试用例。每个测试用例第 1 行给出第 1 个结点的地址、结点总个数正整数 N (≤10^5)、
以及正整数 K (≤N)，即要求反转的子链结点的个数。结点的地址是 5 位非负整数，NULL 地址用 -1 表示。
接下来有 N 行，每行格式为：Address Data Next
其中 Address 是结点地址，Data 是该结点保存的整数数据，Next 是下一结点的地址。
输入样例：
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

输出格式：
对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。
输出样例：
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/ 

//有可能存在游离结点，所以应该只统计有效结点数量
//测试点5的游离节点之间无关系，而测试点6的游离节点之间可能是相连的 
//测试点5超时 --> 修改了将链表调整成正确顺序的循环，减少循环次数 

typedef struct Node{
	int address;  //结点地址 
	int data;  //结点值 
	int next;  //下一结点的地址 
}LinkList;

int main()
{
	int first,n,k,t=0,tt=0,sum=0;  //sum统计有效结点数量 
	LinkList L[100001];
	LinkList res[100001];
	scanf("%d %d %d",&first,&n,&k);
	for(int i=0; i<n; i++)
		scanf("%d %d %d",&L[i].address,&L[i].data,&L[i].next);
//	for(int i=0; i<n; i++)  //找到第一个结点 
//	{
//		if(L[i].address == first)
//			res[sum++] = L[i];		
//	}
//	for(int i=0; i<n; i++)  //将链表正序存于res[]中 
//	{
//		for(int j=0; j<n; j++)
//		{			
//			if(res[sum-1].next == L[j].address)
//				res[sum++] = L[j];
//		}
//	} 
	while(first != -1)  //找到第一个结点后，将此结点的下一个结点作为新的第一个结点，以此类推 
    {
        for(int i=0; i<n; i++)   //将链表正序存于res[]中
        {
            if(L[i].address == first)
            {
                res[sum++] = L[i];
                first = L[i].next;
            }	
        }
    }
	for(tt=0; tt+k<=sum; tt+=k)
	{
		for(int j=tt+k-1; j>=tt; j--)  //data翻转后存入L[]中 
			L[t++] = res[j];
//			printf("%05d %d %05d\n",res[j].address,res[j].data,res[j].next);
	}
	if(tt < sum)
	{
		for(int i=tt; i<sum; i++)
			L[t++] = res[i];
//			printf("%05d %d %05d\n",res[i].address,res[i].data,res[i].next);
	}
	//L[].data此时满足每k个结点反转，输出时注意修改每个结点的下一个结点地址即可 
	for(int i=0; i<t-1; i++)
		printf("%05d %d %05d\n",L[i].address,L[i].data,L[i+1].address);
	printf("%05d %d -1\n",L[t-1].address,L[t-1].data);	
	return 0;
} 

/*大佬AC代码  更加简洁，清晰 
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int first, k, n, temp;
    cin >> first >> n >> k;
    int data[100005], next[100005], list[100005];
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }
    int sum = 0;//不一定所有的输入的结点都是有用的，加个计数器
    while (first != -1) {
        list[sum++] = first;
        first = next[first];
    }
    for (int i = 0; i < (sum - sum % k); i += k)
        reverse(begin(list) + i, begin(list) + i + k);
    for (int i = 0; i < sum - 1; i++)
        printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]);
    printf("%05d %d -1", list[sum - 1], data[list[sum - 1]]);
    return 0;
}
*/ 

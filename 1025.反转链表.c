#include <stdio.h>

/*
����һ������ K �Լ�һ�������� L�����д���� L ��ÿ K ����㷴ת��
���磺���� L Ϊ 1��2��3��4��5��6��K Ϊ 3�������Ӧ��Ϊ 3��2��1��6��5��4��
��� K Ϊ 4�������Ӧ��Ϊ 4��3��2��1��5��6������󲻵� K ��Ԫ�ز���ת��

�����ʽ��
ÿ��������� 1 ������������ÿ������������ 1 �и����� 1 �����ĵ�ַ������ܸ��������� N (��10^5)��
�Լ������� K (��N)����Ҫ��ת���������ĸ��������ĵ�ַ�� 5 λ�Ǹ�������NULL ��ַ�� -1 ��ʾ��
�������� N �У�ÿ�и�ʽΪ��Address Data Next
���� Address �ǽ���ַ��Data �Ǹý�㱣����������ݣ�Next ����һ���ĵ�ַ��
����������
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

�����ʽ��
��ÿ������������˳�������ת�����������ÿ�����ռһ�У���ʽ��������ͬ��
���������
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/ 

//�п��ܴ��������㣬����Ӧ��ֻͳ����Ч�������
//���Ե�5������ڵ�֮���޹�ϵ�������Ե�6������ڵ�֮������������� 
//���Ե�5��ʱ --> �޸��˽������������ȷ˳���ѭ��������ѭ������ 

typedef struct Node{
	int address;  //����ַ 
	int data;  //���ֵ 
	int next;  //��һ���ĵ�ַ 
}LinkList;

int main()
{
	int first,n,k,t=0,tt=0,sum=0;  //sumͳ����Ч������� 
	int i,j;
	LinkList L[100001];
	LinkList res[100001];
	scanf("%d %d %d",&first,&n,&k);
	for(i=0; i<n; i++)
		scanf("%d %d %d",&L[i].address,&L[i].data,&L[i].next);
//	for(int i=0; i<n; i++)  //�ҵ���һ����� 
//	{
//		if(L[i].address == first)
//			res[sum++] = L[i];		
//	}
//	for(int i=0; i<n; i++)  //�������������res[]�� 
//	{
//		for(int j=0; j<n; j++)
//		{			
//			if(res[sum-1].next == L[j].address)
//				res[sum++] = L[j];
//		}
//	} 
	while(first != -1)  //�ҵ���һ�����󣬽��˽�����һ�������Ϊ�µĵ�һ����㣬�Դ����� 
    {
        for(i=0; i<n; i++)   //�������������res[]��
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
		for(j=tt+k-1; j>=tt; j--)  //data��ת�����L[]�� 
			L[t++] = res[j];
//			printf("%05d %d %05d\n",res[j].address,res[j].data,res[j].next);
	}
	if(tt < sum)
	{
		for(i=tt; i<sum; i++)
			L[t++] = res[i];
//			printf("%05d %d %05d\n",res[i].address,res[i].data,res[i].next);
	}
	//L[].data��ʱ����ÿk����㷴ת�����ʱע���޸�ÿ��������һ������ַ���� 
	for(i=0; i<t-1; i++)
		printf("%05d %d %05d\n",L[i].address,L[i].data,L[i+1].address);
	printf("%05d %d -1\n",L[t-1].address,L[t-1].data);	
	return 0;
} 

/*����AC����  ���Ӽ�࣬���� 
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
    int sum = 0;//��һ�����е�����Ľ�㶼�����õģ��Ӹ�������
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

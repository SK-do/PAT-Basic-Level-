#include<stdio.h>
#include<math.h>

/*
�� Pi��ʾ�� i �����������θ����������� M��N��10^4������� Pm�� Pn������������

�����ʽ��
������һ���и��� M �� N������Կո�ָ���
����������
5 27

�����ʽ��
����� Pm�� Pn������������ÿ 10������ռ 1 �У�����Կո�ָ�������ĩ�����ж���ո�
���������
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/ 

//�ж�����
int isPrime(int a)
{
	int t = (int)sqrt(a);
	for(int i=2; i<=t; i++)
	{
		if(a%i == 0)
			return 0;
	}
	return 1;
} 

int main()
{
	int pi[10000];
	int m,n,k=0,j=0;
	if(scanf("%d",&m) <= scanf("%d",&n))
	{
		for(int i=2; k<=n; i++)   //ͳ������ p1 - pn 
		{
			if(isPrime(i))  //i������
			{
				pi[k] = i; 
				k++;
			}
		}
		for(int i=m-1; i<n-1; i++)  //���pm - pn 
		{
			j++;  //ͳ�ƴ�ʱ������������� 
			if(j%10 == 0)
				printf("%d\n",pi[i]);
			else
				printf("%d ",pi[i]);
		}
		printf("%d\n",pi[n-1]);
	}
	return 0;
} 

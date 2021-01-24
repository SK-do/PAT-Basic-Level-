#include<stdio.h>

/*
����һϵ�����������밴Ҫ������ֽ��з��࣬��������� 5 �����֣�
A1 = �ܱ� 5 ����������������ż���ĺͣ�
A2 = ���� 5 ������ 1 �����ְ�����˳����н�����ͣ������� n1-n2+n3-n4...; 
A3 = �� 5 ������ 2 �����ֵĸ�����
A4 = �� 5 ������ 3 �����ֵ�ƽ��������ȷ��С����� 1 λ��
A5 = �� 5 ������ 4 ��������������֡�

�����ʽ��(13 1 2 3 4 5 6 7 8 9 10 20 16 18) (8 1 2 4 5 6 7 9 16)
ÿ��������� 1 ������������ÿ�����������ȸ���һ�������� 1000 �������� N�������� N �������� 1000 �Ĵ�����������������ּ��Կո�ָ���

�����ʽ��(30 11 2 9.7 9) (N 11 2 N 9)
�Ը����� N ��������������ĿҪ����� A1 ~ A5����һ����˳����������ּ��Կո�ָ�������ĩ�����ж���ո�
������ĳһ�����ֲ����ڣ�������Ӧλ����� N��
*/ 

int main()
{
	int n,num[1000];
	int a1[1000],a2[1000],a3[1000],a4[1000],a5[1000];
	int count1=0,count2=0,count3=0,count4=0,count5=0;
	if(scanf("%d",&n) <= 1000)
	{
		for(int i=0; i<n; i++)
		{
			if(scanf("%d",&num[i]) <= 1000);
			{
				if(num[i]%5 == 0)
				{
					a1[count1] = num[i];
					count1++;
				}
				if(num[i]%5 == 1)
				{
					a2[count2] = num[i];
					count2++;
				}
				if(num[i]%5 == 2)
				{
					a3[count3] = num[i];
					count3++;
				}
				if(num[i]%5 == 3)
				{
					a4[count4] = num[i];
					count4++;
				}
				if(num[i]%5 == 4)
				{
					a5[count5] = num[i];
					count5++;
				}
			}
		}
	}
	//1���ܱ�5����������������ż���ĺ�
	int even_sum=0; 
	for(int i=0; i<count1; i++)
	{
		if(a1[i]%2 == 0)
			even_sum += a1[i];
	}
	//�������������� 
	if(even_sum == 0)
		printf("N ");
	else
		printf("%d ",even_sum);
	
	//2������5������1�����ְ�����˳����н�����ͣ������� n1-n2+n3-n4...
	int sum=0;
	for(int i=0; i<count2; i++)
	{
		if((i+1)%2 == 0)
			sum -= a2[i];
		else
			sum += a2[i];
	}
	//������͵�ֵ����Ϊ0 
	if(count2 == 0)
		printf("N ");
	else
		printf("%d ",sum);
	
	//3����5������2�����ֵĸ��� -- count3
	if(count3 == 0)
		printf("N ");
	else
		printf("%d ",count3);
	
	//4����5������3�����ֵ�ƽ��������ȷ��С�����1λ
	int ave=0;
	double average;
	for(int i=0; i<count4; i++)
	{
		ave += a4[i];
	}
//	printf("\nave=%d,count4=%d\n",ave,count4);
	average = (double)ave/count4;
	if(count4 == 0)
		printf("N ");
	else
		printf("%.1lf ",average);
	
	//5����5������4��������������� 
	int max=a5[0];
	for(int i=1; i<count5; i++)
	{
		if(a5[i] > max)
			max = a5[i];
	}
	if(count5 == 0)
		printf("N\n");
	else
		printf("%d\n",max);
	return 0;
} 

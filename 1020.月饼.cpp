#include<stdio.h>
#include<stdlib.h>

/*
�ָ������������±��Ŀ���������ۼۡ��Լ��г�����������������������Ի�õ���������Ƕ��١�
ע�⣺����ʱ����ȡ��һ���ֿ�档���������������������ģ����������� 3 ���±����������ֱ�Ϊ 18��15��10 ��֣����ۼ۷ֱ�Ϊ 75��72��45 ��Ԫ��
����г������������ֻ�� 20 ��֣���ô��������������Ӧ��������ȫ�� 15 ��ֵ� 2 ���±����Լ� 5 ��ֵ� 3 ���±������ 72 + 45/2 = 94.5����Ԫ����

�����ʽ��
ÿ���������һ������������
ÿ�����������ȸ���һ�������� 1000 �������� N ��ʾ�±������������Լ������� 500�������Ϊ��λ���������� D ��ʾ�г������������
���һ�и��� N ��������ʾÿ���±��Ŀ�����������Ϊ��λ�������һ�и��� N ��������ʾÿ���±������ۼۣ�����ԪΪ��λ�������ּ��Կո�ָ���
����������
3 20
18 15 10
75 72 45

�����ʽ��
��ÿ�������������һ�������������棬����ԪΪ��λ����ȷ��С����� 2 λ��
���������
94.50
*/

//����������Ϊ0��Ҳ���ܴ��������±����ܿ���� 

int main()
{
	//nΪ�±���������dΪ�г������������k[]Ϊ�������s[]Ϊ���ۼۣ�m[]Ϊ���� 
	int n,index;
	float d,k[1001],s[1001],m[1001],m2[1001],max,money=0.00;
	if(scanf("%d",&n)<=1000 && scanf("%f",&d)<=500) 
	{
		for(int i=0; i<n; i++)
			if(scanf("%f",&k[i])>=0);
		for(int i=0; i<n; i++)
			if(scanf("%f",&s[i])>=0);
		for(int i=0; i<n; i++)  //�����ÿ���±��ĵ��� 
		{
			if(k[i] > 0)
			{
				m[i] = s[i]/k[i];
				m2[i] = s[i]/k[i];
			}
			else
			{
				m[i] = 0.00;
				m2[i] = 0.00;				
			}
		}
//		for(int i=0; i<n; i++)
//			printf("%f ",m[i]);
		for(int i=0; i<n; i++)   
		{
			max = m[n-1];
			for(int j=n-2; j>=i; j--)  //�����ҵ�������ߵ��±����ಢ��������
			{
				if(m[j] >= max)
				{
					max = m[j];
				}
				else 
				{
					m[j+1] = m[j];
					m[j] = max;
				} 
			}
			for(int a=0; a<n; a++)  //��¼��ߵ��۵�ԭ���±꣬�Ա㶨λ��Ӧ����������ۼ� 
			{
				if(max == m2[a])
					index = a;
			}
			if(d>0 && k[index]>0)
			{
				if(k[index] >= d)  //������������ʱ������=������*���� 
				{
					money += d*m[i];
//					printf("1��index=%d,%.2f,d=%.2f\n",index,money,d); 
				}
				else  //���С��������ʱ������=���ۼ� 
				{
					money += (float)s[index];
//					printf("2��index=%d,%.2f,d=%.2f\n",index,money,d); 
				} 
			}	
			else
			{				
				printf("%.2f\n",money); 
				return 0;
			}			
			d -= k[index];
		}
		printf("%.2f\n",money); 
	}
	return 0;
} 

/*
//�ṹ��
typedef struct MCake{
	float num;  //�±������ 
	float account;  //�±����ۼ�
	float price;  //�±����� 
}MoonCake;

//��������ıȽϺ��� 
int cmp(const void *a, const void *b)
{
	MCake *aa = (MCake *)a;
	MCake *bb = (MCake *)b;
	return (((bb->price)>(aa->price))?1:-1);
}

int main()
{
	MoonCake cake[1001];
	int n;  //nΪ�±������� 
	float d,money=0.00;  //dΪ�г���������� 
	if(scanf("%d",&n)<=1000 && scanf("%f",&d)<=500) 
	{
		for(int i=0; i<n; i++)
			scanf("%f",&cake[i].num);
		for(int i=0; i<n; i++)
			scanf("%f",&cake[i].account);
		for(int i=0; i<n; i++)  //����ÿ���±��ĵ��ۣ���Ԫ/��֣� 
		{
			if(cake[i].num > 0)
				cake[i].price = cake[i].account/cake[i].num;
			else
				cake[i].price = 0.00;
		}
		
		qsort(cake,n,sizeof(cake[0]),cmp);  //����
		
		for(int i=0; i<n; i++)
		{
			if(d > 0)
			{
				if(d >= cake[i].num)
					money += cake[i].account;
				else
					money += d*cake[i].price;				
				d -= cake[i].num;
			}
			else
			{
				printf("%.2f\n",money);
				return 0;
			}
		} 
		printf("%.2f\n",money);
	}
	return 0;
} 
*/

#include<stdio.h>
#include<math.h> 

/*
�����Ƕ���dnΪ��dn = Pn+1-Pn,����Pi�ǵ�i����������Ȼ��d1 = 1���Ҷ���n>1��dn��ż�����������Բ��롱��Ϊ�����������������Ҳ�Ϊ2����������
�ָ�������������N(<10^5)������㲻����N���������������Եĸ�����

�����ʽ:(20) 
������һ�и���������N��

�����ʽ:(4)
��һ�������������N���������������Եĸ�����
*/

//�ж�һ�����Ƿ�Ϊ����
int isPrime(int a)
{
	int i;
	int k = (int)sqrt(a);
	for(i=2; i<=k; i++)
	{
		if(a%i == 0)   //��ֻ��1���������� 
			return 0;
	}
	return 1;
} 

int main()
{
	int n,count=0;  //count��¼�������������Ը���
	int i; 
	if(scanf("%d",&n) > 0)
	{
		for(i=5; i<=n; i=i+2)  //2Ϊ���� 
		{
			if(isPrime(i) && isPrime(i-2))  //�����Ҳ�Ϊ2������ 
			{
//				printf("%d %d\n",i,i-2);
				count++;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}

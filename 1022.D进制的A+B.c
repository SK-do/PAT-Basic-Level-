#include<stdio.h>

/*
���������Ǹ� 10 �������� A �� B (��2^30-1)����� A+B �� D (1<D��10)��������

�����ʽ��(123 456 8)
������һ�������θ��� 3 ������ A��B �� D��

�����ʽ��(1103)
��� A+B �� D ��������
*/ 

int main()
{
	int a,b,sum,D,res[1000],i=0,j;
	if(scanf("%d",&a)>0 && scanf("%d",&b)>0 && scanf("%d",&D)<=10)
	{
		sum = a+b;
//		while(sum > 0)  //���Ե�3δ��  ��δ���� 0 0 �������  ���Ϊ0 ������� 
//		{
//			res[i++] = sum%D;
//			sum /= D;			
//		} 
		do
		{
			res[i++] = sum%D;
			sum /= D;
		}while(sum > 0);
		for(j=i-1; j>=0; j--)
			printf("%d",res[j]);
		printf("\n");
	}
	return 0;
} 

#include<stdio.h>
#include<string.h>

/*
���д����ͳ��ÿ�ֲ�ͬ�ĸ�λ���ֳ��ֵĴ��������磺���� N=100311������ 2 �� 0��3 �� 1���� 1 �� 3��

�����ʽ��
ÿ��������� 1 ��������������һ�������� 1000 λ�������� N��
����������
100311

�����ʽ��
�� N ��ÿһ�ֲ�ͬ�ĸ�λ���֣��� D:M �ĸ�ʽ��һ���������λ���� D ������ N �г��ֵĴ��� M��Ҫ�� D �����������
���������
0:2
1:3
3:1
*/ 

int main()
{
	char num[1001];  //���벻����1000λ�������� -- ֻ��ת�����ַ������� 
	int len, M[10]={0},i;
	scanf("%s",num);
	len = strlen(num);
//	printf("%s %d\n",num,len);
	for(i=0; i<len; i++)
	{
//		switch (num[i]){
//			case '0':	M[0]++;    break;
//			case '1':	M[1]++;    break;
//			case '2':	M[2]++;    break;
//			case '3':	M[3]++;    break;
//			case '4':	M[4]++;    break;
//			case '5':	M[5]++;    break;
//			case '6':	M[6]++;    break;
//			case '7':	M[7]++;    break;
//			case '8':	M[8]++;    break;
//			case '9':	M[9]++;    break;			
//		}
		M[num[i]-'0']++;
	}
	for(i=0; i<=9; i++)
	{
		if(M[i] != 0)
			printf("%d:%d\n",i,M[i]);
	}
	return 0;
}

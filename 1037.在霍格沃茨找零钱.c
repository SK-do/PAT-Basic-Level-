#include <stdio.h>

/*
������ǹ����������ԣ����֪��ħ�����������Լ��Ļ���ϵͳ ���� ���纣����߹����ģ�
��ʮ�߸�������(Sickle)��һ����¡(Galleon)����ʮ�Ÿ�����(Knut)��һ�����ɣ������ס���
���ڣ���������Ӧ���ļ�Ǯ P ����ʵ����Ǯ A�����������дһ��������������Ӧ�ñ��ҵ���Ǯ��

�����ʽ��(10.16.27 14.1.28) (14.1.28 10.16.27)
������ 1 ���зֱ���� P �� A����ʽΪ Galleon.Sickle.Knut������� 1 ���ո�ָ���
���� Galleon �� [0, 10^7] �����ڵ�������Sickle �� [0, 17) �����ڵ�������Knut �� [0, 29) �����ڵ�������

�����ʽ��(3.2.1) (-3.2.1)
��һ������������ͬ���ĸ�ʽ�������Ӧ�ñ��ҵ���Ǯ�������û����Ǯ����ô�����Ӧ���Ǹ�����
*/ 

void pay(int ag,int as,int ak,int bg,int bs,int bk)
{
	int g,s,k;
	if(ak >= bk)  //����Ӧ�ҵ����أ�Knut�� 
	{
		k = ak-bk;		
	}
	else
	{
		k = ak+29-bk;
		as--;
	}
	if(as >= bs)  //����Ӧ�ҵ����ɣ�Sickle��
	{
		s = as-bs;
	} 
	else
	{
		s = as+17-bs;
		ag--;
	}
	g = ag-bg;
	printf("%d.%d.%d\n",g,s,k);
} 

int main()
{
	int pg,ps,pk,ag,as,ak;
	int i,j;
	scanf("%d.%d.%d %d.%d.%d",&pg,&ps,&pk,&ag,&as,&ak);
	if(pg<ag || (pg==ag && ps<as) || (pg==ag && ps==as && pk<=ak))  //Ǯ�㹻֧�� 
		pay(ag,as,ak,pg,ps,pk);
	else  //û����Ǯ��������� 
	{
		printf("-");
		pay(pg,ps,pk,ag,as,ak); 
	}
	return 0;
}

#include<stdio.h>
#include<string.h>

/*
1004 �ɼ����� (20��)
���� n��>0����ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�

�����ʽ��
ÿ������������� 1 ��������������ʽΪ
�� 1 �У������� n
�� 2 �У��� 1 ��ѧ�������� ѧ�� �ɼ�
�� 3 �У��� 2 ��ѧ�������� ѧ�� �ɼ�
  ... ... ...
�� n+1 �У��� n ��ѧ�������� ѧ�� �ɼ�
����������ѧ�ž�Ϊ������ 10 ���ַ����ַ������ɼ�Ϊ 0 �� 100 ֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�
����������
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

�����ʽ��
��ÿ������������� 2 �У��� 1 ���ǳɼ����ѧ����������ѧ�ţ��� 2 ���ǳɼ����ѧ����������ѧ�ţ��ַ������� 1 �ո�
���������
Mike CS991301
Joe Math990112
*/ 

int main()
{
	int n;   //ѧ������
	char name[100],number[100];
	char min_name[100],min_number[100],max_name[100],max_number[100];
	int score,min_score=100,max_score=0;
	int i;
	if(scanf("%d",&n) > 0)
	{
		for(i=0; i<n; i++)
		{
			if(scanf("%s",name) && scanf("%s",number) && scanf("%d",&score)>=0)
            {
                if(score >= max_score)
                {
                    strcpy(max_name,name);
                    strcpy(max_number,number);
                    max_score = score;
                }
                if(score <= min_score)
                {
                    strcpy(min_name,name);
                    strcpy(min_number,number);
                    min_score = score;
                }
            }
		}
		printf("%s %s\n",max_name,max_number);
		printf("%s %s\n",min_name,min_number);
	} 
	return 0;
}

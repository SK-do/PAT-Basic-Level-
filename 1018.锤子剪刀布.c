#include<stdio.h>

/*
���Ӧ�ö����桰���Ӽ�����������Ϸ��
����ͬʱ�������ƣ��ָ������˵Ľ����¼����ͳ��˫����ʤ��ƽ�������������Ҹ���˫���ֱ��ʲô���Ƶ�ʤ�����

�����ʽ��
����� 1 �и��������� N����10^5������˫������Ĵ�������� N �У�ÿ�и���һ�ν������Ϣ��
���ס���˫��ͬʱ�����ĵ����ơ�C�������ӡ���J������������B������������ 1����ĸ����׷����� 2�������ҷ����м���1���ո�
����������
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J

�����ʽ��
����� 1��2 �зֱ�����ס��ҵ�ʤ��ƽ�������������ּ��� 1 ���ո�ָ���
��3�и���������ĸ���ֱ����ס��һ�ʤ�����������ƣ��м��� 1 ���ո�����ⲻΨһ�����������ĸ����С�Ľ�
���������
5 3 2
2 3 5
B B
*/

//�����ʤ������������
int function(int t[])
{
	int index=0,max=t[0],i;
	for(i=1; i<3; i++)
	{
		if(t[i] > max)
		{
			max = t[i];
			index = i;
		}
	}
	return index;
} 

int main()
{
	int n,more_a[3]={0},more_b[3]={0};  //0-B; 1-C; 2-J
	char a,b,more[3]={'B','C','J'};
	int win_a=0,win_b=0,ave_a=0,ave_b=0,fal_a=0,fal_b=0;
	int i;
	if(scanf("%d",&n) <= 100000)
	{
		for(i=0; i<n; i++)
		{
			while(getchar()!='\n');  //���scanf�Ĳ������ݣ���Ȼscanf���ȡ�����з� 
			scanf("%c %c",&a,&b);
//			printf("%c %c\n",a,b);
			if(a=='C' && b=='J')  //�׷� C ʤ 
			{
				win_a++;
				fal_b++;
				more_a[1]++; 
			}
			if(a=='J' && b=='B')  //�׷� J ʤ 
			{
				win_a++;
				fal_b++;
				more_a[2]++; 
			}
			if(a=='B' && b=='C')  //�׷� B ʤ 
			{
				win_a++;
				fal_b++;
				more_a[0]++; 
			}
			if((a=='C'&&b=='C') || (a=='J'&&b=='J') || (a=='B'&&b=='B'))  //ƽ��
			{
				ave_a++;
				ave_b++;
			} 
			if(a=='J' && b=='C')  //�ҷ� C ʤ 
			{
				win_b++;
				fal_a++;
				more_b[1]++; 
			}
			if(a=='B' && b=='J')  //�ҷ� J ʤ 
			{
				win_b++;
				fal_a++;
				more_b[2]++; 
			}
			if(a=='C' && b=='B')  //�ҷ� B ʤ 
			{
				win_b++;
				fal_a++;
				more_b[0]++; 
			}
		}
	}
	printf("%d %d %d\n",win_a,ave_a,fal_a);
	printf("%d %d %d\n",win_b,ave_b,fal_b);
	printf("%c %c\n",more[function(more_a)],more[function(more_b)]);
	return 0;
} 

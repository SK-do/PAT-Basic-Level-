#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

/*
����Ҫ����� N ��ѧ���ĳɼ��������ĳһ����������ѧ�����������

�����ʽ��
�����ڵ� 1 �и��������� 10^5�������� N����ѧ�������������һ�и��� N ��ѧ���İٷ��������ɼ����м��Կո�ָ���
���һ�и���Ҫ��ѯ�ķ������� K�������� N ����������������� K ���������м��Կո�ָ���
����������
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88

�����ʽ��
��һ���а���ѯ˳������÷ֵ���ָ��������ѧ���������м��Կո�ָ�������ĩ�����ж���ո�
���������
3 2 0
*/ 

/*���Ƽ򵥣��������һ�����Ե�ᳬʱ����ʹ�Ƚ�������ͳ���������ͽ���ѭ�������ǻᳬʱ��
�ٶ���һ�£�����˴��е�˼·������ѧ���ɼ�ʱ����ÿ����������������count[101]��Ӧλ�ã������˲��ҵ�˫��ѭ����
*/

//int cmp(const void *a, const void *b)
//{
//	return *(int *)a-*(int *)b;  //���� 
//}

int main()
{
	int n,score[MAX],k,check;
	int i,j,ret[MAX]={0},count[101]={0};
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&score[i]);
		count[score[i]]++;
	}
//	qsort(score,n,sizeof(score[0]),cmp);  //��score[]�������� 
	scanf("%d",&k);
	for(i=0; i<k-1; i++)
	{
		scanf("%d",&check);
		printf("%d ",count[check]);
//		for(j=0; j<n; j++)
//		{
//			if(check == score[j])
//				ret[i]++;
//			if(check < score[j])  //�ҵ�����check���������� 
//				break;
//		}
	}
	scanf("%d",&check);
	printf("%d\n",count[check]);
//	for(i=0; i<k-1; i++)
//		printf("%d ",ret[i]);
//	printf("%d\n",ret[k-1]);
	return 0;
}

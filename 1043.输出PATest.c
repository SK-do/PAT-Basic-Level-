#include <stdio.h>

/*
����һ�����Ȳ����� 10^4�ġ�����Ӣ����ĸ���ɵ��ַ������뽫�ַ����µ���˳�򣬰� PATestPATest.... ������˳������������������ַ���
��Ȼ�������ַ��ĸ�����һ����һ����ģ���ĳ���ַ��Ѿ�����꣬�����µ��ַ��԰� PATest ��˳���ӡ��ֱ�������ַ����������

�����ʽ��(redlesPayBestPATTopTeePHPereatitAPPT)
������һ���и���һ�����Ȳ����� 10^4�ġ�����Ӣ����ĸ���ɵķǿ��ַ�����

�����ʽ��(PATestPATestPTetPTePePee)
��һ���а���ĿҪ������������ַ�������Ŀ��֤����ǿա�
*/

int main()
{
	char c;
	int count[127]={0},i;
	while((c=getchar()) != '\n')  //��ASCII��洢����ĸ����ַ����� 
		count[(int)c]++;
	while(count['P']>0 || count['A']>0 || count['T']>0 || count['e']>0 || count['s']>0 || count['t']>0)  //������е�PATest�ַ� 
	{
		if(count['P'] > 0)
		{
			printf("P");
			count['P']--;
		}
		if(count['A'] > 0)
		{
			printf("A");
			count['A']--;
		}
		if(count['T'] > 0)
		{
			printf("T");
			count['T']--;
		}
		if(count['e'] > 0)
		{
			printf("e");
			count['e']--;
		}
		if(count['s'] > 0)
		{
			printf("s");
			count['s']--;
		}
		if(count['t'] > 0)
		{
			printf("t");
			count['t']--;
		}
	} 
	printf("\n");
	return 0;
} 

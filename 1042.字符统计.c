#include <stdio.h>
#include <ctype.h>

/*
���д�����ҳ�һ�θ��������г�����Ƶ�����Ǹ�Ӣ����ĸ��

�����ʽ��(This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........)
������һ���и���һ�����Ȳ����� 1000 ���ַ�����
�ַ����� ASCII ���������ɼ��ַ����ո���ɣ����ٰ��� 1 ��Ӣ����ĸ���Իس��������س��������ڣ���

�����ʽ��(e 7)
��һ�����������Ƶ����ߵ��Ǹ�Ӣ����ĸ������ִ���������Կո�ָ���
����в��У����������ĸ����С���Ǹ���ĸ��ͳ��ʱ�����ִ�Сд�����Сд��ĸ��
*/

int main()
{
	char c;
	int count[127]={0},i,index,max;
	while((c=tolower(getchar())) != '\n')  //tolower�������������ַ���Сд��ĸ��û��Сд��ĸ���򱣳ֲ���
		count[(int)c]++;
	max = index = 0;
	for(i=97; i<123; i++)  //a~z  97~122
	{
		if(count[i] > max)  //����в��У����������ĸ����С���Ǹ���ĸ
		{
			max = count[i];
			index = i;
		}
	}
	printf("%c %d\n",index,max);
	return 0;
} 

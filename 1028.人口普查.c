#include <stdio.h>
#include <stdlib.h>

/*
ĳ��������˿��ղ飬�õ���ȫ���������ա�������д�������ҳ��������곤����������ˡ�
����ȷ��ÿ����������ڶ��ǺϷ��ģ�����һ���Ǻ���ġ���������֪����û�г��� 200 ������ˣ��������� 2014 �� 9 �� 6 �գ�
���Գ��� 200 ������պ�δ���������ն��ǲ�����ģ�Ӧ�ñ����˵���

�����ʽ��
�����ڵ�һ�и��������� N��ȡֵ��(0,10^5]����� N �У�ÿ�и��� 1 ���˵��������ɲ����� 5 ��Ӣ����ĸ��ɵ��ַ�������
�Լ��� yyyy/mm/dd������/��/�գ���ʽ���������ա���Ŀ��֤���곤�����������û�в��С�
����������
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20

�����ʽ��
��һ����˳�������Ч���յĸ��������곤�˺��������˵�����������Կո�ָ���
���������
3 Tom John
*/

//ע�⣺��������ڿ��ܾ���������ʱֻ�����һ�� 0 ���� 

typedef struct{
	char name[5];
	int year,month,day;
}people;

int cmp(const void *a, const void *b)
{
	people *aa = (people *)a;
	people *bb = (people *)b;
	if(aa->year != bb->year)  //��ͬ����� 
		return (aa->year)-(bb->year);
	else if(aa->month != bb->month)  //��ͬ�³��� 
		return (aa->month)-(bb->month);
	else  
		return (aa->day)-(bb->day); 
}

int main()
{
	int n,l=0,i;
	people t,p[100001];
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		scanf("%s %d/%d/%d",t.name,&t.year,&t.month,&t.day);  //name yyyy/mm/dd
		 //����200������պ�δ���������ղ����� 
		if(t.year<2014 && t.year>1814)
			p[l++] = t;
		else if((t.year==2014 && t.month<9) || (t.year==1814 && t.month>9))
			p[l++] = t;
		else if((t.year==2014 && t.month==9 && t.day<=6) || (t.year==1814 && t.month==9 && t.day>=6))
			p[l++] = t;
	}
	qsort(p,l,sizeof(people),cmp);
    if(l > 0)
	    printf("%d %s %s\n",l,p[0].name,p[l-1].name);
    else  //��������ھ�������
        printf("%d\n",l);
	return 0;
}

#include<stdio.h>
#include<string.h>

/*
����̽����Ħ˹�ӵ�һ����ֵ�����������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm��
����̽�ܿ�������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�������� 14:04��
1����Ϊǰ�����ַ����е� 1 ����ͬ�Ĵ�дӢ����ĸ����Сд�����֣��ǵ� 4 ����ĸ D�����������ģ�
2���� 2 ����ͬ���ַ��� E �����ǵ� 5 ��Ӣ����ĸ������һ����ĵ� 14 ����ͷ������һ��� 0 �㵽 23 �������� 0 �� 9���Լ���д��ĸ A��N��ʾ����
3���������ַ����� 1 ����ͬ��Ӣ����ĸ s �����ڵ� 4 ��λ�ã��� 0 ��ʼ�������ϣ������ 4 ���ӡ�
�ָ��������ַ��������������Ħ˹����õ�Լ���ʱ�䡣

�����ʽ��
������ 4 ���зֱ���� 4 ���ǿա��������ո��ҳ��Ȳ����� 60 ���ַ�����
����������
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm

�����ʽ��
��һ�������Լ���ʱ�䣬��ʽΪ DAY HH:MM������ DAY ��ĳ���ڵ� 3 �ַ���д��
�� MON ��ʾ����һ��TUE ��ʾ���ڶ���WED ��ʾ��������THU ��ʾ�����ģ�FRI ��ʾ�����壬SAT ��ʾ��������SUN ��ʾ�����ա�
��Ŀ���뱣֤ÿ�����Դ���Ψһ�⡣
���������
THU 14:04
*/

int main()
{
	char d1[60],d2[60],t1[60],t2[60];
	char day,hour;
	int time,count=0,flag=0;  //flag�����ж��Ƿ��ҵ����������ĵ�һ����ĸ 
	int len_d1,len_d2,len_t1,len_t2,len1,len2;
	int i;
	scanf("%s %s %s %s",&d1,&d2,&t1,&t2);
	len_d1 = strlen(d1);
	len_d2 = strlen(d2);
	len_t1 = strlen(t1);
	len_t2 = strlen(t2);
//	printf("%d %d ",len_d1,len_d2);
	if(len_d1 >= len_d2)
		len1 = len_d2;
	else
		len1 = len_d1;
	if(len_t1 >= len_t2)
		len2 = len_t2;
	else
		len2 = len_t1;
	for(i=0; i<len1; i++)
	{
		if(d1[i]==d2[i] && flag==0 && d1[i]>='A' && d1[i]<='G')
		{
			day = d1[i];
			flag = 1;
			switch(day){
				case 'A':	printf("MON ");    break;
				case 'B':	printf("TUE ");    break;
				case 'C':	printf("WED ");    break;
				case 'D':	printf("THU ");    break;
				case 'E':	printf("FRI ");    break;
				case 'F':	printf("SAT ");    break;
				case 'G':	printf("SUN ");    break;
			}
			continue;
		}
		if(d1[i]==d2[i] && flag==1)
		{
			if((d1[i]>='A' && d1[i]<='N') || (d1[i]>='0' && d1[i]<='9'))
			{
				hour = d1[i];
				break;
			}
		}
	}
	for(i=0; i<len2; i++)
	{
		if(t1[i] == t2[i])
		{
			if(t1[i]>='A' && t1[i]<='Z')
			{
				time = i;
				break;				
			}
			if(t1[i]>='a' && t1[i]<='z')
			{
				time = i;
				break;				
			}
		}
	}
//	for(int i=0; i<strlen(d); i++)
//		printf("%c ",d[i]);				
//	switch(hour){
//		case '0':	printf("00:");	  break;
//		case '1':	printf("01:");	  break;
//		case '2':	printf("02:");	  break;
//		case '3':	printf("03:");    break;
//		case '4':	printf("04:");	  break;
//		case '5':	printf("05:");	  break;
//		case '6':	printf("06:");	  break;
//		case '7':	printf("07:");	  break;
//		case '8':	printf("08:");	  break;
//		case '9':	printf("09:");	  break;
//		case 'A':	printf("10:");    break;
//		case 'B':	printf("11:");    break;
//		case 'C':	printf("12:");    break;
//		case 'D':	printf("13:");    break;
//		case 'E':	printf("14:");    break;
//		case 'F':	printf("15:");    break;
//		case 'G':	printf("16:");    break;
//		case 'H':	printf("17:");    break;
//		case 'I':	printf("18:");    break;
//		case 'J':	printf("19:");    break;
//		case 'K':	printf("20:");    break;
//		case 'L':	printf("21:");    break;
//		case 'M':	printf("22:");    break;
//		case 'N':	printf("23:");    break;
//	}
	if(hour>='0' && hour<='9')
		printf("0%c:",hour);
	else
		printf("%d:",hour-'A'+10);  //����ASCII����� 
	printf("%02d\n",time);   //���ݿ�Ȳ���2λʱ��0�
//	printf("\n%c %c %d\n",day,hour,time);
	return 0;
}

#include <stdio.h>
#include <string.h>

/*
���������� 13 ���Ƽ����ģ�
1�������˵� 0 �������˳�Ϊ tret��
2������������ 1 �� 12 �Ļ����ķֱ�Ϊ��jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec��
3�������˽���λ�Ժ�� 12 ����λ���ֱַ��Ϊ��tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou��
��������˵����� 29 ����ɻ����ľ��� hel mar���������� elo nov ��Ӧ�������� 115��
Ϊ�˷��㽻���������д����ʵ�ֵ���ͻ�������֮��Ļ��롣

�����ʽ��
�����һ�и���һ�������� N��<100������� N �У�ÿ�и���һ�� [0, 169) �����ڵ����� ���� �����ǵ����ģ������ǻ����ġ�
����������
4
29
5
elo nov
tam

�����ʽ��
��Ӧ�����ÿһ�У���һ���������������һ�����Ե����֡�
���������
hel mar
may
115
13
*/

//�������ַ�����������������ģ����Ե�4һֱ�� ����ʱ���� ��δ�ҵ�ԭ�� 
//�������˼·������strncmp������λ�Ƚϡ� 

int main()
{
	char a[13][5]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};  //�����λ��Ӧ�Ļ�����
	char b[13][4]={"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};  //�����λ��Ӧ�Ļ�����
	int n,i,j,len,num=0,l_high=0,l_low=0,res=0;
	char c,s[10],high[5],low[5];
	scanf("%d",&n);
	while(getchar()!='\n');  //���scanf��������Ƭ 
	for(i=0; i<n; i++)
	{
//		gets(s);
		c = getchar();
		for(j=0; c!='\n'; j++)
		{
			s[j] = c; 
			c = getchar();
		}
		s[j] = '\0';  //ע����Ҫ�ֶ�����ַ���������
		len = strlen(s);
		if(s[0]>='0' && s[0]<='9')  //����Ϊ�������� 
		{
			num = 0;
			for(j=0; j<len; j++)  //���ַ���ת��Ϊ���� 
				num = num*10+(s[j]-'0');
//			printf("num = %d\n",num);
			if(num/13 != 0)   //�н�λ
			{
				if(num%13 == 0)  //����13
					printf("%s\n",b[num/13]);
				else  //������ 
					printf("%s %s\n",b[num/13],a[num%13]);
			}
			else if(num%13 != 0)  //û�н�λ 
				printf("%s\n",a[num%13]);
			else if(num == 0)
				printf("tret\n");
		}
		else  //����Ϊ������
		{
			res = 0; 
			if(len == 3)  //ֻ��һ�������� 
			{
				for(j=1; j<13; j++)
				{
					if(strcmp(s,a[j]) == 0)  //�ǵ�λ 
						res = j;
					if(strcmp(s,b[j]) == 0)  //�Ǹ�λ 
						res = j*13;
				}				
				printf("%d\n",res);
			}
			else if(len == 4)  //Ϊ0
				printf("0\n");
			else  //������������ 
			{
				for(j=0; j<13; j++)
				{
					if(strncmp(s,b[j],3) == 0)  //�Ƚ��ַ���ǰ3λ 
						res += j*13;
				}
				strcpy(s,&s[4]);  //�ѵ�2λ���Ƶ���1λ������
				for(j=0; j<13; j++)
				{
					if(strncmp(s,a[j],3) == 0)
						res += j;
				}
//				for(j=0; j<len; j++)  //�������λ 
//				{
//					if(s[j] != ' ')
//						high[l_high++] = s[j];
//					else
//						break;
//				} 
//				for(j=l_high+1; j<len; j++)  //�������λ 
//					low[l_low++] = s[j];
//				for(j=0; j<13; j++)
//				{
//					if(strcmp(high,b[j]) == 0)
//						res += j*13;
//					if(strcmp(low,a[j]) == 0)
//						res += j;	
//				}
				printf("%d\n",res);
			} 
		} 
	}
	return 0;
}

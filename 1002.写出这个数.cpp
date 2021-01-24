#include <stdio.h>
#include <string.h>

int main()
{
	char n[200];
	int sum=0,length; 
	int count[100],i=0;
	char *str[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	scanf("%s",&n);
	length = strlen(n);
	for(int i=0; i<length; i++)
	{
		sum += n[i] - '0';
	}
//	printf("%d", sum);
	while(sum >= 1)
	{
		count[i] = sum%10;
		sum = sum/10;
		i++;
	}
	for(int j=i-1; j>0; j--)
	{
		printf("%s ",str[count[j]]);
	}
	printf("%s",str[count[0]]);
	return 0;
}

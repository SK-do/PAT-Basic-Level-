#include<stdio.h>

int main()
{
	int n;
	int i=0;   //iֵ��¼���貽�� 
	if(scanf("%d",&n) <= 1000){
        while(n != 1){
            if(n%2 == 0){   //nΪż�� 
                n = n/2;
                i++;
            }
            else{   //nΪ���� 
                n = (3*n+1)/2;
                i++;
            }
        }
    }
	printf("%d\n",i);
	return 0;
} 

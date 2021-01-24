#include<stdio.h>

int main()
{
	int n;
	int i=0;   //i值记录所需步数 
	if(scanf("%d",&n) <= 1000){
        while(n != 1){
            if(n%2 == 0){   //n为偶数 
                n = n/2;
                i++;
            }
            else{   //n为奇数 
                n = (3*n+1)/2;
                i++;
            }
        }
    }
	printf("%d\n",i);
	return 0;
} 

#include<stdio.h>
#include<string.h>

/*
1004 成绩排名 (20分)
读入 n（>0）名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：
每个测试输入包含 1 个测试用例，格式为
第 1 行：正整数 n
第 2 行：第 1 个学生的姓名 学号 成绩
第 3 行：第 2 个学生的姓名 学号 成绩
  ... ... ...
第 n+1 行：第 n 个学生的姓名 学号 成绩
其中姓名和学号均为不超过 10 个字符的字符串，成绩为 0 到 100 之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

输出格式：
对每个测试用例输出 2 行，第 1 行是成绩最高学生的姓名和学号，第 2 行是成绩最低学生的姓名和学号，字符串间有 1 空格。
输出样例：
Mike CS991301
Joe Math990112
*/ 

int main()
{
	int n;   //学生个数
	char name[100],number[100];
	char min_name[100],min_number[100],max_name[100],max_number[100];
	int score,min_score=100,max_score=0;
	int i;
	if(scanf("%d",&n) > 0)
	{
		for(i=0; i<n; i++)
		{
			if(scanf("%s",name) && scanf("%s",number) && scanf("%d",&score)>=0)
            {
                if(score >= max_score)
                {
                    strcpy(max_name,name);
                    strcpy(max_number,number);
                    max_score = score;
                }
                if(score <= min_score)
                {
                    strcpy(min_name,name);
                    strcpy(min_number,number);
                    min_score = score;
                }
            }
		}
		printf("%s %s\n",max_name,max_number);
		printf("%s %s\n",min_name,min_number);
	} 
	return 0;
}

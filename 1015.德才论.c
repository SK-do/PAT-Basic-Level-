#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

/*
宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：
“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”
现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：
输入第一行给出 3 个正整数，分别为：N（≤10^5），即考生总数；L（≥60），为录取最低分数线，即德分和才分均不低于 L 的考生才有资格被考虑录取；
H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；
才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；
德才分均低于 H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；
其他达到最低线 L 的考生也按总分排序，但排在第三类考生之后。
随后 N 行，每行给出一位考生的信息，包括：准考证号 德分 才分，其中准考证号为 8 位整数，德才分为区间 [0, 100] 内的整数。数字间以空格分隔。
输入样例：
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60

输出格式：
输出第一行首先给出达到最低分数线的考生人数 M，随后 M 行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。
当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。
输出样例：
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/

typedef struct{    //考生信息 
	int no,de,cai;
}student;

//排序所需的比较函数
int cmp(const void *a, const void *b)
{
	student *aa = (student *)a;
	student *bb = (student *)b;
	if((aa->de+aa->cai) != (bb->de+bb->cai))  //按总分降序排序 
		return (bb->de+bb->cai)-(aa->de+aa->cai);
	else if(aa->de != bb->de)  //总分相同，按德分降序排序
		return (bb->de)-(aa->de);
	else  //德分相同，按准考证号升序排序 
		return (aa->no)-(bb->no); 
} 

//输出
void display(student t[], int l)
{
	int i;
	for(i=0; i<l; i++)
		printf("%d %d %d\n",t[i].no,t[i].de,t[i].cai);
} 

int main()
{
	int n,l,h,i;  //l为最低录取线，h为优先录取线 
	int l1,l2,l3,l4;
	student s,class1[MAX],class2[MAX],class3[MAX],class4[MAX];
	l1=l2=l3=l4=0;
	scanf("%d %d %d",&n,&l,&h);
	for(i=0; i<n; i++)
	{
		scanf("%d %d %d",&s.no,&s.de,&s.cai);
        if(s.de>=l && s.cai>=l)
        {            
            if(s.de>=h && s.cai>=h)  //①德分和才分均不低于 h
                class1[l1++] = s; 
            else if(s.de >= h)  //②才分不到但德分到线
                class2[l2++] = s;
            else if(s.de >= s.cai)  //③德才分均低于 h，但德分不低于才分
                class3[l3++] = s;
            else  //④其他达到最低线 l 的考生 
                class4[l4++] = s;
        }
	}
	//将每一类考生分别按要求排序 
	qsort(class1, l1, sizeof(student), cmp);
	qsort(class2, l2, sizeof(student), cmp);
	qsort(class3, l3, sizeof(student), cmp);
	qsort(class4, l4, sizeof(student), cmp);
	printf("%d\n",l1+l2+l3+l4);  //输出过线考生总数
	//输出每类考生 
	display(class1,l1);
	display(class2,l2);
	display(class3,l3);
	display(class4,l4);
	return 0;
}

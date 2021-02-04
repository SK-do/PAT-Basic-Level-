#include <stdio.h>
#include <ctype.h>

/*
请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

输入格式：(This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........)
输入在一行中给出一个长度不超过 1000 的字符串。
字符串由 ASCII 码表中任意可见字符及空格组成，至少包含 1 个英文字母，以回车结束（回车不算在内）。

输出格式：(e 7)
在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。
如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。
*/

int main()
{
	char c;
	int count[127]={0},i,index,max;
	while((c=tolower(getchar())) != '\n')  //tolower函数返回输入字符的小写字母，没有小写字母的则保持不变
		count[(int)c]++;
	max = index = 0;
	for(i=97; i<123; i++)  //a~z  97~122
	{
		if(count[i] > max)  //如果有并列，则输出按字母序最小的那个字母
		{
			max = count[i];
			index = i;
		}
	}
	printf("%c %d\n",index,max);
	return 0;
} 

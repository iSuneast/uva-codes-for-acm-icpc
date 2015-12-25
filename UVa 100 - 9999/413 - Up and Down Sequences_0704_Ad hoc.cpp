/*
413 - Up and Down Sequences

Ad hoc...
题目不难...
关键是去重...
把一样的连续元素压缩在一起,另外用一个数组保存这个元素的出现次数
然后从头到尾一次扫描加判断即可...
用一个值保存当前的访问状态...
0代表开始
1代表up
-1代表down
则只要每次判断的时候看一下上一对的状态与当前状态
相同则累加序列值,不同的话要同时累加序列的个数...
*/

#include<iostream>
#define MAXN 100
using namespace std;

int var[MAXN],num[MAXN],tot;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&var[0])!=EOF && var[0])
	{
		tot=1;
		while(scanf("%d",&var[tot])!=EOF && var[tot])
			++tot;

		int p=0;
		num[p]=1;
		for(int i=1;i<tot;++i)
		{
			if(var[i]==var[p])
				++num[p];
			else
			{
				var[++p]=var[i];
				num[p]=1;
			}
		}
		++p;

		int up=0,up_cnt=0,down=0,down_cnt=0,cnt=0;
		int u=0;

		for(int i=1;i<p;++i)
		{
			if(var[i]>var[i-1])
			{
				up+=num[i];
				if(!u)
					up+=num[i-1]-1;
				if(u<=0)
					++up_cnt;
				u=1;
			}
			else if(var[i]<var[i-1])
			{
				down+=num[i];
				if(!u)
					down+=num[i-1]-1;
				if(u>=0)
					++down_cnt;
				u=-1;
			}
		}

		double key1=0,key2=0;
		if(up_cnt)
			key1=up*1.0/up_cnt;
		if(down_cnt)
			key2=down*1.0/down_cnt;
		printf("Nr values = %d:  %.6lf %.6lf\n",tot,key1,key2);
	}

	return 0;
}

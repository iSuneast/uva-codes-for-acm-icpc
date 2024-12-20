/*
10720 - Graph Construction

greedy...
brute force...
O(N^2logN)
贪心+暴力匹配...

对初始给定的图要判断说是否有
	<0度的顶点
	>=n度的顶点
	以上两种无解...
	其余情况也是类似的判定...
可为什么以前就是过不了?
*/

#include<iostream>
#include<algorithm>
#define MAXN 10010
using namespace std;

int n,node[MAXN];

bool judge()
{
	int start=0,end=n;
	while(start<end)
	{
		sort(node+start,node+end);
		while(start<end && !node[start])	//0度顶点
			++start;
		if(start==end)
			return true;
		if(node[end-1]>=end-start)	//顶点度数过大无法分配
			return false;
		int p=end-2;
		while(node[end-1]--)	//贪心
			--node[p--];
		--end;
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		bool got=false;
		for(int i=0;i<n;++i)
		{
			scanf("%d",node+i);
			if(node[i]<0 || node[i]>=n)		//无解判定
				got=true;
		}
		if(!got && judge())
			puts("Possible");
		else
			puts("Not possible");
	}

	return 0;
}

/*
11729 - Commando War

greedy...
贪心
按照任务完成所需的时间降序排即可
*/

#include<iostream>
#include<algorithm>
#define MAXN 1010
using namespace std;

struct people
{
	int start,dur;
	bool operator <(const people &b)const
	{
		return dur>b.dur;
	}
}ppl[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1,n;
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<n;++i)
			scanf("%d%d",&ppl[i].start,&ppl[i].dur);
		sort(ppl,ppl+n);
		int cur=0,key=0;
		for(int i=0;i<n;++i)
		{
			cur+=ppl[i].start;
			key=max(key,ppl[i].dur+cur);
		}
		printf("Case %d: %d\n",cas++,key);
	}

	return 0;
}

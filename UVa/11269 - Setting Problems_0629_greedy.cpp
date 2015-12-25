/*
11269 - Setting Problems

greedy...
进程调度问题...
贪心即可...

考虑一个包含两个任务的子问题
A:(a.s,a.g),B:(b.s,b.g)
A->B:	[0,a.s]			[a.s,a.s+a.g]
		[a.s,a.s+b.s]	[max(a.s+b.s , a.s+a.g),max(a.s+b.s , a.s+a.g)+b.g]
		end time=max(a.s+b.s , a.s+a.g)+b.g
				=max(b.s,a.g)+a.s+b.g
B->A:	end time=max(a.s,b.g)+b.s+a.g
按照以上两个等式排序后从头到尾一次扫描即可...
*/

#include<iostream>
#include<algorithm>
#define MAXN 25
using namespace std;

struct TASK
{
	int Sultan,Golapibaba;
	bool operator<(const TASK &t)const
	{
		return max(t.Sultan,Golapibaba)+Sultan+t.Golapibaba
			<max(Sultan,t.Golapibaba)+t.Sultan+Golapibaba;
	}
}task[MAXN];
int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&task[i].Sultan);
		for(int i=0;i<n;++i)
			scanf("%d",&task[i].Golapibaba);

		sort(task,task+n);

		int Golapibaba=0,Sultan=0;
		for(int i=0;i<n;++i)
		{
			Sultan+=task[i].Sultan;
			Golapibaba=max(Sultan+task[i].Golapibaba,Golapibaba+task[i].Golapibaba);
		}
		printf("%d\n",Golapibaba);

	}

	return 0;
}

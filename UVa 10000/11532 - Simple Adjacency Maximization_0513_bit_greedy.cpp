/*
11532 - Simple Adjacency Maximization

bit...
greedy...
像师大校赛的最后一题...
p个1，q个0
最佳组合应该是
......110 110 110 1
即1与0的关系是p=2*q+1
当p>=2*q+1时应该对上式取反即1 011 011 011 ......
	然后将取反的式子与原式对比.取小即可
而p<2*q+1时,1偏少.直接贪心得到的一定是最小解...
*/

#include<iostream>
#define MAXN 64
using namespace std;

char key[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,p,q;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&p,&q);
		memset(key,0,sizeof(key));
		int l=p+q,cur=0;
		bool more=false;
		if(p>=2*q+1)	//这句话要放在前面啊...
			more=true;
		if(p)
			key[0]=1,--p;
		++cur;
		while(p || q)
		{
			if(q)
				++cur,--q;
			if(p)
				key[cur++]=1,--p;
			if(p)
				key[cur++]=1,--p;
		}
		long long ans=0;
		for(int i=l;i>=0;--i)
			ans=ans*2+key[i];
		if(more)
		{
			long long t=0;
			while(l>=0 && !key[l])
				--l;
			for(int i=0;i<=l;++i)
				t=t*2+key[i];
			ans=min(ans,t);
		}
		printf("%lld\n",ans);
	}

	return 0;
}

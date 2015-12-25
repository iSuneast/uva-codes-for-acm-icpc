/*
11353 - A Different Kind of Sorting

number theory...
O(NlogN) sieve
sort as the problem description
*/

#include<iostream>
#include<algorithm>
#define MAXN 2000001
using namespace std;

struct Factor
{
	int n,cnt;
	bool operator<(const Factor &t)const
	{
		if(cnt==t.cnt)
			return n<t.n;
		return cnt<t.cnt;
	}
}factor[MAXN];
bool flag[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	memset(factor,0,sizeof(factor));
	factor[1].n=1;

	for(int i=2;i<MAXN;++i)
	{
		factor[i].n=i;
		if(!flag[i])
			for(int j=i+i;j<MAXN;j+=i)
			{
				flag[j]=true;
				int t=j;
				while(t%i==0)
				{
					t/=i;
					++factor[j].cnt;
				}
			}
	}

	sort(factor,factor+MAXN);

	int n,cas=1;
	while(scanf("%d",&n)!=EOF && n)
		printf("Case %d: %d\n",cas++,factor[n].n);

	return 0;
}

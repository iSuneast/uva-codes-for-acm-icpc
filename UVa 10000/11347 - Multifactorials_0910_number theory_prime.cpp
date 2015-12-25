/*
11347 - Multifactorials

number theory...
prime...
factors...
use sieve to calculate all factors through 1~n and store in Array[n][p]
for each n store its factors in key[]
multiply{key[]+1} is the final answer
*/

#include<iostream>
#define MAXN 1001
using namespace std;
const long long INF=1000000000000000000LL;

int cnt[MAXN][MAXN],key[MAXN];
bool flag[MAXN];

void init()
{
	memset(flag,0,sizeof(flag));
	memset(cnt,0,sizeof(cnt));

	for(int i=2;i<MAXN;++i)
	{
		if(!flag[i])
		{
			for(int j=i;j<MAXN;j+=i)
			{
				flag[j]=true;
				int t=j;
				while(t%i==0)
				{
					cnt[j][i]++;
					t/=i;
				}
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,n;
	char s[23];
	init();

	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d%s",&n,s);
		if(!n)
		{
			printf("Case %d: 0\n",cas);
			continue;
		}

		memset(key,0,sizeof(key));
		int k=strlen(s);
		while(n>0)
		{
			for(int i=0;i<=n;++i)
				key[i]+=cnt[n][i];
			n-=k;
		}

		long long ans=1;
		for(int i=0;i<MAXN;++i)
		{
			ans*=(key[i]+1);
			if(ans>INF || ans<0)
			{
				ans=-1;
				break;
			}
		}

		if(ans!=-1)
			printf("Case %d: %lld\n",cas,ans);
		else
			printf("Case %d: Infinity\n",cas);
	}
	
	return 0;
}

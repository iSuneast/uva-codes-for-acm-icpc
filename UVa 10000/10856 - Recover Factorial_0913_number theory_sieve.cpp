/*
10856 - Recover Factorial

number theory...
sieve. prime...
use O(NlogN) sieve to calc the number of factors
and then use bsearch to located the answer is enough
*/

#include<iostream>
#include<algorithm>
#define MAXN 10000002
using namespace std;

bool flag[MAXN];
int cnt[MAXN],sum[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	for(int i=2;i<MAXN;++i)
	{
		if(!flag[i])
		{
			cnt[i]=1;
			for(int j=i+i;j<MAXN;j+=i)
			{
				flag[j]=true;
				int t=j;
				while(t%i==0)
				{
					++cnt[j];
					t/=i;
				}
			}
		}
		sum[i]=sum[i-1]+cnt[i];
	}

	int cas=1,n;
	while(scanf("%d",&n)!=EOF && n>=0)
	{
		int p=lower_bound(sum,sum+MAXN,n)-sum;
		if(sum[p]==n)
			printf("Case %d: %d!\n",cas++,p);
		else
			printf("Case %d: Not possible.\n",cas++);
	}

	return 0;
}

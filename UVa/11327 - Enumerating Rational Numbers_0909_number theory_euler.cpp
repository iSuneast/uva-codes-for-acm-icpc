/*
11327 - Enumerating Rational Numbers

number theory...
euler function...
calc the euler function and sum[n]=SUM{ phi(1~n) }
bsearch n in sum[], the position is "d"
and then use O(d) time to find "n" is enough
*/

#include<iostream>
#include<algorithm>
#define MAXN 200003
using namespace std;

bool flag[MAXN];
int phi[MAXN];
long long sum[MAXN],n;

void init()
{
	sum[1]=phi[1]=2;
	for(int i=2;i<MAXN;++i)
	{
		phi[i]=i;
	}

	for(int i=2;i<MAXN;++i)
	{
		if(!flag[i])
		{
			for(int j=i;j<MAXN;j+=i)
			{
				flag[j]=true;
				phi[j]=phi[j]/i*(i-1);
			}
		}
		sum[i]=phi[i]+sum[i-1];
	}
}

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	while(scanf("%lld",&n)!=EOF && n)
	{
		int p=lower_bound(sum,sum+MAXN,n)-sum;
		int k=n-sum[p-1],key;
		for(key=1;key<p;++key)
		{
			if(gcd(key,p)==1)
				if(!(--k))
					break;
		}
		if(n==1)
			key=0;

		printf("%d/%d\n",key,p);
	}

	return 0;
}

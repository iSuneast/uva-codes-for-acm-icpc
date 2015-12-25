/*
11466 - Largest Prime Divisor

number theory...
prime sieve...
*/

#include<iostream>
#define MAXN 10000000
#define PRIME 664580
using namespace std;

long long n;
int tot,prime[PRIME];
bool flag[MAXN];

void init()
{
	prime[tot++]=2;
	for(int i=3;i<MAXN;i+=2)
		if(!flag[i])
		{
			prime[tot++]=i;
			for(int j=i+i;j<MAXN;j+=i)
				flag[j]=true;
		}
}

long long process()
{
	if(n<0)
		n=-n;
	if(n<MAXN && (n%2 && !flag[n]))
		return -1;
	long long cur=n,key=-1;
	int cnt=0;
	for(int i=0;i<tot && cur>=prime[i];++i)
		if(cur%prime[i]==0)
		{
			++cnt;
			key=prime[i];
			while(cur%prime[i]==0)
				cur/=prime[i];
		}
	if(cnt>=1 && cur!=1)
		return cur;
	if(cnt==1)
		key=-1;
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	while(scanf("%lld",&n)!=EOF && n)
	{
		cout<<process()<<endl;
	}

	return 0;
}

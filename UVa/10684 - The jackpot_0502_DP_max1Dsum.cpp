/*
10684 - The jackpot

DP...
max 1D sum...
天哪...
竟然到今天才知道说一维序列的最大和有一个O(N)的算法...
我果然落后了...
dp[i]=max(dp[i-1]+var[i],var[i])
ans=max(ans,dp[i])
边界条件是
ans=dp[0]=var[0]
*/

#include<iostream>
#define max(a,b) ((a)>(b)?(a):(b))
#define MAXN 10010
using namespace std;

int dp[MAXN],var[MAXN],n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		scanf("%d",var);
		dp[0]=var[0];
		int key=dp[0];
		for(int i=1;i<n;++i)
		{
			scanf("%d",var+i);
			dp[i]=max(dp[i-1]+var[i],var[i]);
			key=max(dp[i],key);
		}
		if(key<=0)
			puts("Losing streak.");
		else
			printf("The maximum winning streak is %d.\n",key);
	}

	return 0;
}


/*
O(NlogN)的算法...

#include<iostream>
#define max(a,b) ((a)>(b)?(a):(b))
#define MAXN 10010
using namespace std;

int var[MAXN],n;

int max_sum(int start,int end)
{
	if(start>=end)
		return 0;
	else if(start+1==end)
		return var[start];
	int m=(start+end)>>1;
	int l=max_sum(start,m);
	int r=max_sum(m,end);
	int key=max(l,r);
	int v,i;
	l=var[m-1];
	v=0;
	for(i=m-1;i>=start;--i)
	{
		v+=var[i];
		l=max(l,v);
	}
	v=0;
	r=var[m];
	for(i=m;i<end;++i)
	{
		v+=var[i];
		r=max(r,v);
	}
	key=max(key,l+r);
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<n;++i)
			scanf("%d",var+i);
		int key=max_sum(0,n);
		if(key<=0)
			puts("Losing streak.");
		else
			printf("The maximum winning streak is %d.\n",key);
	}

	return 0;
}

*/
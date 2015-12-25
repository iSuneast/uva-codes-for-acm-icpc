/*
11856 - Ferry Loading V

dp...
the problem is all the same as "Tug Of War"
it's an O(n*n*100) DP
but the data in this problem is float number
*
* The total weight of vehicles on the port side should not
* differ from that on the starboard side by more than 2%
*
so we can try to convert the float number into integer
NewData[] = Data[]/Sum*20000 is quite enough...
then use DP to solve it...
*/

#include<iostream>
#define MAXN 20000
using namespace std;

struct DATA{int id,pre;}dp[MAXN+3];
double data[103];
int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		double sum=0;
		for(int i=0;i<n;++i)
		{
			scanf("%lf",&data[i]);
			sum+=data[i];
		}
		memset(dp,-1,sizeof(dp));
		dp[0].pre=-2;

		for(int i=n-1;i>=0;--i)
		{
			int cur=data[i]/sum*MAXN;
			for(int j=MAXN/2;j>=0;--j)
			{
				if(dp[j].pre==-1 || dp[j+cur].pre!=-1)
					continue;
				dp[j+cur].pre=j;
				dp[j+cur].id=i+1;
			}
		}

		for(int j=MAXN/2;j>=0;--j)
		{
			if(dp[j].pre!=-1)
			{
				printf("%d",dp[j].id);
				int cur=dp[j].pre;
				while(dp[cur].id>0)
				{
					printf(" %d",dp[cur].id);
					cur=dp[cur].pre;
				}
				putchar(10);
				break;
			}
		}
	}

	return 0;
}

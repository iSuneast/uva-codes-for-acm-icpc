/*
10465 - Homer Simpson

DP...
knapsack...
ACM生涯的第一道0-1背包问题...
WA了4次...
其实现在看来觉得背包问题其实也不会很难嘛...
什么东西都是这样...
理解了就好说...
关于背包的初始化....
dp[0]=1即可...
不要弄成dp[n[0]]=dp[n[1]]=1...
这样代码很挫..
*/

#include<iostream>
#define MAXN 10010
using namespace std;

int dp[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n[2],t;
	while(cin>>n[0]>>n[1]>>t)
	{
		int i,j;
		memset(dp,0,sizeof(dp));
		dp[0]=1;	//初始化...背包0可达...
		for(i=0;i<2;++i)
			for(j=0;j<=t;++j)
				if(j>=n[i] && dp[j-n[i]])
					dp[j]=max(dp[j],dp[j-n[i]]+1);
		if(dp[t])
			cout<<dp[t]-1<<endl;
		else for(int i=t;i>=0;--i)
				if(dp[i])
				{
					cout<<dp[i]-1<<" "<<t-i<<endl;
					break;
				}
	}

	return 0;
}

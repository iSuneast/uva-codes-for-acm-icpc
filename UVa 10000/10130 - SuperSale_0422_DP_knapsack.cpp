/*
10130 - SuperSale

DP...
knapsack...
又是一题传说中的背包...
*/

#include<iostream>
#define MAXN 1010
#define cap 33
using namespace std;

int p[MAXN],w[MAXN],dp[MAXN][cap];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int i,j,n,g,key=0,weight;
		cin>>n;
		for(i=0;i<n;++i)
			cin>>p[i]>>w[i];
		memset(dp,0,sizeof(dp));
		for(i=n-1;i>=0;--i)		//n种物品
			for(j=0;j<cap;++j)	//背包容量
			{
				dp[i][j]=(i==n-1?0:dp[i+1][j]);
				if(j>=w[i])
					dp[i][j]=max(dp[i][j],dp[i+1][j-w[i]]+p[i]);
			}
		cin>>g;
		for(i=0;i<g;++i)
		{
			cin>>weight;
			key+=dp[0][weight];
		}
		cout<<key<<endl;
	}

	return 0;
}

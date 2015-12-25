/*
990 - Diving for Gold

DP...
knapsack...
天啊...
背了一个晚上的背包都快背出杯具了...
还好终于是搞定了...
只要用一个fa数组保存父节点信息即可...
没有必要递归...
(主要原始写了半天递归一直是错的...呜~~~)
*/

#include<iostream>
#define MAXN 33
using namespace std;
typedef pair<int,int> pii;

pii gold[MAXN];
int dp[MAXN][1010],fa[MAXN][1010],cnt,n,w;
bool flag[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
//	freopen("990.txt","w",stdout);
#endif

	int tim,i,j;
	bool first=true;
	while(cin>>tim>>w)
	{
		if(!first)
			cout<<endl;
		first=false;
		cin>>n;
		for(i=1;i<=n;++i)
			cin>>gold[i].first>>gold[i].second;
		memset(dp,0,sizeof(dp));
		memset(fa,0,sizeof(fa));
		for(i=1;i<=n;++i)
			for(j=0;j<=tim;++j)
			{
				dp[i][j]=(i==1?0:dp[i-1][j]);
				if(j>=3*w*(gold[i].first))
				{
					if(dp[i][j]<dp[i-1][j-3*w*gold[i].first]+gold[i].second)
					{
						dp[i][j]=dp[i-1][j-3*w*gold[i].first]+gold[i].second;
						fa[i][j]=1;		//fa数组保存父节点信息...
					}
				}
			}
		cout<<dp[n][tim]<<endl;
		memset(flag,0,sizeof(flag));
		i=n;j=tim;
		cnt=0;
		while(i>0)
		{
			if(fa[i][j]!=0)		//父节点为前一个结点,并且前一个结点是解
			{
				flag[i]=1;
				j-=3*w*(gold[i].first);
				++cnt;
			}
			--i;
		}
		cout<<cnt<<endl;
		for(i=1;i<=n;++i)
			if(flag[i])
				cout<<gold[i].first<<" "<<gold[i].second<<endl;
	}

	return 0;
}

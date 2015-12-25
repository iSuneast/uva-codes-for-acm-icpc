/*
990 - Diving for Gold

DP...
knapsack...
�찡...
����һ�����ϵı������챳��������...
���������Ǹ㶨��...
ֻҪ��һ��fa���鱣�游�ڵ���Ϣ����...
û�б�Ҫ�ݹ�...
(��Ҫԭʼд�˰���ݹ�һֱ�Ǵ��...��~~~)
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
						fa[i][j]=1;		//fa���鱣�游�ڵ���Ϣ...
					}
				}
			}
		cout<<dp[n][tim]<<endl;
		memset(flag,0,sizeof(flag));
		i=n;j=tim;
		cnt=0;
		while(i>0)
		{
			if(fa[i][j]!=0)		//���ڵ�Ϊǰһ�����,����ǰһ������ǽ�
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

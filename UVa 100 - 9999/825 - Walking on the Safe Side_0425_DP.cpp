/*
825 - Walking on the Safe Side

DP...
经典模型...
不多说了...

发现输入数据格式有点问题...
之前直接用while((c=getchar())!='\r' && c!='\n')来判断输入结束
结果TLE...估计是在最后一个字符那里有个空格之类的...
*/

#include<iostream>
#define MAXN 1000
using namespace std;

int dp[MAXN][MAXN];
char buf[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int w,n,i,j,p,t;
		cin>>w>>n;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=w;++i)
		{
			scanf("%d",&p);
			gets(buf);
			char *token=strtok(buf," ");
			while(token)
			{
				sscanf(token,"%d",&t);
				dp[p][t]=-1;
				token=strtok(NULL," ");
			}
		}
		dp[1][1]=1;
		for(i=1;i<=w;++i)
			for(j=1;j<=n;++j)
				if(dp[i][j]!=-1)
				{
					if(dp[i-1][j]!=-1)
						dp[i][j]+=dp[i-1][j];
					if(dp[i][j-1]!=-1)
						dp[i][j]+=dp[i][j-1];
				}
		cout<<dp[w][n]<<endl;
		if(dataset)
			cout<<endl;
	}

	return 0;
}

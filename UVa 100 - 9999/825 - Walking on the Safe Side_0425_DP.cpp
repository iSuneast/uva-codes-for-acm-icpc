/*
825 - Walking on the Safe Side

DP...
����ģ��...
����˵��...

�����������ݸ�ʽ�е�����...
֮ǰֱ����while((c=getchar())!='\r' && c!='\n')���ж��������
���TLE...�����������һ���ַ������и��ո�֮���...
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

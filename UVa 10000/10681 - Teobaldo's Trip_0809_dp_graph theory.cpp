/*
10681 - Teobaldo's Trip

dp..
graph theory...
�ӵ�0�쿪ʼ,������ƿ���ȥ�ĳ���
dp[d][c]�����d����Ե������c
�����g[c][k],������c,k��ͨ��,dp[d+1][k]�ɴ�
*/

#include<iostream>
#define MAXN 103
#define MAXD 203
using namespace std;

bool dp[MAXD][MAXN],g[MAXN][MAXN];
int s,e,d,a,b,c,l;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&c,&l)!=EOF && (c||l))
	{
		memset(dp,0,sizeof(dp));
		memset(g,0,sizeof(g));
		while(l--)
		{
			scanf("%d%d",&a,&b);
			g[a][b]=g[b][a]=true;
		}
		scanf("%d%d%d",&s,&e,&d);

		dp[0][s]=true;
		for(int i=0;i<d;++i)
			for(int j=1;j<=c;++j)
				if(dp[i][j])
					for(int k=1;k<=c;++k)
						if(g[j][k])
							dp[i+1][k]=true;

		puts(dp[d][e]?"Yes, Teobaldo can travel.":"No, Teobaldo can not travel.");
	}

	return 0;
}

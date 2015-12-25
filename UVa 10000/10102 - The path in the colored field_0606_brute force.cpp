/*
10102 - The path in the colored field

brute force...
找出所有的'1''3'的格子,暴力匹配即可..
*/

#include<iostream>
#include<cmath>
#define MAXN 100
#define INF 0x7f7f7f7f
using namespace std;
typedef pair<int,int> pii;

pii p1[MAXN*MAXN],p3[MAXN*MAXN];
char g[MAXN][MAXN];
int n,sz1,sz3;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF)
	{
		sz1=sz3=0;
		int key=0;
		for(int i=0;i<n;++i)
		{
			scanf("%s",g[i]);
			for(int j=0;g[i][j];++j)
				if(g[i][j]=='1')
					p1[sz1++]=make_pair(i,j);
				else if(g[i][j]=='3')
					p3[sz3++]=make_pair(i,j);
		}
		for(int i=0;i<sz1;++i)
		{
			int cur=INF;
			for(int j=0;j<sz3;++j)
			{
				int t=abs(p1[i].first-p3[j].first)+abs(p1[i].second-p3[j].second);
				cur=min(t,cur);
			}
			key=max(cur,key);
		}
		printf("%d\n",key);
	}

	return 0;
}

/*
10507 - Waking up brain

brute force...
keep looping while we can find an answer
just expand the node with three ancestor node
*/

#include<iostream>
#define MAXN 30
using namespace std;
const int INF=0x3f3f3f3f;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	bool g[MAXN][MAXN];
	int n,m,dis[MAXN];
	char buf[MAXN];

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(g,0,sizeof(g));
		memset(dis,0x3f,sizeof(dis));

		scanf("%s",buf);
		for(int i=0;buf[i];++i)
		{
			dis[ buf[i]-'A' ]=0;
			--n;
		}

		while(m--)
		{
			scanf("%s",buf);
			g[ buf[0]-'A' ][ buf[1]-'A' ]=g[ buf[1]-'A' ][ buf[0]-'A' ]=true;
		}

		int dep=0;
		bool more=true;
		while(more)
		{
			more=false;

			for(int u=0;u<MAXN;++u)
			{
				if(dis[u]!=INF)
					continue;
				int cnt=0;
				for(int v=0;v<MAXN;++v)
					if(g[u][v] && dis[v]<=dep)
						++cnt;
				if(cnt>=3)
				{
					dis[u]=dep+1;
					--n;
					more=true;
				}
			}

			++dep;
		}

		if(!n)
			printf("WAKE UP IN, %d, YEARS\n",dep-1);
		else
			printf("THIS BRAIN NEVER WAKES UP\n");
	}

	return 0;
}

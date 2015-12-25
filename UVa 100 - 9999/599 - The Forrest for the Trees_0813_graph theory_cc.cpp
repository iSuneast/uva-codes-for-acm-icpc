/*
599 - The Forrest for the Trees

graph theory...
cc...
算图的连通分支个数...
*/

#include<iostream>
#define MAXN 128
using namespace std;

char buf[MAXN],u,v;
int fa[MAXN],cnt[MAXN];
bool flag[MAXN];

int find(int u)
{
	return u==fa[u]?u:fa[u]=find(fa[u]);
}

void merge(int u,int v)
{
	int a=find(u),b=find(v);
	if(a!=b)
	{
		fa[a]=b;
		cnt[b]+=cnt[a];
		cnt[a]=0;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		for(int i='A';i<='Z';++i)
		{
			flag[i]=false;
			cnt[i]=1;
			fa[i]=i;
		}
		while(scanf("%s",buf)!=EOF && buf[0]!='*')
		{
			u=buf[1],v=buf[3];
			flag[u]=flag[v]=true;
			merge(u,v);
		}

		scanf("%s",buf);
		char *token=strtok(buf,",");
		while(token)
		{
			flag[ token[0] ]=true;
			token=strtok(NULL,",");
		}

		int tree=0,acorn=0;
		for(int u='A';u<='Z';++u)
			if(flag[u])
			{
				if(cnt[u]==1)
					acorn++;
				else if(cnt[u]>1)
					tree++;
			}

			printf("There are %d tree(s) and %d acorn(s).\n",tree,acorn);
	}

	return 0;
}

/*
10092 - The Problem with the Problem Setter

graph theory...
hungry...
¼ÌÐøÐÙÑÀÀû...
*/

#include<iostream>
#define MAXN 1200
using namespace std;

bool g[MAXN][MAXN],flag[MAXN];
int n_k,n_p,category[MAXN],ps[MAXN],tot,match[MAXN];

int dfs(int u)
{
	for(int i=0;i<tot;++i)
		if(g[u][i] && !flag[i])
		{
			flag[i]=true;
			int t=match[i];
			match[i]=u;
			if(t==-1 || dfs(t))
				return 1;
			match[i]=t;
		}
	return 0;
}

int hungry()
{
	int key=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<tot;++i)
	{
		memset(flag,0,sizeof(flag));
		key+=dfs(i);
	}
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n_k,&n_p) && (n_k||n_p))
	{
		int sum=0;
		for(int i=0;i<n_k;++i)
		{
			scanf("%d",category+i);
			ps[i]=sum;
			sum+=category[i];
		}
		ps[n_k]=sum;
		tot=sum+n_p;

		int cnt,p,cur;
		memset(g,0,sizeof(g));
		for(int i=0;i<n_p;++i)
		{
			scanf("%d",&cnt);
			cur=sum+i;
			while(cnt--)
			{
				scanf("%d",&p);
				for(int j=ps[p-1];j<ps[p];++j)
					g[cur][j]=g[j][cur]=true;
			}
		}

		int key=hungry()/2;
		if(key==sum)
		{
			puts("1");
			for(int i=0;i<n_k;++i)
			{
				bool first=true;
				for(int j=ps[i];j<ps[i+1];++j)
				{
					if(!first)
						putchar(' ');
					first=false;
					printf("%d",match[j]-sum+1);
				}
				putchar('\n');
			}
		}
		else
			puts("0");
	}

	return 0;
}

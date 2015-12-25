/*
 * 11902 - Dominator
 * 
 * graph theory...
 * cut-node...
 * you have to check whether the nodes are connected with 0 before further process...
 * 
 * happy coding...
 */

#include<cstdio>
#include<cstring>
#define MAXN 103
using namespace std;

int g[MAXN][MAXN], n;
bool key[MAXN][MAXN], flag[MAXN], IcanC[MAXN];

void output()
{
	for(int i=0;i<n;++i)
	{
		putchar('+');
		for(int j=1;j<(n<<1);++j)
		{
			putchar('-');
		}
		puts("+");
		
		for(int j=0;j<n;++j)
		{
			printf("|%c",key[i][j]?'Y':'N');
		}
		puts("|");
	}
	
	putchar('+');
	for(int j=1;j<(n<<1);++j)
		putchar('-');
	puts("+");
}

void read()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			scanf("%d",&g[i][j]);
		}
		g[i][i]=0;
	}
}

void dfs(int u,int fade)
{
	if(u==fade)
		return ;
	flag[u]=true;
	for(int v=0;v<n;++v)
	{
		if(g[u][v] && !flag[v])
			dfs(v, fade);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
    	read();
    	
		memset(flag,0,sizeof(flag));
		dfs(0,-1);
		memcpy(IcanC,flag,sizeof(flag));
    	
    	for(int i=0;i<n;++i)
    	{
    		memset(flag,0,sizeof(flag));
    		dfs(0,i);
    		for(int j=0;j<n;++j)
    		{
    			key[i][j]=(IcanC[j] && !flag[j]);
    		}
    	}

    	printf("Case %d:\n",cas);
    	output();
    }

    return 0;
}


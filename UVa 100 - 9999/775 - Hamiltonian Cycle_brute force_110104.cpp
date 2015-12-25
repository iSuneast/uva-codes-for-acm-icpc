/*
 * 775 - Hamiltonian Cycle
 * 
 * brute force...
 * just a simple dfs function will make sense...
 * try it !
 */

#include<cstdio>
#include<cstring>
#define MAXN 260

bool g[MAXN][MAXN],flag[MAXN],fade;
int n,key[MAXN];

void output()
{
	fade=false;
	for(int i=0;i<n;++i)
		printf("%d ",key[i]);
	puts("1");	
}

void dfs(int u,int dep)
{
	if(!fade)
		return ;
	if(dep==n)
	{
		if(g[ key[dep-1] ][1])
			return output();
	}
	for(int v=1;v<=n;++v)
		if(g[u][v] && !flag[v])
		{
			flag[v]=true;
			key[dep]=v;
			dfs(v,dep+1);
			flag[v]=false;
		}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int u,v;
    char s[100];
    while(scanf("%d",&n)!=EOF)
    {
    	gets(s);
    	memset(g,0,sizeof(g));
    	while(gets(s) && s[0]!='%')
    	{
    		sscanf(s,"%d%d",&u,&v);
    		g[u][v]=g[v][u]=true;
    	}
    	
    	if(n<3)
    		puts("N");
    	else
    	{
        	memset(flag,0,sizeof(flag));
    		fade=true;
    		key[0]=1;	flag[1]=true;
        	dfs(1,1);
        	if(fade)
        		puts("N");
    	}
    }

    return 0;
}


/*
11138 - Nuts and Bolts

graph theory...
binary match...
it's quite a simple binary match problem
you can even use the most part of the code in the problem description...
*/

#include<iostream>
#define MAX_BOLTS 500
#define MAX_NUTS  500
using namespace std;

int nuts,bolts;
int fits[MAX_BOLTS][MAX_NUTS],match[MAX_NUTS];
bool flag[MAX_NUTS];

void read_input_data(void)
{
	scanf("%d%d",&bolts,&nuts);
	for(int b=0;b<bolts;b++)
		for(int n=0;n<nuts;n++)
			scanf("%d",&fits[b][n]);
}

bool dfs(int u)
{
	for(int v=0;v<nuts;++v)
		if(fits[u][v] && !flag[v])
		{
			flag[v]=true;
			if(match[v]==-1 || dfs(match[v]))
			{
				match[v]=u;
				return true;
			}
		}
	return false;
}

int hungry()
{
	memset(match,-1,sizeof(match));
	int key=0;
	for(int i=0;i<bolts;++i)
	{
		memset(flag,0,sizeof(flag));
		key+=dfs(i)?1:0;
	}
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cases,caseno;
	scanf("%d",&cases);
	for(caseno=1;caseno<=cases;caseno++)
	{
		read_input_data();
		printf("Case %d: ",caseno);
		printf("a maximum of %d nuts and bolts ",hungry());
		printf("can be fitted together\n");
	}

	return 0;
}

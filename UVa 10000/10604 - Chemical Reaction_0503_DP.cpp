/*
10604 - Chemical Reaction

DP...
花了好大力气做的一道DP题...
又是传说中的状态转移DP...
之前一直没有找到好的状态转移方法...
后来发现状态按另一个方向想的话...
就变得很简单了...

其实可以按化学物品的类型压缩...
而不是按下一个状态的具体形态压缩...

解释一下sample的压缩方法就很明显了...
	--- 1 2 2 3	可以转化为
类型 1 数量 1
类型 2 数量 2
类型 3 数量 1
即状态变为	121
则,状态转化变得很简单了...
121	->	*11+() || 1*1+() || 11*+() ->...
由于最多有10个试管所以压缩到11进制的数里面...
每次要用的时候化回来出来即可...

此题还有一个很重要的地方...
不要轻易地对题目没有描述清楚地地方做出假设...
要知道说(1,3)混合与(3,1)混合是不等价的...
虽然这并不影响状态转移...
但是错误的假设得出的结论自然也是错误的...
WA了N次的代价...
*/

#include<iostream>
#define MAXSTATE 1610510
#define MAXN 10
#define MOD 11
#define INF 0x7f7f7f7f
using namespace std;

int state[MAXSTATE],var[MAXN],n,m;
struct pii
{
	int first,second;
}g[MAXN][MAXN];

int hash()
{
	int key=0;
	for(int i=1;i<=n;++i)
		key=key*MOD+var[i];
	return key;
}

int dp(int cur)
{
	if(state[cur]!=INF)
		return state[cur];
	else
	{
		bool done=false;
		for(int i=1;i<=n;i++)
			if(var[i])
				for(int j=i;j<=n;++j)
					if((j==i && var[j]>1) || (j>i && var[j]))
					{
						--var[i];
						--var[j];
						++var[ g[i][j].first ];
						int t=dp(hash())+g[i][j].second;
						--var[ g[i][j].first ];
						state[cur]=min(state[cur],t);
						++var[ g[j][i].first ];
						t=dp(hash())+g[j][i].second;
						state[cur]=min(state[cur],t);
						--var[ g[j][i].first ];
						++var[i];
						++var[j];
						done=true;
					}
		if(!done)
			state[cur]=0;
		return state[cur];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		int i,j;
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				scanf("%d%d",&g[i][j].first,&g[i][j].second);
		scanf("%d",&m);
		int t;
		memset(var,0,sizeof(var));
		for(i=0;i<m;++i)
		{
			scanf("%d",&t);
			++var[t];
		}
		memset(state,0x7f,sizeof(state));
		printf("%d\n",dp(hash()));
		char c;
		while((c=getchar())!='/' && c!='.')	;
	}

	return 0;
}

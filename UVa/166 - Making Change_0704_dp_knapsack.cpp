/*
166 - Making Change

dp...
knapsack...
经典的换硬币问题...
不过既然规模这么小..
直接搜索吧...
*/

#include<iostream>
#define INF 0x7f7f7f7f
#define eps 1e-9
#define MAXN 6
#define MAXCOIN 501
using namespace std;

const int var[]={5,10,20,50,100,200};
int coin[MAXN],tot,dp[MAXCOIN],state[MAXCOIN];

bool input()
{
	bool bk=true;
	for(int i=0;i<MAXN;++i)
	{
		scanf("%d",coin+i);
		if(coin[i])
			bk=false;
	}
	return !bk;
}

void init()
{
	memset(dp,0x7f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<MAXCOIN;++i)
		for(int j=0;j<MAXN;++j)
			if(i-var[j]>=0)
				dp[i]=min(dp[i],dp[ i-var[j] ]+1);
}

void dfs(int u)
{
	for(int i=0;i<MAXN;++i)
		if(coin[i] && var[i]+u<MAXCOIN)
			if(state[u]+1<state[ var[i]+u ])
			{
				state[ var[i]+u ]=state[u]+1;
				--coin[i];
				dfs(var[i]+u);
				++coin[i];
			}
}

void format()
{
	coin[0]=min(coin[0],100);
	coin[1]=min(coin[1],50);
	coin[2]=min(coin[2],25);
	coin[3]=min(coin[3],10);
	coin[4]=min(coin[4],5);
	coin[5]=min(coin[5],2);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	while(input())
	{
		format();
		memset(state,0x7f,sizeof(state));
		state[0]=0;
		dfs(0);

		double t;
		scanf("%lf",&t);
		tot=t*100+eps;	//有精度问题

		int key=INF;
		for(int i=tot;i<MAXCOIN;++i)
			if(state[i]!=INF)
				key=min(key,state[i]+dp[i-tot]);
		printf("%3d\n",key);
	}

	return 0;
}

/*
完全背包解法...
#include<iostream>
#define INF 0x7f7f7f7f
#define eps 1e-9
#define MAXN 6
#define MAXCOIN 501
using namespace std;

const int var[]={5,10,20,50,100,200};
int coin[MAXN],tot,dp[MAXCOIN],state[MAXCOIN];

bool input()
{
	bool bk=true;
	for(int i=0;i<MAXN;++i)
	{
		scanf("%d",coin+i);
		if(coin[i])
			bk=false;
	}
	return !bk;
}

void init()
{
	memset(dp,0x7f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<MAXCOIN;++i)
		for(int j=0;j<MAXN;++j)
			if(i-var[j]>=0)
				dp[i]=min(dp[i],dp[ i-var[j] ]+1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	while(input())
	{
		memset(state,0x7f,sizeof(state));
		state[0]=0;
		for(int i=0;i<MAXN;++i)
			for(int j=0;j<coin[i];++j)
				for(int k=MAXCOIN-1;k>=0;--k)
					if(k>=var[i])
						state[k]=min(state[k],state[ k-var[i] ]+1);
					else
						break;

		double t;
		scanf("%lf",&t);
		tot=t*100+eps;	//有精度问题

		int key=INF;
		for(int i=tot;i<MAXCOIN;++i)
			if(state[i]!=INF)
				key=min(key,state[i]+dp[i-tot]);
		printf("%3d\n",key);
	}

	return 0;
}

*/
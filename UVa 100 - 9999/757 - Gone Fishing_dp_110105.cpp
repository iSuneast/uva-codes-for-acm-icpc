/*
 * 757 - Gone Fishing
 * 
 * dp...
 * if we don't need to print out the solution, the problem is quite a simple DP problem
 * but we have to consider the time spend in each lake now in descending order
 * don't use fa[][] array to store the best path you current find
 * but try to find out all the valid best path and choose the best one...
 * 
 * done!
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 30
#define TIME 200
using namespace std;
typedef pair<int,int> pii;

int n,h;
int f[MAXN],d[MAXN],t[MAXN];
int dp[MAXN][TIME],spend_here[MAXN][TIME];
pii fa[MAXN][TIME];

void read()
{
	scanf("%d",&h);	h*=12;
	for(int i=0;i<n;++i)
		scanf("%d",&f[i]);
	for(int i=0;i<n;++i)
		scanf("%d",&d[i]);
	for(int i=1;i<n;++i)
		scanf("%d",&t[i]);
}

void ChkMax(int &v,int t)
{
	if(v<t)
		v=t;
}

struct ANS
{
	int time[MAXN];
	bool operator<(const ANS &t)const
	{
		for(int i=0;i<n;++i)
			if(time[i]!=t.time[i])
				return time[i]<t.time[i];
		return false;
	}
	void init()
	{
		memset(time,0,sizeof(time));
	}
}tmp,key;

void dfs(int lake,int cur)
{
	int sh=spend_here[lake][cur];
	if(lake)
		dfs(fa[lake][cur+sh].first,fa[lake][cur+sh].second);
	tmp.time[lake]+=sh;
}

void DynamicP()
{
	memset(dp,-1,sizeof(dp));
	memset(fa,-1,sizeof(fa));
	memset(spend_here,0,sizeof(spend_here));
	
	dp[0][h]=0;
	int max_fish=0;
	
	for(int lake=0;lake<n;++lake)
	{
		for(int cur=0;cur<=h;++cur)		//fishing in current lake
		{
			if(dp[lake][cur]>=0)
			{
				int rem_fish=f[lake],add=dp[lake][cur];
				for(int rem_time=cur-1;rem_time>=0;rem_time--)
				{
					add+=rem_fish;
					if(dp[lake][rem_time]<add)
					{
						dp[lake][rem_time]=add;
						spend_here[lake][rem_time]=cur-rem_time;
					}
					
					rem_fish-=d[lake];
					if(rem_fish<=0)
						break;
				}
			}
		}

		for(int cur=0;cur<=h;++cur)		//generate ANSWER
		{
			ChkMax(max_fish,dp[lake][cur]);
		}
		
		if(lake+1!=n)		//go to next lake
			for(int cur=t[lake+1];cur<=h;++cur)
			{
				if(dp[lake+1][ cur-t[ lake+1 ] ] < dp[lake][cur])
				{
					dp[lake+1][ cur-t[ lake+1 ] ] = dp[lake][cur];
					fa[lake+1][ cur-t[ lake+1 ] ] = make_pair(lake,cur);
				}
			}
	}
	
	key.init();
	for(int lake=0;lake<n;++lake)
	{
		for(int cur=0;cur<=h;++cur)
			if(dp[lake][cur]==max_fish)
			{
				tmp.init();
				tmp.time[0]+=cur;
				dfs(lake,cur);
				if(key<tmp)
					key=tmp;				
			}
	}
	
	for(int i=0;i<n;++i)
		printf( (i+1!=n?"%d, ":"%d\n"),key.time[i]*5 );
	printf("Number of fish expected: %d\n",max_fish);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    bool first=true;
    while(scanf("%d",&n)!=EOF && n)
    {
    	if(!first)
    		putchar(10);
    	first=false;
    	
    	read();
    	DynamicP();
    }

    return 0;
}


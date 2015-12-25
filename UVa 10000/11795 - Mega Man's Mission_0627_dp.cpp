/*
11795 - Mega Man's Mission

dp..
状态dp
用pair保存当前状态
@	first-保存robot是否被消灭
@	second-保存是否可以消灭robot
然后判断robot[i]是否是当前状态的可行解,
	是的话就转移...
*/

#include<iostream>
#include<queue>
#define MAXN 16
using namespace std;
typedef pair<int,int> pii;
//first-保存robot是否被消灭,second-保存是否可以消灭robot

long long state[1<<MAXN];
int n,robot[MAXN];
pii mega;
char buf[MAXN+3];

long long dp(pii cur)
{
	queue<pii> q;
	q.push(cur);
	while(!q.empty())
	{
		cur=q.front();	q.pop();
		for(int i=0;i<n;++i)
			if(!(cur.first&(1<<i)) && cur.second&(1<<i) )
			{
				pii tmp;
				tmp.first=cur.first+(1<<i);
				tmp.second=cur.second|robot[i];
				if(!state[tmp.first])
					q.push(tmp);
				state[tmp.first]+=state[cur.first];
			}
	}
	return state[(1<<n)-1];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d",&n);

		mega=make_pair(0,0);
		scanf("%s",buf);
		for(int i=0;i<n;++i)
			if(buf[i]=='1')
				mega.second+=1<<i;

		for(int j=0;j<n;++j)
		{
			scanf("%s",buf);
			robot[j]=0;
			for(int i=0;i<n;++i)
				if(buf[i]=='1')
					robot[j]+=1<<i;
		}
		memset(state,0,sizeof(state));
		state[0]=1;

		printf("Case %d: %lld\n",cas,dp(mega));
	}

	return 0;
}

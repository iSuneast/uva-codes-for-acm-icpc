/*
11730 - Number Transformation

numbe theory...
graph theory...
BFS...

素数打表.
BFS的时候注意s==t的特殊情况
*/

#include<iostream>
#define MAXN 1010
using namespace std;

int s,t,dis[MAXN],prime[MAXN],q[MAXN],factors[MAXN],cnt;

void init()
{
	memset(prime,0,sizeof(prime));
	cnt=0;
	prime[cnt++]=2;
	for(int i=3;i<MAXN;i+=2)
	{
		if(!prime[i])
		{
			prime[cnt++]=i;
			for(int j=i+i;j<MAXN;j+=i)
				prime[j]=-1;
		}
	}
}

int prime_factors(int n)
{
	int key=0;
	for(int i=0;i<cnt;++i)
		if(n<=prime[i])
			break;
		else if(n%prime[i]==0)
			factors[key++]=prime[i];
	return key;
}

int bfs()
{
	if(s==t)
		return 0;
	memset(dis,-1,sizeof(dis));
	int front=0,rear=0;
	q[rear++]=s;
	dis[s]=0;
	while(front<rear)
	{
		int cur=q[front++];
		int key=prime_factors(cur);
		for(int i=0;i<key;++i)
		{
			int n=cur+factors[i];
			if(n==t)
				return dis[cur]+1;
			else if(n<t && dis[n]==-1)
			{
				dis[n]=dis[cur]+1;
				q[rear++]=n;
			}
		}
	}
	return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	init();
	while(scanf("%d%d",&s,&t)!=EOF && (s||t))
		printf("Case %d: %d\n",cas++,bfs());

	return 0;
}

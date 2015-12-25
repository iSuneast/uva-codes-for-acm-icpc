/*
10594 - Data Flow

graph theory
min-cost-max-flow...
天哪...
WA到没谱了...
我估计我使用的算法也是对的...
可能是有什么特殊情况是lrj的算法过不了的?
*/

/*
10594 - Data Flow

graph theory
min-cost-max-flow...
天哪...
WA到没谱了...
我估计我使用的算法也是对的...
可能是有什么特殊情况是lrj的算法过不了的?
*/

#include<iostream>
#include<queue>
#define MAXN 110
#define INF 1e17
using namespace std;
typedef long long ll;

ll cap,flow[MAXN][MAXN],cost[MAXN][MAXN],totalflow,d[MAXN];
ll m,fa[MAXN],start=1,target;
ll key;
bool inq[MAXN],flag[MAXN][MAXN],fresh[MAXN];	//fresh标记某个点的流量是否有更新.inq标记某个点是否已在队列里面

bool min_cost_max_flow()		//SSP
{
	queue<ll> q;
	memset(flow,0,sizeof(flow));
	ll u,v;
	for(ll remflow=totalflow;totalflow>0;remflow=totalflow-=remflow)	//remflow更新每次增广的流量
	{
		fill_n(d,MAXN,INF);
		d[start]=0;
		q.push(start);
		memset(fresh,0,sizeof(fresh));
		while(!q.empty())
		{
			u=q.front();	q.pop();
			inq[u]=false;
			for(v=start;v<=target;++v)
				if(flag[u][v])
				{
					if(flow[u][v]<cap && d[v]>d[u]+cost[u][v])	//正向流量
					{
						d[v]=d[u]+cost[u][v];
						fa[v]=u;
						fresh[v]=true;
						if(!inq[v])
						{
							inq[v]=true;
							q.push(v);
						}
					}
					if(flow[v][u]>0 && d[v]>d[u]-cost[v][u])		//反向流量
					{
						d[v]=d[u]-cost[v][u];
						fa[v]=u;
						fresh[v]=false;
						if(!inq[v])
						{
							inq[v]=true;
							q.push(v);
						}
					}
				}
		}
		if(d[target]==INF)	//无增广
			return false;
		for(u=target;u!=start;u=fa[u])		//逆序枚举可增广的流量
			remflow=min(remflow,fresh[u]?cap-flow[fa[u]][u]:flow[u][fa[u]]);
		for(u=target;u!=start;u=fa[u])		//增广
			fresh[u]?flow[fa[u]][u]+=remflow:flow[u][fa[u]]-=remflow;
	}
	key=0;
	for(u=start;u<=target;++u)
		for(v=start;v<=target;++v)
			if(flag[u][v])
				key+=flow[u][v]*cost[u][v];
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("10594.txt","w",stdout);
#endif

	while(cin>>target>>m)
	{
		ll i,j,s,e;
		memset(flag,0,sizeof(flag));
		for(i=0;i<m;++i)
		{
			cin>>s>>e>>cap;
			cost[s][e]=cost[e][s]=cap;
			flag[s][e]=flag[e][s]=true;
		}
		cin>>totalflow>>cap;
		if(min_cost_max_flow())
			cout<<key<<endl;
		else
			cout<<"Impossible."<<endl;
	}

	return 0;
}

/*
以下代码为刘汝佳推荐使用的min cost max flow算法...
除了min_cost_max_flow部分代码不一样以外...
main函数和上面的AC代码是一样的...
可是为什么这个版本就是一直WA?
明明是可以过BBS所有的数据的...
---------------------------------------------------------
long long cap[MAXN][MAXN],flow[MAXN][MAXN],cost[MAXN][MAXN],totalflow,d[MAXN];
long long m,p[MAXN],start=1,target;
long long key,c;
bool inq[MAXN],flag[MAXN][MAXN];

long long my_flow()
{
	key=0;
	for(long long i=start;i<=target;++i)
		for(long long j=start;j<i;++j)
			if(flow[i][j])
			{
				if(flow[i][j]>0)
					key+=flow[i][j]*cost[i][j];
				else
					key-=flow[i][j]*cost[i][j];
			}
}

bool min_cost_max_flow()
{
	queue<long long> q;
	memset(flow,0,sizeof(flow));
	long long u,v;
	while(true)
	{
		fill_n(d,MAXN,INF);
		d[start]=0;
		q.push(start);
		while(!q.empty())			//bellman-ford找增广路
		{
			u=q.front();	q.pop();
			inq[u]=false;
			for(v=start;v<=target;++v)
				if(cap[u][v]>flow[u][v] && d[v]>d[u]+cost[u][v])
				{
					d[v]=d[u]+cost[u][v];
					p[v]=u;
					if(!inq[v])
					{
						inq[v]=true;
						q.push(v);
					}
				}
		}
		if(d[target]==INF)
			return false;
		long long cur=INF;
		for(u=target;u!=start;u=p[u])
			cur=min(cur,cap[p[u]][u]-flow[p[u]][u]);
		if(cur>totalflow)
		{
			cur=totalflow;totalflow=0;
		}
		else
			totalflow-=cur;
		for(u=target;u!=start;u=p[u])
		{
			flow[p[u]][u]+=cur;
			flow[u][p[u]]-=cur;
		}
		if(!totalflow)
		{
			my_flow();
			return true;
		}
	}
}
*/

/*
sample input

4 4
1 3 3
3 4 4
1 2 2
2 4 5
20 100
8 11
1 2 0
1 3 0
1 4 0
5 8 0
6 8 0
7 8 0
2 6 1
3 7 1
2 5 2
3 6 2
4 7 2
3 1
4 4
1 3 3
3 4 4
1 2 2
2 4 5
20 1
4 5
1 4 1
1 3 3
3 4 4
1 2 2
2 4 5
20 10
10 16
1 9 8
6 9 7
7 9 83
10 9 6
8 9 64
3 9 62
4 9 59
2 4 29
4 8 29
8 5 64
3 5 40
6 5 2
10 5 76
5 7 70
4 7 7
7 1 21
805 22349
10 18
2 1 13
10 1 54
8 1 28
3 1 88
5 1 8
7 1 86
6 1 32
4 1 75
9 1 60
4 5 8
9 5 17
6 5 55
5 3 52
2 3 50
4 3 41
3 9 66
6 9 44
10 9 35
20235 21705
10 40
4 9 13
7 9 90
9 2 76
3 2 63
2 5 83
6 5 27
5 4 21
7 4 25
1 4 74
9 1 58
7 1 64
10 1 53
5 1 80
3 1 66
6 1 5
10 4 51
6 4 86
2 4 55
8 4 40
8 1 19
2 1 92
8 10 37
5 8 26
2 8 76
6 8 23
8 3 11
4 3 12
6 3 43
7 3 10
9 3 75
5 3 33
7 6 53
10 5 59
5 7 100
7 10 52
9 10 96
3 10 44
2 10 46
5 9 73
6 9 87
9750 13344
10 38
4 9 83
5 9 52
9 7 63
1 7 30
6 7 6
2 7 48
8 7 85
10 7 4
4 7 56
3 7 21
6 1 68
2 1 98
9 1 3
3 1 12
10 1 88
4 1 31
5 1 82
8 1 15
9 2 27
8 2 67
3 2 46
4 2 95
6 2 81
5 2 14
10 2 3
3 4 39
6 4 18
10 4 89
8 4 86
5 4 67
5 3 64
8 3 7
9 3 29
5 7 50
5 8 65
10 8 20
10 3 87
6 3 54
24639 8190
10 11
6 3 53
9 3 4
5 3 44
3 4 55
8 4 71
6 4 43
1 4 86
2 4 89
9 4 8
5 4 89
10 4 96
4972 23026
10 0
26969 1206
10 39
9 4 13
10 4 98
1 4 68
5 4 95
8 4 92
2 1 3
9 1 47
8 1 7
6 1 72
7 1 10
1 10 48
5 10 90
3 5 78
8 5 54
7 5 8
9 5 72
2 5 12
1 5 78
6 5 87
2 3 95
10 2 60
8 2 16
2 6 25
7 6 45
6 10 36
7 10 8
3 1 39
4 2 1
9 2 61
7 2 49
6 8 42
10 8 13
3 7 70
9 10 81
3 10 23
3 8 27
7 8 18
9 8 78
3 9 40
32702 15084
10 9
9 5 49
2 5 1
5 6 75
2 6 5
10 6 6
9 6 23
7 6 25
1 6 45
3 6 40
4124 28230
10 37
2 6 44
6 7 4
5 7 12
3 7 36
10 7 47
8 7 61
2 7 43
5 6 72
3 6 27
6 10 61
5 10 9
4 10 75
10 8 56
6 8 83
4 8 13
5 8 93
2 8 82
3 8 26
1 3 57
4 3 96
9 3 66
5 3 57
2 3 93
10 3 19
9 7 69
1 7 8
4 7 64
9 5 66
5 2 49
1 2 12
4 2 1
9 2 48
2 10 24
9 10 7
6 9 57
1 9 13
8 9 50
22137 19596
10 11
4 9 66
2 9 36
3 9 97
7 9 41
5 9 88
1 9 49
6 9 94
8 9 14
10 9 80
5 4 78
7 5 7
19920 24127
8 11
1 2 0
1 3 0
1 4 0
5 8 0
6 8 0
7 8 0
2 6 1
3 7 1
2 5 2
3 6 2
4 7 2
3 1
10 10
1 2 3
2 3 4
3 4 5
4 5 6
5 6 7
6 7 8
8 9 10
10 2 12
2 7 1
3 9 0
1 1
10 10
1 2 3
2 3 4
3 4 5
4 5 6
5 6 7
6 7 8
8 9 10
10 2 12
2 7 1
3 9 0
5000 800
10 3
1 2 3
2 3 4
10 2 12
1 1
2 1
2 2 1
1 800
10 10
1 2 3
2 3 4
3 4 5
4 5 6
5 6 7
6 7 8
8 9 10
10 2 12
2 7 1
3 9 0
100 800
*/

/*
sample output

140
6
Impossible.
80
11270
1092690
516750
841452
904904
Impossible.
694824
210324
465609
2569680
6
15
Impossible.
15
Impossible.
1500

*/
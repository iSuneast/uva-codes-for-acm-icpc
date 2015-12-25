/*
10801 - Lift Hopping

晕,这题做得好辛苦啊...
Dijkstra...
*/

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#define min(a,b) ((a)<(b))?(a):(b)
#define MAXN 100
#define MAXLIFT 5
#define INF 1e8
#define TIMEOUT 60
using namespace std;

typedef pair<int,int> pii;
int d[MAXN*MAXLIFT],flag[MAXN*MAXLIFT],t[MAXLIFT],n,k;
vector<pii> vi[MAXLIFT*MAXN];
priority_queue<pii,vector<pii>,greater<pii> > pq;

void dijkstra()
{
	int p=0,i,sz,dis;
	for(i=0;i<n;i++)	//记得是从第一层开始乘坐电梯的...此时所有的电梯都可以坐.且d[]=0
		pq.push(make_pair(d[i*MAXN]=0,i*MAXN));
	pii cur;
	memset(flag,0,sizeof(flag));
	while(!pq.empty())
	{
		cur=pq.top();	pq.pop();
		p=cur.second;
		dis=cur.first;
		if(flag[p])
			continue;
		flag[p]=1;
		sz=vi[p].size();
		for(i=0;i<sz;i++)
			pq.push(make_pair(d[vi[p][i].second]=min(d[vi[p][i].second],vi[p][i].first+dis),
					vi[p][i].second));
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10801.txt","w",stdout);

	while(cin>>n>>k)
	{
		int i,a,b;
		for(i=0;i<n;i++)
			scanf("%d",t+i);
		getchar();
		for(i=0;i<MAXN*n;i++)
		{
			d[i]=INF;
			vi[i].clear();
		}
		for(i=1;i<MAXN;++i)
			for(a=0;a<n;++a)
				for(b=0;b<a;++b)
				{
					vi[a*MAXN+i].push_back(make_pair(TIMEOUT,b*MAXN+i));
					vi[b*MAXN+i].push_back(make_pair(TIMEOUT,a*MAXN+i));
				}

		string buf;
		for(i=0;i<n;i++)
		{
			getline(cin,buf);
			stringstream sin(buf);
			sin>>a;
			while(sin>>b)
			{
				vi[i*MAXN+a].push_back(make_pair(t[i]*(b-a),i*MAXN+b));
				vi[i*MAXN+b].push_back(make_pair(t[i]*(b-a),i*MAXN+a));
				a=b;
			}
		}
		dijkstra();
		int key=INF;
		for(i=0;i<n;i++)
			key=min(key,d[k+i*MAXN]);
		if(key==INF)
			cout<<"IMPOSSIBLE"<<endl;
		else
			cout<<key<<endl;
	}

return 0;
}
/*
in.txt
4 89
7 2 4 8
3 34 45 56 77
4 23 34 89
0 99
3 99
3 1
100 10 100
0 1
0 1
0 1
2 30
10 5
0 1 3 5 7 9 11 13 15 20 99
4 13 15 19 20 25 30
2 30
10 1
0 5 10 12 14 20 25 30
2 4 6 8 10 12 14 22 25 28 29
3 50
10 50 100
0 10 30 40
0 20 30
0 20 50
1 1
2
0 2 4 6 8 10
3 30
100 100 1
0 2 4 5 6 7 8 21 22 23 24 25 26 30
1 2 19 11 12 13 14 15 16 30
1 10 30
2 99
100 1
0 1 98 99
1 98
2 5
1 1
0 3
4 5
*/
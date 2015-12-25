/*
10986 - Sending email

Dijkstra...
*/


#include<iostream>
#include<queue>
#define MAXNODE 20010
#define INF 1e9
using namespace std;
typedef pair<int,int> pii;

int n,m,s,t,flag[MAXNODE],d[MAXNODE];

void dijkstra(vector<pii> v[MAXNODE])
{
	for(int i=0;i<n;++i)
	{
		d[i]=INF;
		flag[i]=0;
	}
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.push(make_pair(d[s]=0,s));
	pii cur;
	while(!pq.empty())
	{
		cur=pq.top();	pq.pop();
		int p=cur.second;
		if(flag[p])
			continue;
		else
			flag[p]=1;
		int sz=v[p].size();
		for(int i=0;i<sz;++i)
		{
			int e=v[p][i].first;
			int w=v[p][i].second;
			if(d[e]>cur.first+w)
				pq.push(make_pair(d[e]=cur.first+w,e));
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	for(int cas=1;cas<=dataset;++cas)
	{
		int i,start,target,weight;
		cin>>n>>m>>s>>t;
		vector<pii> v[MAXNODE];
		for(i=0;i<m;++i)
		{
			scanf("%d %d %d",&start,&target,&weight);
			v[start].push_back(make_pair(target,weight));
			v[target].push_back(make_pair(start,weight));
		}
		dijkstra(v);
		cout<<"Case #"<<cas<<": ";
		if(d[t]==INF)
			cout<<"unreachable"<<endl;
		else
			cout<<d[t]<<endl;
	}

return 0;
}

/*
10171 - Meeting Prof. Miguel...

BFS...
暴搜...
很奇怪的说...
为什么dijkstra和floyd-warshall...
不行呢...
*/

#include<iostream>
#include<queue>
#define MAXN 30
#define INF 1e9
using namespace std;
typedef pair<int,int> pii;
vector<pii> vy[MAXN],vm[MAXN];
int n,disy[MAXN],dism[MAXN];

void bfs(int s,vector<pii> v[MAXN],int dis[MAXN])
{
	queue<int> q;
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		s=q.front();	q.pop();
		int sz=v[s].size();
		for(int i=0;i<sz;++i)
		{
			int cur=v[s][i].first;
			if(dis[cur]>dis[s]+v[s][i].second)
			{
				dis[cur]=dis[s]+v[s][i].second;
				q.push(cur);
			}
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	while(cin>>n && n)
	{
		char street,direct,begin,end;
		int var,i;
		for(i=0;i<MAXN;++i)
		{
			vy[i].clear();	disy[i]=INF;
			vm[i].clear();	dism[i]=INF;
		}
		for(i=0;i<n;++i)
		{
			cin>>street>>direct>>begin>>end>>var;
			if(street=='Y')
			{
				vy[begin-'A'].push_back(make_pair(end-'A',var));
				if(direct=='B')
					vy[end-'A'].push_back(make_pair(begin-'A',var));
			}
			else
			{
				vm[begin-'A'].push_back(make_pair(end-'A',var));
				if(direct=='B')
					vm[end-'A'].push_back(make_pair(begin-'A',var));
			}
		}
		cin>>begin>>end;
		bfs(begin-'A',vy,disy);
		bfs(end-'A',vm,dism);
		int key=INF;
		for(i=0;i<MAXN;++i)
			if(dism[i]+disy[i]<key)
				key=dism[i]+disy[i];
		if(key==INF)
			cout<<"You will never meet."<<endl;
		else
		{
			cout<<key;
			for(i=0;i<MAXN;++i)
				if(dism[i]+disy[i]==key)
					cout<<' '<<(char)('A'+i);
			cout<<endl;
		}
	}

	return 0;
}

/*
-----------Dijkstra--------
#include<iostream>
#include<queue>
#define min(a,b) ((a)<(b))?(a):(b)
#define MAXN 30
#define INF 1e6
using namespace std;
typedef pair<int,int> pii;
int gm[MAXN][MAXN],gy[MAXN][MAXN],dism[MAXN],disy[MAXN],cnt;

void dijkstra(int s,int g[MAXN][MAXN],int dis[MAXN])
{
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	bool flag[MAXN];
	memset(flag,0,sizeof(flag));
	pq.push(make_pair(dis[s]=0,s));
	while(!pq.empty())
	{
		pii cur=pq.top();	pq.pop();
		s=cur.second;
		flag[s]=true;
		int d=dis[s];
		for(int i=0;i<MAXN;++i)
			if(g[s][i]!=INF && !flag[i])
			{
				dis[i]=min(dis[i],d+g[s][i]);
				pq.push(make_pair(dis[i],i));
			}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10171.txt","w",stdout);

	char b,e,street,direct;
	int i,j,var,ps,pe,n,flag[256];
	while(cin>>n && n)
	{
		for(i=0;i<MAXN;++i)
		{
			for(j=0;j<MAXN;++j)
				gy[i][j]=gm[i][j]=INF;
			gy[i][i]=gm[i][i]=0;
			dism[i]=disy[i]=INF;
		}
		memset(flag,-1,sizeof(flag));
		cnt=0;
		for(i=0;i<n;++i)
		{
			cin>>street>>direct>>b>>e>>var;
			if(flag[b]==-1)
				flag[b]=cnt++;
			ps=flag[b];
			if(flag[e]==-1)
				flag[e]=cnt++;
			pe=flag[e];
			if(street=='Y')
			{
				gy[ps][pe]=min(gy[ps][pe],var);
				if(direct=='B')
					gy[pe][ps]=min(gy[pe][ps],var);
			}
			else
			{
				gm[ps][pe]=min(gm[ps][pe],var);
				if(direct=='B')
					gm[pe][ps]=min(gm[pe][ps],var);
			}
		}
		cin>>b>>e;
		if(flag[b]==-1 || flag[e]==-1)
		{
			if(b!=e)
				cout<<"You will never meet."<<endl;
			else
				cout<<"0 "<<b<<endl;
			continue;
		}
		ps=flag[b];	pe=flag[e];
		dijkstra(ps,gy,disy);
		dijkstra(pe,gm,dism);
		int key=-1;
		for(i=0;i<cnt;++i)
			if(disy[i]!=INF && dism[i]!=INF)
			{
				if(key==-1)
					key=i;
				else if(disy[i]+dism[i]<disy[key]+dism[key])
					key=i;
			}
		if(key==-1)
			cout<<"You will never meet."<<endl;
		else
		{
			cout<<disy[key]+dism[key];
			for(char i='A';i<='Z';++i)
			{
				int p=flag[i];
				if(disy[p]+dism[p]==disy[key]+dism[key])
					cout<<' '<<i;
			}
			cout<<endl;
		}
	}

	return 0;
}
*/

/*
--------------floyd-warshall---------------
#include<iostream>
#define min(a,b) ((a)<(b))?(a):(b)
#define MAXN 30
#define INF 1e9
using namespace std;

int gm[MAXN][MAXN],gy[MAXN][MAXN],n,cnt;

void floyd_warshall()
{
	for(int k=1;k<cnt;++k)
		for(int i=1;i<cnt;++i)
			for(int j=1;j<cnt;++j)
			{
				gm[i][j]=min(gm[i][j],gm[i][k]+gm[k][j]);
				gy[i][j]=min(gy[i][j],gy[i][k]+gy[k][j]);
			}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10171.txt","w",stdout);

	char b,e,street,direct,flag[256];
	int i,j,var,ps,pe,n;
	while(cin>>n && n)
	{
		for(i=0;i<MAXN;++i)
		{
			for(j=0;j<MAXN;++j)
				gy[i][j]=gm[i][j]=INF;
			gy[i][i]=gm[i][i]=0;
		}
		cnt=1;
		memset(flag,0,sizeof(flag));
		for(i=0;i<n;++i)
		{
			cin>>street>>direct>>b>>e>>var;
			if(!flag[b])
				flag[b]=cnt++;
			ps=flag[b];
			if(!flag[e])
				flag[e]=cnt++;
			pe=flag[e];
			if(street=='Y')
			{
				gy[ps][pe]=min(gy[ps][pe],var);
				if(direct=='B')
					gy[pe][ps]=min(gy[pe][ps],var);
			}
			else
			{
				gm[ps][pe]=min(gm[ps][pe],var);
				if(direct=='B')
					gm[pe][ps]=min(gm[pe][ps],var);
			}
		}
		cin>>b>>e;
		if(!flag[b] || !flag[e])
		{
			if(b!=e)
				cout<<"You will never meet."<<endl;
			else
				cout<<"0 "<<b<<endl;
			continue;
		}
		floyd_warshall();
		ps=flag[b];	pe=flag[e];
		int key=-1;
		for(i=1;i<cnt;++i)
			if(gy[ps][i]!=INF && gm[pe][i]!=INF)
			{
				if(key==-1)
					key=i;
				else if(gy[ps][i]+gm[pe][i]<gy[ps][key]+gm[pe][key])
					key=i;
			}
		if(key==-1)
			cout<<"You will never meet."<<endl;
		else
		{
			cout<<gy[ps][key]+gm[pe][key];
			for(char i='A';i<='Z';++i)
			{
				int p=flag[i];
				if(gy[ps][p]+gm[pe][p]==gy[ps][key]+gm[pe][key])
					cout<<' '<<i;
			}
			cout<<endl;
		}
	}

	return 0;
}

*/
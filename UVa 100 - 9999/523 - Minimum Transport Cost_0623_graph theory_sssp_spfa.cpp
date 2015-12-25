/*
523 - Minimum Transport Cost

graph theory...
sssp...
读入那边会比较麻烦一点...
其它的也没什么好主意的...
spfa求一下最短路,dfs输出路径即可
*/

#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#define MAXN 1600
#define INF 0x7f7f7f7f
using namespace std;

string buf;
int g[MAXN][MAXN],cost[MAXN],n;

void format()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(g[i][j]==-1)
				g[i][j]=INF;
}

int fa[MAXN],dis[MAXN];
bool inq[MAXN];

void dfs(int u,int start)
{
	if(u==start)
		cout<<start;
	else
	{
		dfs(fa[u],start);
		cout<<"-->"<<u;
	}
}

void spfa(int start,int end)
{
	cout<<"From "<<start<<" to "<<end<<" :"<<endl;
	if(start==end)
	{
		cout<<"Path: "<<start<<endl;
		cout<<"Total cost : 0"<<endl;
		return ;
	}

	memset(inq,0,sizeof(inq));
	memset(dis,0x7f,sizeof(dis));
	dis[start]=0;

	queue<int> q;
	q.push(start);
	inq[start]=true;

	int c_s=0,c_e=0;
	swap(c_s,cost[start]);	swap(c_e,cost[end]);

	while(!q.empty())
	{
		int cur=q.front();	q.pop();	inq[cur]=false;
		for(int i=1;i<=n;++i)
			if(dis[i]>dis[cur]+g[cur][i]+cost[i])
			{
				dis[i]=dis[cur]+g[cur][i]+cost[i];
				fa[i]=cur;
				if(!inq[i])
					q.push(i);
				inq[i]=true;
			}
	}

	swap(c_s,cost[start]);	swap(c_e,cost[end]);

	cout<<"Path: ";	dfs(end,start);
	cout<<endl<<"Total cost : "<<dis[end]<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	getline(cin,buf);getline(cin,buf);

	while(dataset--)
	{
		getline(cin,buf);
		stringstream sin(buf);
		n=1;
		while(sin>>g[1][n])
			++n;
		--n;
		for(int i=2;i<=n;++i)
			for(int j=1;j<=n;++j)
				cin>>g[i][j];
		format();
		for(int i=1;i<=n;++i)
			cin>>cost[i];

		getline(cin,buf);
		bool first=true;
		while(getline(cin,buf) && buf!="")
		{
			if(!first)
				cout<<endl;
			first=false;
			stringstream sin(buf);
			int start,end;
			sin>>start>>end;
			spfa(start,end);
		}
	}

	return 0;
}

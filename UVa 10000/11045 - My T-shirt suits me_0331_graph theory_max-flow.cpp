/*
11045 - My T-shirt suits me

max-flow...
二分匹配的问题...
转化为最大流...

start为原点,end为终点.
有sz=6种规格的衣服看为六个点,编号从1->6.
由start向这六个点连接六条边,每条边的权重为n/6.

m个人,每个人向1->6这几个点连接2条边.边权为1
m个点向end连接一条边,边权为1.

建好图后edmonds_karp就可以了...
*/

#include<iostream>
#include<map>
#include<queue>
#include<string>
#define MAXN 45
#define INF 1e9
#define sz 6
using namespace std;

int n,m,cap[MAXN][MAXN],flow[MAXN][MAXN],fa[MAXN],remflow[MAXN],start,end;

int edmonds_karp()
{
	int key=0,u,v;
	memset(flow,0,sizeof(flow));
	queue<int> q;
	while(true)
	{
		memset(remflow,0,sizeof(remflow));
		remflow[start]=INF;
		q.push(start);
		while(!q.empty())
		{
			u=q.front();	q.pop();
			for(v=start;v<=end;++v)
				if(!remflow[v] && cap[u][v]>flow[u][v])
				{
					fa[v]=u;
					q.push(v);
					remflow[v]=min(remflow[u],cap[u][v]-flow[u][v]);
				}
		}
		if(remflow[end]==0)
			return key;
		for(u=end;u!=start;u=fa[u])
		{
			flow[fa[u]][u]+=remflow[end];
			flow[u][fa[u]]-=remflow[end];
		}
		key+=remflow[end];
	}
	return key;
}

int main()
{
//	freopen("in.txt","r",stdin);

	map<string,int> msi;
	msi["XXL"]=1;
	msi["XL"]=2;
	msi["L"]=3;
	msi["M"]=4;
	msi["S"]=5;
	msi["XS"]=6;

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		memset(cap,0,sizeof(cap));
		scanf("%d %d",&n,&m);
		start=0;
		end=sz+m+1;
		int i,p;
		for(i=1;i<=sz;++i)
			cap[start][i]=n/6;
		string shirt;
		for(i=1;i<=m;++i)
		{
			p=i+sz;
			cin>>shirt;
			cap[msi[shirt]][p]=1;
			cin>>shirt;
			cap[msi[shirt]][p]=1;
			cap[p][end]=1;
		}
		if(edmonds_karp()==m)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

	return 0;
}

/*
753 - A Plug for UNIX

max-flow
这题做到我要崩溃了..
先是题目没有看清楚...
漏掉几个条件...狂WA...
然后...就更加悲剧了...
发现图建错了...
*/

#include<iostream>
#include<map>
#include<string>
#include<queue>
#define MAXN 310
#define INF 1e8
#define min(a,b) ((a)<(b))?(a):(b)
using namespace std;

int cap[MAXN][MAXN],start,end,flow[MAXN][MAXN],fa[MAXN],remflow[MAXN],n,m,k;

int edmonds_karp()
{
	int key=0,u,v,tend=end+n+m+k;
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
			for(v=start;v<=tend;++v)
				if(!remflow[v] && cap[u][v]>flow[u][v])
				{
					fa[v]=u;
					q.push(v);
					remflow[v]=min(remflow[u],cap[u][v]-flow[u][v]);
				}
		}
		if(!remflow[end])
			return key;
		for(u=end;u!=start;u=fa[u])
		{
			flow[fa[u]][u]+=remflow[end];
			flow[u][fa[u]]-=remflow[end];
		}
		key+=remflow[end];
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		memset(cap,0,sizeof(cap));
		int i,p;
		start=0;
		end=1;		//end直接弄成1算了.数据那边不好控制.
		cin>>n;
		map<string,int> msi,msi2;	//弄两个map,一个是仪器,一个是插口.
		string buf,buf2;
		for(i=1;i<=n;++i)
		{
			p=i+1;
			cin>>buf;
			if(msi.find(buf)==msi.end())
				msi[buf]=p;
			++cap[msi[buf]][end];
		}
		cin>>m;
		for(i=1;i<=m;++i)
		{
			p=i+1+n;
			cin>>buf;
			cin>>buf;
			if(msi2.find(buf)==msi2.end())
				msi2[buf]=p;
			++cap[start][msi2[buf]];
			if(msi.find(buf)!=msi.end())
				cap[msi2[buf]][msi[buf]]=INF;	//从设备到插头.流量无限
		}
		cin>>k;
		for(i=1;i<=k;++i)
		{
			cin>>buf>>buf2;
			if(msi.find(buf2)!=msi.end())
				cap[msi2[buf]][msi[buf2]]=INF;		//无限多个转接口.
			if(msi2.find(buf2)!=msi2.end())
				cap[msi2[buf]][msi2[buf2]]=INF;	//转接口之间可以互相转接.
		}
		cout<<m-edmonds_karp()<<endl;
		if(dataset)
			cout<<endl;
	}

	return 0;
}

/*
753 - A Plug for UNIX

max-flow
����������Ҫ������..
������Ŀû�п����...
©����������...��WA...
Ȼ��...�͸��ӱ�����...
����ͼ������...
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
		end=1;		//endֱ��Ū��1����.�����Ǳ߲��ÿ���.
		cin>>n;
		map<string,int> msi,msi2;	//Ū����map,һ��������,һ���ǲ��.
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
				cap[msi2[buf]][msi[buf]]=INF;	//���豸����ͷ.��������
		}
		cin>>k;
		for(i=1;i<=k;++i)
		{
			cin>>buf>>buf2;
			if(msi.find(buf2)!=msi.end())
				cap[msi2[buf]][msi[buf2]]=INF;		//���޶��ת�ӿ�.
			if(msi2.find(buf2)!=msi2.end())
				cap[msi2[buf]][msi2[buf2]]=INF;	//ת�ӿ�֮����Ի���ת��.
		}
		cout<<m-edmonds_karp()<<endl;
		if(dataset)
			cout<<endl;
	}

	return 0;
}

/*
11045 - My T-shirt suits me

max-flow...
����ƥ�������...
ת��Ϊ�����...

startΪԭ��,endΪ�յ�.
��sz=6�ֹ����·���Ϊ������,��Ŵ�1->6.
��start��������������������,ÿ���ߵ�Ȩ��Ϊn/6.

m����,ÿ������1->6�⼸��������2����.��ȨΪ1
m������end����һ����,��ȨΪ1.

����ͼ��edmonds_karp�Ϳ�����...
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

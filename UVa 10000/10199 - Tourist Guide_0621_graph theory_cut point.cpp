/*
10199 - Tourist Guide

graph theory...
求割点
暴力枚举,删边,判连通即可
只需注意一下图可能是一个森林即可
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#define MAXN 110
using namespace std;

bool g[MAXN][MAXN],flag[MAXN],key[MAXN],buf[MAXN];
int n,m;
string city[MAXN];

void dfs(int u)
{
	for(int v=0;v<n;++v)
		if(g[u][v] && !flag[v])
		{
			flag[v]=true;
			dfs(v);
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(cin>>n && n)
	{
		if(cas!=1)
			cout<<endl;

		map<string,int> msi;
		for(int i=0;i<n;++i)
			cin>>city[i];
		sort(city,city+n);
		for(int i=0;i<n;++i)
			msi[ city[i] ]=i;
		cin>>m;

		string a,b;
		memset(g,0,sizeof(g));
		for(int i=0;i<m;++i)
		{
			cin>>a>>b;
			int u=msi[a],v=msi[b];
			g[u][v]=g[v][u]=true;
		}

		memset(key,0,sizeof(key));
		int tot=0;
		for(int i=0;i<n;++i)
		{
			memset(flag,0,sizeof(flag));
			for(int j=0;j<n;++j)
				if(g[i][j])
				{
					g[i][j]=g[j][i]=false;
					buf[j]=true;
				}
				else
					buf[j]=false;

			for(int j=0;j<n;++j)
				if(buf[j])
				{
					flag[j]=true;
					dfs(j);
					break;
				}

			for(int j=0;j<n;++j)
				if(!flag[j] && buf[j])
				{
					key[i]=true;
					++tot;
					break;
				}

			for(int j=0;j<n;++j)
				g[i][j]=g[j][i]=buf[j];
		}
		cout<<"City map #"<<cas++<<": "<<tot<<" camera(s) found"<<endl;
		for(int i=0;i<n;++i)
			if(key[i])
				cout<<city[i]<<endl;
	}

	return 0;
}

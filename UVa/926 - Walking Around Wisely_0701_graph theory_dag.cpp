/*
926 - Walking Around Wisely

graph theory...
DAG...
溢出错误是最难发现的...
不过遇到这种最后结果可能很大的题...
使用int64应该是个不错的主意...
*/

#include<iostream>
#include<vector>
#define MAXN 1000
using namespace std;
typedef pair<int,int> pii;

int n,m,topo[MAXN],tot;
vector<int> edge[MAXN];
pii s,e,cur;
char d[3];
bool flag[MAXN];
long long key[MAXN];

int hash(pii u)
{
	return (u.first-1)*n+u.second;
}

void del(pii a,pii b)
{
	int u=hash(a),v=hash(b);
	vector<int>::iterator vit=edge[u].begin();
	while(vit!=edge[u].end())
	{
		if(*vit==v)
		{
			edge[u].erase(vit);
			break;
		}
		++vit;
	}
}

void dfs(int u)
{
	flag[u]=true;
	for(int i=0;i<edge[u].size();++i)
	{
		int v=edge[u][i];
		if(!flag[v])
			dfs(v);
	}
	topo[--tot]=u;
}

void init()
{
	for(int x=s.first;x<=e.first;++x)
		for(int y=s.second;y<=e.second;++y)
		{
			int u=hash( make_pair(x,y) );
			if(x!=e.first)
				edge[u].push_back(hash( make_pair(x+1,y) ));
			if(y!=e.second)
				edge[u].push_back(hash( make_pair(x,y+1) ));
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n*n;++i)
		{
			edge[i].clear();
			flag[i]=false;
			key[i]=0;
		}
		scanf("%d%d",&s.first,&s.second);
		scanf("%d%d",&e.first,&e.second);

		init();
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d%s",&cur.first,&cur.second,d);
			if(d[0]=='S')
				del(make_pair(cur.first,cur.second-1),cur);
			else if(d[0]=='E')
				del(cur,make_pair(cur.first+1,cur.second));
			else if(d[0]=='W')
				del(make_pair(cur.first-1,cur.second),cur);
			else
				del(cur,make_pair(cur.first,cur.second+1));
		}
		tot=n*n;
		dfs(hash(s));
		key[ hash(s) ]=1;
		for(int i=tot;i<=n*n;++i)
		{
			int u=topo[i];
			for(int j=0;j<edge[u].size();++j)
				key[ edge[u][j] ]+=key[u];
		}
		printf("%lld\n",key[ hash(e) ]);
	}

	return 0;
}

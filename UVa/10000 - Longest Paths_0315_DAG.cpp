/*
10000 - Longest Paths
*/

#include<iostream>
#define MAXN 50000		//尽量开大一点,千万别小气...不然要是这里有BUG可是要出人命的...
using namespace std;

int node[MAXN],nodes,edges,s,edge[MAXN][2];

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10000.txt","w",stdout);

	int cas=1,i,j;
	while(cin>>nodes && nodes)
	{
		cin>>s;
		edges=0;
		while(cin>>edge[edges][0]>>edge[edges][1]	//晕死我了...告诉你说以后不要直接copy前面的东西!!!
			&& (edge[edges][0]||edge[edges][1]))
			++edges;
		memset(node,-1,sizeof(node));
		node[s]=0;
		bool done;
		int len=-1;
		do
		{
			done=false;
			++len;
			for(i=1;i<=nodes;i++)
				if(node[i]==len)
					for(j=0;j<edges;j++)
						if(edge[j][0]==i)
						{
							node[edge[j][1]]=len+1;
							done=true;
						}
		}while(done);
		for(i=1;node[i]<len;i++)
			;
		cout<<"Case "<<cas++
			<<": The longest path from "<<s
			<<" has length "<<len<<", finishing at "
			<<i<<"."<<endl<<endl;
	}

return 0;
}

/*
DFS-------------------------TLE

#include<iostream>
#include<vector>
#define MAXN 5000
using namespace std;

int d[MAXN],n,s,key,tg;
bool first;

void dfs(vector<int> g[MAXN],int i,int dep)
{
	if(dep>key)
	{
		key=dep;
		tg=i;
	}
	else if(dep==key)
		tg=tg<i?tg:i;
	for(int j=0;j<g[i].size();j++)
	{
		int v=g[i][j];
		if(!d[v])
		{
			d[v]=1;
			dfs(g,v,dep+1);
			d[v]=0;
		}
	}
	return ;
}

int main()
{//
	freopen("in.txt","r",stdin);
//	freopen("10000.txt","w",stdout);

	int p,q,cas=1;
	while(cin>>n && n)
	{
		vector<int> g[MAXN];
		cin>>s;
		while(cin>>p>>q && (p||q))
			g[p].push_back(q);
		memset(d,0,sizeof(d));
		d[s]=1;
		key=0;
		dfs(g,s,0);
		cout<<"Case "<<cas++
			<<": The longest path from "<<s
			<<" has length "<<key<<", finishing at "
			<<tg<<"."<<endl<<endl;
	}

return 0;
}

*/

/*
DP------DAG--------------WA

#include<iostream>
#include<vector>
#define MAXN 10010
using namespace std;

int d[MAXN],n,s,key,tg;
bool first;

int dp(vector<int> g[MAXN],int i,int dep)
{
	if(d[i])
		return d[i];
	else for(int j=0;j<g[i].size();j++)
	{
		int t=dp(g,g[i][j],dep+1)+1;
		d[i]=d[i]>t?d[i]:t;
	}
	if(dep>key)
	{
		key=dep;
		tg=i;
	}
	else if(dep==key)
		tg=tg<i?tg:i;
	return d[i];
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10000.txt","w",stdout);

	int p,q,cas=1;
	while(cin>>n && n)
	{
		vector<int> g[MAXN];
		cin>>s;
		while(cin>>p>>q && (p||q))
			g[p].push_back(q);
		memset(d,0,sizeof(d));
		key=0;
		dp(g,s,0);
		if(!d[s])
			tg=s;
		cout<<"Case "<<cas++
			<<": The longest path from "<<s
			<<" has length "<<d[s]<<", finishing at "
			<<tg<<"."<<endl<<endl;
	}

return 0;
}

*/
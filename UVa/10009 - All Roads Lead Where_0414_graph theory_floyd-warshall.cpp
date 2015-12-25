/*
10009 - All Roads Lead Where?

graph theory.
floyd-warshall...
*/

#include<iostream>
#include<map>
#include<string>
#define min(a,b) ((a)<(b))?(a):(b)
#define MAXN 30
#define INF 1e9
using namespace std;

int g[MAXN][MAXN],fa[MAXN][MAXN],flag[MAXN],cnt;
char hash[MAXN];

void floyd_warshall()
{
	memset(fa,-1,sizeof(fa));
	for(int k=0;k<cnt;++k)
		for(int i=0;i<cnt;++i)
			for(int j=0;j<cnt;++j)
				if(g[i][j]>g[i][k]+g[k][j])
				{
					g[i][j]=g[i][k]+g[k][j];
					fa[i][j]=k;
				}
}

void print(int s,int e)
{
	if(!flag[s])
		cout<<hash[s],flag[s]=1;
	if(fa[s][e]!=-1)
	{
		print(s,fa[s][e]);
		print(fa[s][e],e);
	}
	if(!flag[e])
		cout<<hash[e],flag[e]=1;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int n,m,i,s,e;
		for(s=0;s<MAXN;++s)
			for(e=0;e<MAXN;++e)
				g[s][e]=INF;
		cin>>n>>m;
		map<char,int> mci;
		string buf;
		cnt=0;
		for(i=0;i<n;++i)
		{
			cin>>buf;
			if(mci.find(buf[0])==mci.end())
				mci[buf[0]]=cnt++;
			s=mci[buf[0]];
			hash[s]=buf[0];
			cin>>buf;
			if(mci.find(buf[0])==mci.end())
				mci[buf[0]]=cnt++;
			e=mci[buf[0]];
			hash[e]=buf[0];
			g[s][e]=g[e][s]=1;
		}
		floyd_warshall();
		for(i=0;i<m;++i)
		{
			cin>>buf;		s=mci[buf[0]];
			cin>>buf;		e=mci[buf[0]];
			memset(flag,0,sizeof(flag));
			print(s,e);
			cout<<endl;
		}
		if(dataset)
			cout<<endl;
	}

	return 0;
}

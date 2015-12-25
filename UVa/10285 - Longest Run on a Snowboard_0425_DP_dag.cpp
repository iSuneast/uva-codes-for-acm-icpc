/*
10285 - Longest Run on a Snowboard

DP...
DAG�·...
*/

#include<iostream>
#include<string>
#define max(a,b) ((a)>(b)?(a):(b))
#define MAXN 110
using namespace std;

int g[MAXN][MAXN],dis[MAXN][MAXN],c,r;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

int dp(int x,int y)
{
	if(dis[x][y]!=-1)
		return dis[x][y];
	dis[x][y]=1;
	for(int d=0;d<4;++d)
	{
		int tx=x+dx[d];
		int ty=y+dy[d];
		if(g[tx][ty]==-1 || g[tx][ty]>=g[x][y])
			continue;
		int td=dp(tx,ty);
		dis[x][y]=max(dis[x][y],td+1);
	}
	return dis[x][y];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		string name;
		cin>>name;
		cout<<name<<": ";
		memset(dis,-1,sizeof(dis));
		memset(g,-1,sizeof(g));
		int i,j;
		cin>>c>>r;
		for(i=1;i<=c;++i)
			for(j=1;j<=r;++j)
				cin>>g[i][j];
		for(i=1;i<=c;++i)
			for(j=1;j<=r;++j)
				if(dis[i][j]==-1)
					dp(i,j);
		int key=-1;
		for(i=1;i<=c;++i)
			for(j=1;j<=r;++j)
				key=max(key,dis[i][j]);
		cout<<key<<endl;		
	}

	return 0;
}

/*
11101 - Mall Mania

惊呆了...
本来以为BFS版本的代码会TLE的...
搜索了整张图...实在慢啊...
没想到竟然真的AC了...
无语了...
看来UVa的服务器的配置比我的PC好多了...
ORz...
*/

#include<iostream>
#include<queue>
#define MAXN 2001
#define INF 1e8
using namespace std;

int g[MAXN][MAXN];
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

int main()
{
//	freopen("in.txt","r",stdin);

	int n,m;
	while(cin>>n && n)
	{
		int i,a,b,tx,ty;
		memset(g,-1,sizeof(g));
		queue<pair<int,int> > q;
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			g[a][b]=0;
			q.push(make_pair(a,b));
		}
		int d=0;
		pair<int,int> pii;
		while(!q.empty())
		{
			pii=q.front();	q.pop();
			a=pii.first;
			b=pii.second;
			d=g[a][b];
			for(i=0;i<4;i++)
			{
				tx=a+dx[i];
				ty=b+dy[i];
				if(tx>=0 && tx<MAXN && ty>=0 && ty<MAXN && g[tx][ty]==-1)
				{
					g[tx][ty]=d+1;
					q.push(make_pair(tx,ty));
				}
			}
		}
		cin>>m;
		d=INF;
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			if(d>g[a][b] && g[a][b]!=-1)
				d=g[a][b];
		}
		cout<<d<<endl;
	}

return 0;
}
/*
一下为brute force版本....TLE...

#include<iostream>
#define MAXN 2001
#define INF 1e8
using namespace std;

int g[2][MAXN*MAXN];

int main()
{
//	freopen("in.txt","r",stdin);

	int n,m;
	while(cin>>n && n)
	{
		int i,j,a,b,d=INF,td;
		for(i=0;i<n;i++)
			scanf("%d %d",&g[0][i],&g[1][i]);
		cin>>m;
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			for(j=0;j<n;j++)
			{
				td=abs(a-g[0][j])+abs(b-g[1][j]);
				d=d<td?d:td;
			}
		}
		cout<<d<<endl;
	}

return 0;
}

*/
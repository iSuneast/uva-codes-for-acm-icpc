/*
 * 11906 - Knight in a War Grid
 * 
 * graph theory...
 * use bfs OR dfs to initialization the graph
 * mark the nodes which we can go from (0,0)
 * then just scan the whole graph and count how many nodes we can visit in one pace
 * 
 * remember to mark (0,0) at first
 * because there is a case like
 * --------------------input
 * 1 1 2 2
 * 0
 * --------------------output
 * 1 0
 * --------------------
 * just a simple trick indeed, by so many people have failed because of it
 * 
 * happy coding...
 */

#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#define MAXN 103
using namespace std;

struct POINT
{
	int x,y;
	POINT(){}
	POINT(int _x,int _y):x(_x),y(_y){}
	bool operator<(const POINT &t)const
	{
		if(x==t.x)
			return y<t.y;
		return x<t.x;
	}
}pnt;

int r,c,m,n,w;
int g[MAXN][MAXN];
const int dx[]={1,1,-1,-1}, dy[]={1,-1,1,-1};

bool valid(const int &x,const int &y)
{
	return 0<=x && x<r && 0<=y && y<c;
}

void bfs()
{
	int odd=0, even=0, tx, ty;
	queue<POINT> q;
	q.push(POINT(0,0));
	g[0][0]=1;
	
	while(!q.empty())
	{
		pnt=q.front();	q.pop();
		for(int d=0;d<4;++d)
		{
			tx=pnt.x+dx[d]*m, ty=pnt.y+dy[d]*n;
			if(valid(tx,ty) && g[tx][ty]==0)
			{
				g[tx][ty]=1;
				q.push(POINT(tx,ty));
			}
			
			tx=pnt.x+dx[d]*n, ty=pnt.y+dy[d]*m;
			if(valid(tx,ty) && g[tx][ty]==0)
			{
				g[tx][ty]=1;
				q.push(POINT(tx,ty));
			}
		}
	}
	
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			if(g[i][j]!=1)
				continue;

			set<POINT> sp;
			for(int d=0;d<4;++d)
			{
				tx=i+dx[d]*m, ty=j+dy[d]*n;
				if(valid(tx,ty) && g[tx][ty]==1)
					sp.insert( POINT(tx,ty) );
				tx=i+dx[d]*n, ty=j+dy[d]*m;
				if(valid(tx,ty) && g[tx][ty]==1)
					sp.insert( POINT(tx,ty) );
			}
			
			if(sp.size()&1)
				++odd;
			else
				++even;
		}
	}
	
	printf("%d %d\n",even,odd);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
    	scanf("%d%d%d%d",&r,&c,&m,&n);
    	memset(g,0,sizeof(g));
    	
    	scanf("%d",&w);
    	while(w--)
    	{
    		scanf("%d%d",&pnt.x,&pnt.y);
    		g[pnt.x][pnt.y]=-1;
    	}
    	
    	printf("Case %d: ",cas);
    	bfs();
    }    

    return 0;
}


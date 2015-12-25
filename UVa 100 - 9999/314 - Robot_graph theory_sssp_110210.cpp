/*
 * 314 - Robot
 *
 * graph theory...
 * sssp...
 * 单源最短路, 开一个三维数组, 其中一维来表示方向就可以了~
 * 对图跑一次spfa即可...
 *
 * happy coding~
 */

#include<iostream>
#include<queue>
#define MAXN 55
using namespace std;
const int INF=0x3f3f3f3f;

struct POINT
{
	int r,c,d;
	POINT(){}
	POINT(int _r,int _c,int _d):r(_r),c(_c),d(_d){}
}s,e;

int dis[4][MAXN][MAXN];
bool inq[4][MAXN][MAXN];
int g[MAXN][MAXN], R, C, D;
const int dr[]={-1,0,1,0};
const int dc[]={0,1,0,-1};

bool valid(int _r,int _c)
{
	return g[_r][_c]==0 && g[_r+1][_c]==0 && g[_r][_c+1]==0 && g[_r+1][_c+1]==0;
}

int spfa()
{
	memset(dis,0x3f,sizeof(dis));
	queue<POINT> q;
	q.push( POINT(s.r, s.c, D) );	dis[D][s.r][s.c]=0;	inq[D][s.r][s.c]=true;

	POINT cur, next;
	while(!q.empty())
	{
		cur=q.front();	q.pop();	inq[cur.d][cur.r][cur.c]=false;
		for(int d=0;d<4;++d)
		{
			for(int p=1;p<=3;++p)
			{
				int tr=cur.r+dr[cur.d]*p, tc=cur.c+dc[cur.d]*p;
				if(!valid(tr, tc))
					break;
				if(dis[cur.d][tr][tc]>dis[cur.d][cur.r][cur.c]+1)
				{
					dis[cur.d][tr][tc]=dis[cur.d][cur.r][cur.c]+1;
					if(!inq[cur.d][tr][tc])
					{
						q.push( POINT(tr, tc, cur.d) );
						inq[cur.d][tr][tc]=true;
					}
				}
			}
		}

		int td=( cur.d+3 )%4;
		if(dis[td][cur.r][cur.c]>dis[cur.d][cur.r][cur.c]+1)
		{
			dis[td][cur.r][cur.c]=dis[cur.d][cur.r][cur.c]+1;
			if(!inq[td][cur.r][cur.c])
			{
				q.push( POINT(cur.r, cur.c, td) );
				inq[td][cur.r][cur.c]=true;
			}
		}

		td=( cur.d+1 )%4;
		if(dis[td][cur.r][cur.c]>dis[cur.d][cur.r][cur.c]+1)
		{
			dis[td][cur.r][cur.c]=dis[cur.d][cur.r][cur.c]+1;
			if(!inq[td][cur.r][cur.c])
			{
				q.push( POINT(cur.r, cur.c, td) );
				inq[td][cur.r][cur.c]=true;
			}
		}
	}

	int a=min(dis[0][e.r][e.c], dis[1][e.r][e.c]);
	int b=min(dis[2][e.r][e.c], dis[3][e.r][e.c]);
	int c=min(a,b);
	if(c==INF)
		return -1;
	else
		return  c;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	char dir[10];
	while(scanf("%d%d",&R,&C)!=EOF && (R||C))
	{
		memset(g,-1,sizeof(g));
		for(int i=1;i<=R;++i)
		{
			for(int j=1;j<=C;++j)
				scanf("%d",&g[i][j]);
		}
		scanf("%d%d", &s.r, &s.c);
		scanf("%d%d", &e.r, &e.c);

		scanf("%s",dir);
		if(dir[0]=='n')			D=0;
		else if(dir[0]=='e')	D=1;
		else if(dir[0]=='s')	D=2;
		else if(dir[0]=='w')	D=3;

		printf("%d\n",spfa());
	}

	return 0;
}

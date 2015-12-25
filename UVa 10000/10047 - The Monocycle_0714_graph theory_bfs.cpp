/*
10047 - The Monocycle

graph theory...
BFS...
��ʵ����һ��״̬�Ƚ϶��������
��[dir][face][x][y]��ά�����浱ǰ״̬
dir	---	����
face--- ������ɫ
x,y	--- ����
@	���ӿ���������תΪ[(dir+d)%DIR][p][x][y]
		d=1,3	DIR=4
@	�������Ϲ���Ϊ[dir][(face+d)%COLOR][tx][ty]
		tx=x+dx[dir],ty=y+dy[dir]	d=1	COLOR=5
��ʼ��[0][0][sx][sy]=0,����INF
ȡ[i][0][tx][ty]��Сֵ����...
*/

#include<iostream>
#include<queue>
#define COLOR 5
#define DIR 4
#define MAXN 30
#define INF 0x3f3f3f3f
using namespace std;

struct STATE
{
	short dir,p,x,y;
};

pair<int,int> s,t;
int n,m,dp[4][5][MAXN][MAXN];
char g[MAXN][MAXN];
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

STATE make(int dir,int p,int x,int y)
{
	STATE cur;
	cur.dir=dir;	cur.p=p;	cur.x=x;	cur.y=y;
	return cur;
}

void bfs(int dir,int p,int x,int y)
{
	queue<STATE> q;
	q.push( make(dir,p,x,y) );
	while(!q.empty())
	{
		STATE cur=cur=q.front();	q.pop();
		dir=cur.dir;	p=cur.p;	x=cur.x;	y=cur.y;
		if(!x || x>n || !y || y>m || g[x][y]=='#')
			continue;

		//ԭ����ת
		int d=1;
		if(dp[(dir+d)%DIR][p][x][y]==INF)
		{
			dp[(dir+d)%DIR][p][x][y]=dp[dir][p][x][y]+1;
			q.push( make((dir+d)%DIR,p,x,y) );
		}
		d=3;
		if(dp[(dir+d)%DIR][p][x][y]==INF)
		{
			dp[(dir+d)%DIR][p][x][y]=dp[dir][p][x][y]+1;
			q.push( make((dir+d)%DIR,p,x,y) );
		}

		//��ǰ����
		int tx=x+dx[dir],ty=y+dy[dir];	d=1;
		if(dp[dir][(p+d)%COLOR][tx][ty]==INF)
		{
			dp[dir][(p+d)%COLOR][tx][ty]=dp[dir][p][x][y]+1;
			q.push(make( dir,(p+d)%COLOR,tx,ty) );
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		if(cas!=1)
			putchar('\n');

		memset(g,0,sizeof(g));
		for(int i=1;i<=n;++i)
		{
			scanf("%s",g[i]+1);
			for(int j=1;j<=m;++j)
			{
				if(g[i][j]=='S')
					s=make_pair(i,j);
				else if(g[i][j]=='T')
					t=make_pair(i,j);
			}
		}
		memset(dp,0x3f,sizeof(dp));
		dp[0][0][s.first][s.second]=0;
		bfs(0,0,s.first,s.second);

		printf("Case #%d\n",cas++);
		int key=INF;
		for(int i=0;i<4;++i)
			key=min(key,dp[i][0][t.first][t.second]);

		if(key==INF)
			puts("destination not reachable");
		else
			printf("minimum time = %d sec\n",key);
	}

	return 0;
}

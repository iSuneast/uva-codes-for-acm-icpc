/*
 * 710 - The Game
 * 
 * Ad hoc...
 * bfs...
 * 
 * a simple problem...
 * but actually it's not about "连连看" =_=
 * I misunderstand this problem and think that, we must move in no more than 4 steps...
 * so keep getting WA for a long time...
 * Poor : ( 
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#define MAXN 80
using namespace std;

int w,h;
char g[MAXN][MAXN];
int vis[MAXN][MAXN];

struct STATE
{
	int x,y,dep;
	bool read()
	{
		scanf("%d%d",&x,&y);
		return x+y;
	}
}u,v,tmp;

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

bool valid(int x,int y)
{
	return 0<=x && x<=w+1 && 0<=y && y<=h+1 && g[y][x]!='X';
}

void go(STATE &cur)
{
	vis[cur.y][cur.x]=0;
	queue<STATE> q;
	
	for(q.push(cur); !q.empty(); q.pop())
	{
		for(int d=0;d<4;++d)
		{
			tmp=q.front();
			tmp.dep++;
			while(valid(tmp.x+=dx[d],tmp.y+=dy[d]))
			{
				if(vis[tmp.y][ tmp.x ]!=-1)
					continue;
				vis[tmp.y][tmp.x]=tmp.dep;
				q.push(tmp);
			}
		}
	}
}

void process()
{
	memset(vis,-1,sizeof(vis));
	u.dep=0;
	go(u);
	if(vis[v.y][v.x]==-1)
		puts("impossible.");
	else
		printf("%d segments.\n",vis[v.y][v.x]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    for(int cas=1;scanf("%d%d%*c",&w,&h)!=EOF && (w||h);++cas)
    {
    	printf("Board #%d:\n",cas);
    	
    	memset(g,0,sizeof(g));
    	for(int i=1;i<=h;++i)
    	{
    		gets(g[i]+1);
    	}
		for(int pair=1;;++pair)
		{
			bool more=min(u.read(),v.read());
			if(!more)
				break;
					
			printf("Pair %d: ",pair);
			if(g[u.y][u.x]!='X' || g[v.y][v.x]!='X')
			{
				puts("impossible.");
				continue;
			}
			g[u.y][u.x]=g[v.y][v.x]=' ';
			process();
			g[u.y][u.x]=g[v.y][v.x]='X';
		}
		putchar(10);
    }

    return 0;
}


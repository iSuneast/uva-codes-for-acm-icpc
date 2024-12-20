/*
11494 - Queen

graph theory...
bfs...
好小的图啊...
*/

#include<iostream>
#include<queue>
#define MAXN 10
using namespace std;

struct point
{
	int x,y;
}start,end;

int chess[MAXN][MAXN];

int hash(int x,int y)
{
	return x*MAXN+y;
}

int bfs()
{
	memset(chess,0,sizeof(chess));
	queue<int> q;
	int cur=hash(start.x,start.y),final=hash(end.x,end.y);
	if(cur==final)
		return 0;
	q.push(cur);
	while(!q.empty())
	{
		cur=q.front();	q.pop();
		int tx=cur/MAXN,ty=cur%MAXN;
		int dis=chess[tx][ty];
		for(int i=1;i<=8;++i)
		{
			if(!chess[i][ty])
				chess[i][ty]=dis+1,q.push(hash(i,ty));
			if(!chess[tx][i])
				chess[tx][i]=dis+1,q.push(hash(tx,i));
		}
		int px,py;
		px=tx,py=ty;
		while(px && py)
		{
			if(!chess[px][py])
				chess[px][py]=dis+1,q.push(hash(px,py));
			--px,--py;
		}
		px=tx,py=ty;
		while(px<=8 && py)
		{
			if(!chess[px][py])
				chess[px][py]=dis+1,q.push(hash(px,py));
			++px,--py;
		}
		px=tx,py=ty;
		while(px<=8 && py<=8)
		{
			if(!chess[px][py])
				chess[px][py]=dis+1,q.push(hash(px,py));
			++px,++py;
		}
		px=tx,py=ty;
		while(px && py<=8)
		{
			if(!chess[px][py])
				chess[px][py]=dis+1,q.push(hash(px,py));
			--px,++py;
		}
	}
	return chess[end.x][end.y];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d%d%d",&start.x,&start.y,&end.x,&end.y)!=EOF 
		&& (start.x || start.y || end.x || end.y))
		printf("%d\n",bfs());

	return 0;
}

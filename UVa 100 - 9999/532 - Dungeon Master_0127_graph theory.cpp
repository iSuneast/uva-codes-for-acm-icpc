/*
532 - Dungeon Master
*/

#include<iostream>

using namespace std;

char mat[50][50][50];
bool flag[50][50][50];
int l,r,c,dis[50][50][50];
int dx[]={0,0,1,-1,0,0},dy[]={1,-1,0,0,0,0},dz[]={0,0,0,0,1,-1};

struct point
{
	int x,y,z;
};

void bfs(point s)
{
	int front=0,rear=0,d;
	point t,q[30000];
	q[rear++]=s;
	flag[s.x][s.y][s.z]=true;
	dis[s.x][s.y][s.z]=0;
	while(front<rear)
	{
		s=q[front++];
		for(d=0;d<6;d++)
		{
			t.x=s.x+dx[d],t.y=s.y+dy[d],t.z=s.z+dz[d];
			if(mat[t.x][t.y][t.z]&&(mat[t.x][t.y][t.z]!='#')&&(!flag[t.x][t.y][t.z]))
			{
				q[rear++]=t;
				flag[t.x][t.y][t.z]=true;
				dis[t.x][t.y][t.z]=dis[s.x][s.y][s.z]+1;
			}
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	int i,j,k;
	point s,e;
	while(cin>>l>>r>>c&&(l||r||c))
	{
		memset(flag,0,sizeof(flag));
		memset(mat,0,sizeof(mat));
		memset(dis,0,sizeof(dis));

		for(i=1;i<=l;i++)
			for(j=1;j<=r;j++)
				for(k=1;k<=c;k++)
				{
					cin>>mat[i][j][k];
					if(mat[i][j][k]=='S')
						s.x=i,s.y=j,s.z=k;
					else if(mat[i][j][k]=='E')
						e.x=i,e.y=j,e.z=k;
				}
		bfs(s);
		if(dis[e.x][e.y][e.z])
			cout<<"Escaped in "<<dis[e.x][e.y][e.z]<<" minute(s)."<<endl;
		else
			cout<<"Trapped!"<<endl;
	}

return 0;
}

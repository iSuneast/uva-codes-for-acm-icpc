/*
10267 - Graphical Editor

UVa的数据真的是万恶到家了...
没有vis数组的DFS函数存在潜在的死循环...
可能会存在color==c的情况...
即:用同一种颜色填充已存在的区域.
于是就死循环了.
*/

#include<iostream>

using namespace std;

char cmd,c,g[260][260],vis[260][260],buf[30];	//定义一个vis数组保存访问状态
int m,n,x,y,i,j,y1,y2,x1,x2;

void dfs(int x,int y,char color)
{
	if(x<=0 || y<=0 || x>n || y>m)
		return ;
	else if(vis[x][y] || g[x][y]!=color)
		return ;
	g[x][y]=c;vis[x][y]=1;
	dfs(x,y-1,color);
	dfs(x,y+1,color);
	dfs(x-1,y,color);
	dfs(x+1,y,color);
 }

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10267.txt","w",stdout);

	while(cin>>cmd && cmd !='X')
		switch(cmd)
		{
		case 'I':
			cin>>m>>n;
			memset(g,0,sizeof(g));
			break;
		case 'C':
			memset(g,0,sizeof(g));
			break;
		case 'L':
			cin>>x>>y>>c;
			g[y][x]=c;
			break;
		case 'V':
			cin>>x>>y1>>y2>>c;
			if(y1 > y2)
				swap(y1,y2);
			for(i=y1;i<=y2;i++)
				g[i][x]=c;
			break;
		case 'H':
			cin>>x1>>x2>>y>>c;
			if(x1 > x2)
				swap(x1,x2);
			for(i=x1;i<=x2;i++)
				g[y][i]=c;
			break;
		case 'K':
			cin>>x1>>y1>>x2>>y2>>c;
			for(i=x1;i<=x2 && i<=m;i++)
				for(j=y1;j<=y2 && j<=n;j++)
					g[j][i]=c;
			break;
		case 'F':
			cin>>x>>y>>c;
			memset(vis,0,sizeof(vis));
			dfs(y,x,g[y][x]);
			break;
		case 'S':
			cin>>buf;
			cout<<buf<<endl;
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
					if(!g[i][j])
						cout<<'O';
					else
						cout<<g[i][j];
				cout<<endl;
			}
			break;
		default :
			gets(buf);
			break;
		}

return 0;
}

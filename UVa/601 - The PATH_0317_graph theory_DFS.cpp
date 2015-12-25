/*
601 - The PATH

好麻烦的题目啊...
DFS...
*/

#include<iostream>
#define MAXN 10000
using namespace std;

int key,n;
char g[MAXN][MAXN];

void dfs(int x,int y,char c,char a)
{
	if(x<=0 || x>n || y<=0 || y>n || g[x][y]!=a)
		return ;
	g[x][y]=c;
	dfs(x,y-1,c,a);	dfs(x,y+1,c,a);
	dfs(x-1,y,c,a);	dfs(x+1,y,c,a);
}

void chk_w()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(g[i][j]=='U')
				if(	(g[i][j-1]==0 && g[i][j+1]==0)
					||(g[i][j-1]==0 && g[i][j+1]=='_')
					||(g[i][j-1]=='-' && g[i][j+1]==0)
					||(g[i][j-1]=='-' && g[i][j+1]=='_')
					||(g[i][j-1]=='_' && g[i][j+1]=='-') )
				{
					key=2;
					return ;
				}
}

void chk_b()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(g[i][j]=='U')
				if(	(g[i-1][j]==0 && g[i+1][j]==0)
					|| (g[i-1][j]==0 && g[i+1][j]=='\\' )
					|| (g[i-1][j]=='|' && g[i+1][j]==0)
					|| (g[i-1][j]=='|' && g[i+1][j]=='\\' )
					|| (g[i-1][j]=='\\' && g[i+1][j]=='|') )
				{
					key=3;
					return ;
				}
}

void print()
{
	switch (key)
	{
	case 0:
		cout<<"White has a winning path."<<endl;break;
	case 1:
		cout<<"Black has a winning path."<<endl;break;
	case 2:
		cout<<"White can win in one move."<<endl;break;
	case 3:
		cout<<"Black can win in one move."<<endl;break;
	case 4:
		cout<<"There is no winning path."<<endl;break;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("601.txt","w",stdout);

	int i,j;
	while(cin>>n && n)
	{
		memset(g,0,sizeof(g));
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				cin>>g[i][j];
		key=4;
		for(i=1;i<=n;i++)
			if(g[i][1]=='W')
				dfs(i,1,'-','W');
		for(i=1;i<=n;i++)
			if(g[i][n]=='-')
				key=0;
		if(key>0)
		{
			for(i=1;i<=n;i++)
				if(g[1][i]=='B')
					dfs(1,i,'|','B');
			for(i=1;i<=n;i++)
				if(g[n][i]=='|')
					key=1;
		}
		if(key>1)
		{
			for(i=1;i<=n;i++)
				if(g[i][n]=='W')
					dfs(i,n,'_','W');
			chk_w();
			if(key>2)
			{
				for(i=1;i<=n;i++)
					if(g[n][i]=='B')
						dfs(n,i,'\\','B');
				chk_b();
			}
		}
		print();
	}

return 0;
}

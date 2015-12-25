/*
10010 - Where's Waldorf?
*/

#include<iostream>
#include<string>

using namespace std;

char grid[52][52];
string words;
int t,m,n,k,flag,len,p;

void xi(int x,int y,int p)
{
	if(p==len)
	{
		flag=1;
		return ;
	}
	if(words[p]==grid[x+1][y])
		xi(x+1,y,p+1);
	else
		return ;
}

void s(int x,int y,int p)
{	
	if(p==len)
	{
		flag=1;
		return ;
	}
	if(words[p]==grid[x-1][y])
		s(x-1,y,p+1);
	else
		return ;
}

void zs(int x,int y,int p)
{
	if(p==len)
	{
		flag=1;
		return ;
	}
	if(words[p]==grid[x-1][y-1])
		zs(x-1,y-1,p+1);
	else
		return ;
}

void yx(int x,int y,int p)
{
	if(p==len)
	{
		flag=1;
		return ;
	}
	if(words[p]==grid[x+1][y+1])
		yx(x+1,y+1,p+1);
	else
		return ;
}

void ys(int x,int y,int p)
{
	if(p==len)
	{
		flag=1;
		return ;
	}
	if(words[p]==grid[x-1][y+1])
		ys(x-1,y+1,p+1);
	else
		return ;
}

void z(int x,int y,int p)
{
	if(p==len)
	{
		flag=1;
		return ;
	}
	if(words[p]==grid[x][y-1])
		z(x,y-1,p+1);
	else
		return ;
}

void yi(int x,int y,int p)
{
	if(p==len)
	{
		flag=1;
		return ;
	}
	if(words[p]==grid[x][y+1])
		yi(x,y+1,p+1);
	else
		return ;
}

void zx(int x,int y,int p)
{
	if(p==len)
	{
		flag=1;
		return ;
	}
	if(words[p]==grid[x+1][y-1])
		zx(x+1,y-1,p+1);
	else
		return ;
}

void dfs(int x,int y,int p)
{
s(x,y,p);
xi(x,y,p);
z(x,y,p);
yi(x,y,p);
zs(x,y,p);
zx(x,y,p);
ys(x,y,p);
yx(x,y,p);
}

void find()
{
	int i,j;

	for(i=0;i<=m;i++)
		for(j=0;j<=n;j++)
			if(words[0]==grid[i+1][j+1])
			{
				flag=0;
				dfs(i+1,j+1,1);
				if(flag)
				{
					cout<<i+1<<' '<<j+1<<endl;
					return ;
				}
			}
}

int main()
{
	int i,j;
	cin>>t;
	while(t--)
	{
		memset(grid,0,sizeof(grid));
		cin>>m>>n;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				cin>>grid[i+1][j+1];
				if(grid[i+1][j+1]<'a')
					grid[i+1][j+1]+=32;
			}
		cin>>k;
		getchar();
		while(k--)
		{
			getline(cin,words);
			len=words.length();
			for(i=0;i<len;i++)
				if(words[i]<'a')
					words[i]+=32;
			find();
		}
		if(t)
			cout<<endl;
	}

return 0;
}

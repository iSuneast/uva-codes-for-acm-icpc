/*
785 - Grid Colouring
*/

#include<iostream>
#include<cstring>

using namespace std;

char maz[35][85];
int n,size,x,y,w;

void print()
{
	int i;
	for(i=0;i<=size;i++)
		cout<<maz[i]<<endl;
}

void dfs(int a,int b)
{
	if(maz[a][b]==' ')
		maz[a][b]=w;
	else
		return ;
	dfs(a+1,b);
	dfs(a-1,b);
	dfs(a,b-1);
	dfs(a,b+1);
}

void get_xy()
{
	int i,j;
	for(i=0;i<size;i++)
		for(j=0;j<strlen(maz[i]);j++)
			if(maz[i][j]!='X'&&maz[i][j]!=' ')
			{
				x=i,y=j;
				w=maz[x][y];
				maz[x][y]=' ';
				dfs(x,y);
			}
}

int get_maze()
{
	size=0;
	memset(maz,0,sizeof(maz));
	while(gets(maz[size]))
		if(maz[size][0]!='_')
			size++;
		else
			break;
	if(size)
		return 1;
	return 0;
}

int main()
{
	while(get_maze())
	{
		get_xy();
		print();
	}

return 0;
}

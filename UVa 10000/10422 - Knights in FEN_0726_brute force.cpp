/*
10422 - Knights in FEN

backtracking...
brute force...
暴力回溯...
加了很土的剪枝,还用位压缩保存图优化...
只要不超时,这题应该就是AC吧...
*/

#include<iostream>
#define SZ 5
#define INF 0x3f3f3f3f
using namespace std;

const int end=549855;
const int dx[]={-2,-1,1,2,-2,-1,1,2},dy[]={1,2,2,1,-1,-2,-2,-1};
char s[10],g[SZ][SZ];
int key;

int hash()
{
	int key=0;
	for(int i=0;i<SZ;++i)
		for(int j=0;j<SZ;++j)
			if(g[i][j]=='1')
				key|=(1<<(i*SZ+j));
	return key;
}

int dfs(int cur,int x,int y,int dep)
{
	if(cur==end && x==2 && y==2)
		key=min(key,dep);
	else if(dep<10 && dep<key)
	{
		int p=x*SZ+y;
		for(int d=0;d<8;++d)
		{
			int tx=x+dx[d],ty=y+dy[d];
			if(tx>=0 && tx<SZ && ty>=0 && ty<SZ)
			{
				if(g[tx][ty]=='1')
				{
					int p1=tx*SZ+ty;
					swap(g[tx][ty],g[x][y]);
					dfs(cur-(1<<p1)+(1<<p),tx,ty,dep+1);
					swap(g[tx][ty],g[x][y]);
				}
				else
					dfs(cur,tx,ty,dep+1);
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);gets(s);
	while(dataset--)
	{
		int ori=0,x,y;
		for(int i=0;i<SZ;++i)
		{
			gets(s);
			for(int j=0;j<SZ;++j)
			{
				g[i][j]=s[j];
				if(s[j]=='1')
					ori|=(1<<(i*SZ+j));
				else if(s[j]==' ')
					x=i,y=j;
			}
		}

		key=INF;
		dfs(ori,x,y,0);
		if(key==INF)
			printf("Unsolvable in less than 11 move(s).\n");
		else
			printf("Solvable in %d move(s).\n",key);
	}

	return 0;
}

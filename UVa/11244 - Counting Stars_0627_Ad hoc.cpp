/*
11244 - Counting Stars

Ad hoc...
������...
3*3�ķ���ֻ���е�����һ��'*'��������...
*/

#include<iostream>
#define MAXN 110
using namespace std;

int r,c;
char g[MAXN][MAXN];

bool chk(int x,int y)
{
	return g[x-1][y-1]!='*' && g[x-1][y]!='*' && g[x-1][y+1]!='*'
		&& g[x][y-1]!='*'					&& g[x][y+1]!='*'
		&& g[x+1][y-1]!='*' && g[x+1][y]!='*' && g[x+1][y+1]!='*';
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(cin>>r>>c && (r||c))
	{
		memset(g,0,sizeof(g));
		for(int i=1;i<=r;++i)
			scanf("%s",g[i]+1);
		int key=0;
		for(int i=1;i<=r;++i)
			for(int j=1;j<=c;++j)
				if(g[i][j]=='*' && chk(i,j))
					++key;
		cout<<key<<endl;
	}

	return 0;
}

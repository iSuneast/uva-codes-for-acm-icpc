/*
10502 - Counting Rectangles

DP...
brute force...
看来UVa这题的数据的确是水了...
O(n^4)的复杂度竟然也可以过...
*/

#include<iostream>
#define MAXN 110
using namespace std;

int g[MAXN][MAXN],n,m;

int main()
{
//	freopen("in.txt","r",stdin);

	while(cin>>n && n)
	{
		cin>>m;
		int i,j,key=0;
		char c;
		memset(g,0,sizeof(g));
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
			{
				cin>>c;
				g[i][j]=c-'0'+g[i][j-1]+g[i-1][j]-g[i-1][j-1];
			}
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
				for(int x=0;x<i;++x)
					for(int y=0;y<j;++y)
						if(g[i][j]-g[x][j]-g[i][y]+g[x][y]==(i-x)*(j-y))
							++key;
		cout<<key<<endl;
	}

	return 0;
}

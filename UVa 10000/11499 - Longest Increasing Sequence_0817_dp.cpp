/*
11499 - Longest Increasing Sequence

dp...
o(n^2)预处理得到next[i][j]...
表示(i,j)到(i,next[i][j])这段区间元素递增

然后O(N^3logN)按行枚举子矩阵
从(i,j)开始,可以得到宽度w=next[i][j]-j+1的长条
k=i+1-n,二分[k][j]在(k-1,j)-(k-1,w)区间的位置p
新的w=min(p-j+1,next[k][j])

同时更新解max((k-i+1)*w)
*/

#include<iostream>
#include<algorithm>
#define MAXN 603
using namespace std;

int n,m,g[MAXN][MAXN],next[MAXN][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
				scanf("%d",&g[i][j]);

			next[i][m-1]=m-1;
			for(int j=m-2;j>=0;--j)
			{
				if(g[i][j]<g[i][j+1])
					next[i][j]=next[i][j+1];
				else
					next[i][j]=j;
			}
		}

		int key=0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				int w=next[i][j]-j+1;
				key=max(key,w);
				for(int k=i+1;k<n;++k)
				{
					int p=lower_bound(g[k-1]+j,g[k-1]+j+w,g[k][j])-g[k-1]-j;
					if(p<=0)
						break;
					w=min(p,next[k][j]-j+1);
					key=max(key,(k-i+1)*w);
				}
			}
		}

		printf("%d\n",key);
	}

	return 0;
}

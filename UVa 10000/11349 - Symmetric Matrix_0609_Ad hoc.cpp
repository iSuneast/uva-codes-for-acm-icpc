/*
11349 - Symmetric Matrix

ad hoc...
水题卡人啊。。。
-2^32<=M[i][j]<=2^32
这里ijiushi一个巨大的tricky...
int的表示范围为[-2^32,2^32)...
*/

#include<iostream>
#define MAXN 110
using namespace std;

long long mat[MAXN][MAXN],n;
char buf[10];

bool chk()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(mat[i][j]!=mat[n-i+1][n-j+1])
				return false;
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%s%s%lld",buf,buf,&n);
		bool neg=false;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				scanf("%lld",&mat[i][j]);
				if(mat[i][j]<0)
					neg=true;
			}
		if(!neg && chk())
			printf("Test #%d: Symmetric.\n",cas);
		else
			printf("Test #%d: Non-symmetric.\n",cas);
	}

	return 0;
}

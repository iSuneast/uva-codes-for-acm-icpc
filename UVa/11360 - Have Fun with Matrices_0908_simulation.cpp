/*
11360 - Have Fun with Matrices

simulation...
just do as problem description...
*/

#include<iostream>
#define MAXN 13
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	int mat[MAXN][MAXN],n,m,a,b;
	char op[MAXN];

	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%s",op);
			for(int j=1;j<=n;++j)
				mat[i][j]=op[j-1]-'0';
		}
		scanf("%d",&m);
		int dif=0;
		while(m--)
		{
			scanf("%s",op);
			switch(op[0])
			{
			case'r':
				scanf("%d%d",&a,&b);
				for(int i=1;i<=n;++i)
					swap(mat[a][i],mat[b][i]);
				break;
			case'c':
				scanf("%d%d",&a,&b);
				for(int i=1;i<=n;++i)
					swap(mat[i][a],mat[i][b]);
				break;
			case'i':
				++dif;	break;
			case'd':
				--dif;	break;
			case't':
				for(int i=1;i<=n;++i)
					for(int j=1;j<i;++j)
						swap(mat[i][j],mat[j][i]);
			}
		}

		printf("Case #%d\n",cas);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				printf("%d",(mat[i][j]+dif%10+10)%10);
			putchar(10);
		}
		putchar(10);
	}

	return 0;
}

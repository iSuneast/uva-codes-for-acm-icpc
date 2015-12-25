/*
11470 - Square Sums

Ad hoc...
Ë®Ìâ...
*/

#include<iostream>
#include<cmath>
#define MAXN 12
using namespace std;

int n,mat[MAXN][MAXN];

void sum(int p,int l)
{
	if(l<=0)
		return;
	else if(l==1)
	{
		printf(" %d",mat[p][p]);
		return ;
	}
	int key=0;
	for(int i=p;i<p+l;++i)
		key+=mat[p][i]+mat[p+l-1][i];
	for(int i=p+1;i<p+l-1;++i)
		key+=mat[i][p]+mat[i][p+l-1];
	printf(" %d",key);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",&mat[i][j]);

		printf("Case %d:",cas++);
		for(int i=1;i<=ceil(n/2.0);++i)
			sum(i,n-(i-1)*2);
		putchar('\n');
	}

	return 0;
}

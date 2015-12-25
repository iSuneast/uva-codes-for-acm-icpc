/*
11597 - Spanning Subtree

graph theory..,
完全图的没有共通边的生成树个数...
顶点数/2
*/

#include<cstdio>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n,cas=1;
	while(scanf("%d",&n)!=EOF && n)
		printf("Case %d: %d\n",cas++,n>>1);

	return 0;
}

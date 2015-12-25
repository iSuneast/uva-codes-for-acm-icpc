/*
278 - Chess

Ad hoc...
不可能对说有的棋子都做一次dfs.
r,Q --- min(n,m)
k --- (n*m+1)/2
K --- ((n+1)/2)*((m+1)/2)
*/

#include<iostream>
using namespace std;

int n,m;
bool op[7];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("314","w",stdout);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%s%d%d",op,&n,&m);

		if(op[0]=='r' || op[0]=='Q')
			printf("%d\n",min(n,m));
		else if(op[0]=='k')
			printf("%d\n",(n*m+1)/2);
		else
			printf("%d\n",((n+1)/2)*((m+1)/2));
	}

	return 0;
}

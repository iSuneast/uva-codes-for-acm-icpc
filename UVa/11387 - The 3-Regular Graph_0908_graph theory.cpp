/*
11387 - The 3-Regular Graph

graph theory...
for each node degree=3 so
total degree = 3*n/2
so n should be an even
just link(i,i+1),link(i,i+n/2) is an ok solution
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		if(n<=3 || n&1)
		{
			puts("Impossible");
			continue;
		}
		printf("%d\n",n*3/2);
		for(int i=1;i<=n;++i)
			printf("%d %d\n",i,(i%n)+1);
		int jump=n/2;
 		for(int i=1;i<=jump;++i)
 			printf("%d %d\n",i,i+jump);
	}

	return 0;
}

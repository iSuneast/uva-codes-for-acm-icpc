/*
11723 - Numbering Roads

math...
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,r,cas=1;
	while(scanf("%d%d",&n,&r)!=EOF && (n||r))
	{
		int key=floor(1.0*n/r);
		if(n%r==0)
			--key;
		if(floor(1.0*n/r)>26)
			printf("Case %d: impossible\n",cas++);
		else
			printf("Case %d: %d\n",cas++,key);
	}

	return 0;
}

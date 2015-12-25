/*
275 - Expanding Fractions

Ad hoc...
找分数的循环节...
同UVa202...
*/

#include<iostream>
#include<ctime>
#define MAXN 1003
using namespace std;

int pos[MAXN],n,m;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		memset(pos,0,sizeof(pos));
		int dep=1;
		if(n>m)
			printf("%d",n/m);
		n%=m;
		putchar('.');
		pos[n]=dep;
		while(n)
		{
			n*=10;
			printf("%d",n/m);
			n%=m;

			if(!pos[n])
				pos[n]=++dep;
			else
				break;

			if(dep%50==0)
				putchar(10);
		}
		putchar(10);

		if(n)
			printf("The last %d digits repeat forever.\n\n",dep-pos[n]+1);
		else
			puts("This expansion terminates.\n");
	}

	return 0;
}

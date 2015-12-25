/*
11482 - Building a Triangular Museum

simulation...
just do as the problem description...
be careful about the input process...
and don't print extra blank,or you'll get PE.
*/

#include<iostream>
using namespace std;

void blank(int n,char c)
{
	while(n--)
		putchar(c);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1,n,m;
	while(scanf("%d%d",&m,&n)!=EOF && (n||m))
	{
		printf("Triangular Museum %d\n",cas++);
		int front=n*m-1;
		for(int i=0;i<n;++i)
		{
			int a=0,b=2*m;
			for(int j=0;j<m-1;++j)
			{
				blank(front--,' ');
				putchar('/');
				blank(a,' ');
				putchar('\\');

				b-=2;
				for(int k=0;k<i;++k)
				{
					blank(b,' ');
					putchar('/');
					blank(a,' ');
					putchar('\\');
				}
				a+=2;
				putchar(10);
			}

			blank(front--,' ');
			putchar('/');
			blank(a,'_');
			putchar('\\');

			b-=2;

			for(int k=0;k<i;++k)
			{
				blank(b,' ');
				putchar('/');
				blank(a,'_');
				putchar('\\');
			}

			a+=2;
			putchar(10);
		}
		putchar(10);
	}

	return 0;
}

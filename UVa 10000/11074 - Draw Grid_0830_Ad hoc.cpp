/*
11074 - Draw Grid

Ad hoc..
just simulation as the problem description¡£¡£¡£
*/

#include<iostream>
using namespace std;

void draw(int n,char c)
{
	while(n--)
		putchar(c);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int s,t,n,cas=1;
	while(scanf("%d%d%d",&s,&t,&n)!=EOF && (s||t||n))
	{
		int len=(s+t)*n+t;

		printf("Case %d:\n",cas++);
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<t;++j)
				draw(len,'*'),putchar(10);
			for(int j=0;j<s;++j)
			{
				for(int k=0;k<n;++k)
				{
					draw(t,'*');
					draw(s,'.');
				}
				draw(t,'*'),putchar(10);
			}
		}
		for(int j=0;j<t;++j)
			draw(len,'*'),putchar(10);

		putchar(10);
	}

	return 0;
}

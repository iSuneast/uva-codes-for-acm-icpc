/*
11350 - Stern-Brocot Tree

simulation...
left cur right
if 'L' left left+cur cur
if 'R' cur cur+right right

long long is quite enough to handle this
*/

#include<iostream>
using namespace std;

struct pii
{
	long long a,b;
}l,r,c;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	char s[90];
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%s",s);
		l.a=0;	l.b=1;
		c.a=1;	c.b=1;
		r.a=1;	r.b=0;

		for(int i=0;s[i];++i)
		{
			if(s[i]=='L')
			{
				r.a=l.a+c.a;
				r.b=l.b+c.b;
				swap(c,r);
			}
			else
			{
				l.a=r.a+c.a;
				l.b=r.b+c.b;
				swap(c,l);
			}
		}

		printf("%lld/%lld\n",c.a,c.b);
	}

	return 0;
}

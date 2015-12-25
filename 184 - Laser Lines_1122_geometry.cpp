/*
184 - Laser Lines

geometry...
just find out how many points >=3 are in the same line
and then output all of the answers in the correct format...

remember that 
the answer sets are mixed with each other at most two points...

(a,b,c,d) is a correct answer
and so (b,c,d) is also an answer but it's invalid...
*/

#include<iostream>
#include<algorithm>
#define MAXN 303
#define SZ 15
using namespace std;

struct POINT
{
	int x,y;
	bool operator<(const POINT &t)const
	{
		return x<t.x || (x==t.x && y<t.y);
	}
}pnt[MAXN];
int key[SZ],sz,n;
bool line[MAXN][MAXN];

bool read()
{
	n=0;
	while(scanf("%d%d",&pnt[n].x,&pnt[n].y)!=EOF
		&& (pnt[n].x || pnt[n].y))
		++n;
	sort(pnt,pnt+n);
	return n;
}

bool coincide(const POINT &a,const POINT &b,const POINT &c)
{
	return (b.y-a.y)*(c.x-a.x)==(c.y-a.y)*(b.x-a.x);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(read())
	{
		memset(line,0,sizeof(line));
		bool got=false;

		for(int i=0;i<n;++i)
		{
			key[0]=i;
			for(int j=i+1;j<n;++j)
			{
				if(line[i][j])
					continue;

				key[1]=j;
				sz=2;
				for(int k=j+1;k<n;++k)
				{
					if(coincide(pnt[i],pnt[j],pnt[k]))
						key[ sz++ ]=k;
				}

				if(sz==2)
					continue;

				if(!got)
					puts("The following lines were found:");
				got=true;
				for(int a=0;a<sz;++a)
				{
					printf("(%4d,%4d)",pnt[ key[a] ].x,pnt[ key[a] ].y);
					for(int b=a+1;b<sz;++b)
						line[ key[a] ][ key[b] ]=true;
				}
				putchar(10);
			}
		}

		if(!got)
			puts("No lines were found");
	}

	return 0;
}

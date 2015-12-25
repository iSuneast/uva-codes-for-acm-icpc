/*
11227 - The silver bullet.

brute force...

Use STL set to detect same points
and then O(n^3) brute force is ok...

we find two point (u,v) at first
scan all of the points
count how many points lay in the line (u,v)
*/

#include<iostream>
#include<set>
#define MAXN 103
using namespace std;

struct POINT
{
	int x,y;
	bool operator<(const POINT&t)const
	{
		return x==t.x && y<t.y || x<t.x;
	}
}pnt[MAXN];
set<POINT> sp;
char buf[10];
int tot,n;

int input()
{
	scanf("%s",buf);
	for(int i=0;buf[i];++i)
		if(buf[i]=='.')
		{
			buf[i]=0;
			return atoi(buf)*100+atoi(buf+i+1);
		}

		return atoi(buf)*100;
}

bool ok(POINT &a,POINT &b,POINT &c)
{
	return (c.y-a.y)*(c.x-b.x)==(c.y-b.y)*(c.x-a.x);
}

int process()
{
	int key=0;
	for(int i=0;i<tot;++i)
	{
		for(int j=i+1;j<tot;++j)
		{
			int ans=0;
			for(int k=0;k<tot;++k)
				ans+=ok(pnt[i],pnt[j],pnt[k]);
			key=max(key,ans);
		}
	}
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d",&n);
		tot=0;
		sp.clear();
		for(int i=0;i<n;++i)
		{
			pnt[tot].x=input();
			pnt[tot].y=input();
			if(sp.find(pnt[tot])==sp.end())
			{
				sp.insert(pnt[tot]);
				++tot;
			}
		}

		if(tot==1)
			printf("Data set #%d contains a single gnu.\n",cas);
		else
			printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n"
			,cas,tot,process());
	}

	return 0;
}

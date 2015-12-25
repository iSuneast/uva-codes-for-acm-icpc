/*
11697 - Playfair Cipher

simulation...
simple problem.
no trick...
*/

#include<iostream>
#define MAXN 1003
using namespace std;

char s[MAXN],g[30];
int h[128];

struct POINT
{
	int x,y;
}a,b;

void general()
{
	memset(h,-1,sizeof(h));
	h['Q']=-2;

	gets(s);
	int p=0;
	for(int i=0;s[i];++i)
	{
		if(!isalpha(s[i]))
			continue;

		s[i]=toupper(s[i]);
		if(h[ s[i] ]==-1)
		{
			h[ s[i] ]=p;
			g[p++]=s[i];
		}
	}

	for(int i='A';i<='Z';++i)
	{
		if(h[i]==-1)
		{
			h[i]=p;
			g[p++]=i;
		}
	}
}

void locate(char c,POINT &cur)
{
	cur.x=h[ c ]/5;
	cur.y=h[ c ]%5;
}

char query(int x,int y)
{
	x%=5;
	y%=5;
	return g[ x*5+y ];
}

bool chk(char &u,char &v)
{
	if(u==v || !v)
	{
		v='X';
		return true;
	}

	locate(u,a);
	locate(v,b);

	if(a.x==b.x)
	{
		u=query(a.x,a.y+1);
		v=query(b.x,b.y+1);
	}
	else if(a.y==b.y)
	{
		u=query(a.x+1,a.y);
		v=query(b.x+1,b.y);
	}
	else
	{
		u=query(a.x,b.y);
		v=query(b.x,a.y);
	}
	return false;
}

void process()
{
	gets(s);
	int l=0;
	for(int i=0;s[i];++i)
		if(isalpha(s[i]))
			s[l++]=toupper(s[i]);
	s[l]=0;

	for(int i=0;i<l;i++)
	{
		char u=s[i],v=s[i+1];
		if(u!=v)
			++i;
		while(chk(u,v))
			;
		putchar(u);
		putchar(v);
	}

	putchar(10);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d%*c",&dataset);
	while(dataset--)
	{
		general();
		process();
	}

	return 0;
}

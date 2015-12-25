/*
422 - Word-Search Wonder

Ad hoc...
×Ö·û´®±©Á¦Æ¥Åä...
*/

#include<iostream>
#define MAXN 110
using namespace std;

char g[MAXN][MAXN],str[MAXN],rev[MAXN];
int n;

bool row(int x,int y,char s[MAXN])
{
	int p=0;
	while(s[p] && g[x][y]==s[p])
		++y,++p;
	return s[p]==0;
}

bool col(int x,int y,char s[MAXN])
{
	int p=0;
	while(s[p] && g[x][y]==s[p])
		++x,++p;
	return s[p]==0;
}

bool ver(int x,int y,char s[MAXN])
{
	int p=0;
	while(s[p] && g[x][y]==s[p])
		++x,++y,++p;
	return s[p]==0;
}

void calc()
{
	int l=strlen(str);
	for(int i=0;i<l;++i)
		rev[i]=str[l-1-i];
	rev[l]=0;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			if(row(i,j,str))
				printf("%d,%d %d,%d\n",i,j,i,j+l-1),l=-1;
			else if(row(i,j,rev))
				printf("%d,%d %d,%d\n",i,j+l-1,i,j),l=-1;

			else if(col(i,j,str))
				printf("%d,%d %d,%d\n",i,j,i+l-1,j),l=-1;

			else if(ver(i,j,str))
				printf("%d,%d %d,%d\n",i,j,i+l-1,j+l-1),l=-1;
			else if(ver(i,j,rev))
				printf("%d,%d %d,%d\n",i+l-1,j+l-1,i,j),l=-1;

			if(l==-1)
				return ;
		}
	puts("Not found");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF)
	{
		gets(str);
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;++i)
			gets(g[i]+1);

		while(gets(str) && strcmp(str,"0"))
			calc();
	}

	return 0;
}

/*
843 - Crypt Kicker

brute force...

after so many times of WA, I finally found the bug:
when using dfs() function, be careful of the action scope of variable

really hard to trace...
*/

#include<iostream>
using namespace std;

char str[100],dic[1003][20],buf[100][20];
int n,dicL[1003],m,bufL[100];
char g[128];
bool flag[128];
int key[100];

bool dfs(int dep)
{
	if(dep==m)
		return true;

	for(int i=0;i<n;++i)
	{
		if(dicL[i]!=bufL[dep])
			continue;

		int j,p=0,pos[100];	//pos[] should be local variable
		for(j=0;j<dicL[i];++j)
		{
			char a=dic[i][j],b=buf[dep][j];
			if(!g[a])
			{
				if(flag[b])
					break;
				pos[p++]=j;
				g[a]=b;
				flag[b]=true;
			}

			if(g[a]!=b)
				break;
		}

		if(j==dicL[i])
		{
			key[dep]=i;
			if(dfs(dep+1))
				return true;
		}

		for(int k=0;k<p;++k)
		{
			flag[ buf[dep][ pos[k] ] ]=false;
			g[ dic[i][ pos[k] ] ]=0;
		}
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	scanf("%d",&n);
	gets(str);
	for(int i=0;i<n;++i)
	{
		gets(dic[i]);
		dicL[i]=strlen(dic[i]);
	}

	while(gets(str))
	{
		int len=strlen(str);
		char *token=strtok(str," ");
		m=0;
		while(token)
		{
			bufL[m]=strlen(token);
			strcpy(buf[m++],token);
			token=strtok(NULL," ");
		}

		memset(g,0,sizeof(g));
		memset(flag,0,sizeof(flag));
		if(dfs(0))
		{
			for(int i=0;i<m;++i)
			{
				if(i)
					putchar(' ');
				printf("%s",dic[ key[i] ]);
			}
		}
		else for(int i=0;i<len;++i)
		{
			if(isalpha(str[i]))
				putchar('*');
			else
				putchar(' ');
		}
		putchar(10);
	}

	return 0;
}

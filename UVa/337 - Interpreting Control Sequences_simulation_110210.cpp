/*
 * 337 - Interpreting Control Sequences
 *
 * simulation...
 * 按题意模拟即可~
 *
 * happy coding~
 */

#include<iostream>
#define MAXN 10
using namespace std;

char buf[1000], key[MAXN][MAXN];

void out()
{
	puts("+----------+");
	for(int i=0;i<MAXN;++i)
	{
		putchar('|');
		for(int j=0;j<MAXN;++j)
		{
			putchar(key[i][j]);
		}
		puts("|");
	}
	puts("+----------+");
}

void clear()
{
	for(int i=0;i<MAXN;++i)
	{
		fill_n(key[i],MAXN,' ');
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	for(int line, cas=1; scanf("%d", &line)!=EOF && line; ++cas)
	{
		gets(buf);

		clear();
		int r=0, c=0;
		bool insert=false;
		while(line--)
		{
			gets(buf);
			for(int i=0,len=strlen(buf); i<len; ++i)
			{
				if(buf[i]=='^')
				{
					++i;
					if(buf[i]=='b')
						c=0;
					else if(buf[i]=='c')
						clear();
					else if(buf[i]=='d')
					{
						if(r+1<MAXN)
							++r;
					}
					else if(buf[i]=='e')
					{
						for(int p=c+1;p<MAXN;++p)
							key[r][p-1]=key[r][p];
						key[r][MAXN-1]=' ';
					}
					else if(buf[i]=='h')
						r=c=0;
					else if(buf[i]=='i')
						insert=true;
					else if(buf[i]=='l')
					{
						if(c>0)
							--c;
					}
					else if(buf[i]=='o')
						insert=false;
					else if(buf[i]=='r')
					{
						if(c+1<MAXN)
							++c;
					}
					else if(buf[i]=='u')
					{
						if(r>0)
							--r;
					}
					else if(buf[i]=='^')
						key[r][c]='^';
					else if(isdigit(buf[i]))
					{
						r=buf[i++]-'0';
						c=buf[i]-'0';
					}
				}
				else
				{
					if(insert)
					{
						for(int p=MAXN-1; p>c; --p)
							key[r][p]=key[r][p-1];
					}
					key[r][c]=buf[i];
					if(c+1<MAXN)
						++c;
				}
			}
		}

		printf("Case %d\n", cas);
		out();
	}

	return 0;
}

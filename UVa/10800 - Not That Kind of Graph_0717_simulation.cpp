/*
10800 - Not That Kind of Graph

simulation...
直接按题目的意思模拟即可...
小心数组越界...
*/

#include<iostream>
#define MAXN 110
#define INF 0x3f3f3f3f
using namespace std;

char g[MAXN][MAXN];
char op[MAXN],pre,hash[128];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	hash['R']='/';	hash['F']='\\';	hash['C']='_';
	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%s",op);
		int p=0,max_y=-INF,min_y=INF,y=50;
		memset(g,0,sizeof(g));
		pre=0;

		while(op[p]!=0)
		{
			if(op[p]=='R' && pre==hash['R'])
				++y;
			else if(op[p]=='F' && pre!=hash['R'])
				--y;
			else if(op[p]=='C' && pre==hash['R'])
				++y;

			pre=g[y][p]=hash[ op[p] ];
			++p;
			min_y=min(min_y,y);
			max_y=max(max_y,y);
		}

		printf("Case #%d:\n",cas);
		for(int j=max_y;j>=min_y;--j)
		{
			int i=p-1;
			while(i>=0 && !g[j][i])
				--i;
			while(i>=0)
			{
				if(!g[j][i])
					g[j][i]=' ';
				--i;
			}
			printf("| %s\n",g[j]);
		}

		putchar('+');
		for(int i=0;i<=p+1;++i)
			putchar('-');
		puts("\n");
	}

	return 0;
}

/*
186 - Trip Routing

floyd-warshall...
题目倒是不难...
输入输出那边确实太技巧性了...

input那边用到strtok...map...
初始化图的时候有多次松弛操作...
floyd-warshall那边要记录路径..
print那边用到了递归...
当值为-1的时候递归结束...
*/

#include<iostream>
#include<string>
#include<map>
#define min(a,b) ((a)<(b))?(a):(b)
#define MAXN 110
#define INF 1e9
using namespace std;

int g[MAXN][MAXN],flag[MAXN][MAXN],cnt=0;
string roads[MAXN][MAXN];
char buf[100];
map<string,int> msi;
map<int,string> mis;

void init()
{
	for(int i=0;i<MAXN;++i)
		for(int j=0;j<MAXN;++j)
		{
			if(i==j)
				g[i][j]=0;
			else
				g[i][j]=INF;
			flag[i][j]=-1;
		}
}

void input()
{
	while(gets(buf) && strcmp(buf,""))
	{
		char *token=strtok(buf,",");
		if(msi.find(token)==msi.end())
		{
			msi[token]=cnt;
			mis[cnt]=token;	
			++cnt;
		}
		int s=msi[token];
		token=strtok(NULL,",");
		if(msi.find(token)==msi.end())
		{
			msi[token]=cnt;
			mis[cnt]=token;	
			++cnt;
		}
		int e=msi[token];
		token=strtok(NULL,",");
		string tmp=token;
		token=strtok(NULL,",");
		int dis=atoi(token);
		if(g[s][e]>dis)
		{
			roads[s][e]=roads[e][s]=tmp;
			g[s][e]=g[e][s]=dis;
		}
	}
}

void floyd_warshall()
{
	for(int k=0;k<cnt;++k)
		for(int i=0;i<cnt;++i)
			for(int j=0;j<cnt;++j)
				if(g[i][j]>g[i][k]+g[k][j])
				{
					g[i][j]=g[i][k]+g[k][j];
					flag[i][j]=k;
				}
}

void print(int s,int e)
{
	if(flag[s][e]==-1)
	{
		int i=mis[s].length();
		cout<<mis[s];
		for(;i<21;++i)
			putchar(' ');
		cout<<mis[e];
		for(i+=mis[e].length();i<42;++i)
			putchar(' ');
		cout<<roads[s][e];
		for(i+=roads[s][e].length();i<53;++i)
			putchar(' ');
		printf("%5d\n",g[s][e]);
		return ;
	}
	print(s,flag[s][e]);
	print(flag[s][e],e);
}

int main()
{
//	freopen("in.txt","r",stdin);

	init();
	input();
	floyd_warshall();
	while(gets(buf))
	{
		cout<<endl<<endl;
		char *token=strtok(buf,",");
		int s=msi[token];
		token=strtok(NULL,",");
		int e=msi[token];
		cout<<"From                 To                   Route      Miles"<<endl
			<<"-------------------- -------------------- ---------- -----"<<endl;

		print(s,e);

		cout<<"                                                     -----"<<endl;
		printf("                                          Total      %5d\n",g[s][e]);
	}

	return 0;
}

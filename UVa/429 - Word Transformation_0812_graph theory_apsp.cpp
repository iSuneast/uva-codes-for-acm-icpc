/*
429 - Word Transformation

graph theory...
apsp...
暴力算出单词的所有变形....
然后查找其变形是否存在...
存在的话就连一条边...
然后对建好的图预处理apsp...
*/

#include<iostream>
#include<string>
#include<map>
#define MAXN 203
#define INF 0x3f3f3f3f
using namespace std;

int g[MAXN][MAXN],n;
map<string,int> msi;
char dic[MAXN][13],buf[30],a[13],b[13];

void floyd()
{
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

void init()
{
	memset(g,0x3f,sizeof(g));
	for(int i=0;i<n;++i)
	{
		for(int l=0;dic[i][l];++l)
		{
			char t=dic[i][l];
			for(char c='a';c<='z';++c)
				if(c!=t)
				{
					dic[i][l]=c;
					if(msi.find(dic[i])!=msi.end())
						g[i][ msi[dic[i]] ]=1;
				}
				dic[i][l]=t;
		}
	}
	floyd();
}

void input()
{
	n=0;
	msi.clear();
	while(scanf("%s",dic[n]) && dic[n][0]!='*')
	{
		msi[ dic[n] ]=n;
		++n;
	}
	gets(buf);
	init();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		input();

		while(gets(buf) && buf[0])
		{
			sscanf(buf,"%s%s",a,b);
			printf("%s %s %d\n",a,b,g[ msi[a] ][ msi[b] ]);
		}

		if(dataset)
			putchar(10);
	}

	return 0;
}

/*
247 - Calling Circles

graph theory...
apsp...
有向图的传递闭包...
其实可以认为是求scc...
把scc里面的所有元素输出就是解
*/

#include<iostream>
#include<map>
#define MAXN 28
using namespace std;

int n,m;
bool g[MAXN][MAXN];
string dic[MAXN];
bool flag[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		if(cas!=1)
			putchar(10);

		memset(g,0,sizeof(g));
		string a,b;
		map<string,int> msi;
		int u,v,tot=0;
		while(m--)
		{
			cin>>a>>b;
			if(msi.find(a)==msi.end())
			{
				dic[tot]=a;
				msi[a]=tot++;
			}

			if(msi.find(b)==msi.end())
			{
				dic[tot]=b;
				msi[b]=tot++;
			}

			g[ msi[a] ][ msi[b] ]=true;
		}

		int i,j,k;
		for(k=0;k<n;++k)
			for(i=0;i<n;++i)
				for(j=0;j<n;++j)
					if(g[i][k] && g[k][j])
						g[i][j]=true;

		printf("Calling circles for data set %d:\n",cas++);
		memset(flag,0,sizeof(flag));
		for(i=0;i<n;++i)
			if(!flag[i])
			{
				cout<<dic[i];
				flag[i]=true;
				if(g[i][i])
				{
					for(j=0;j<n;++j)
						if(g[i][j] && g[j][i] && !flag[j])
						{
							cout<<", "<<dic[j];
							flag[j]=true;
						}
				}
				cout<<endl;
			}
	}

	return 0;
}

/*
104 - Arbitrage

graph theory..
floyd-warshall...
*/

#include<iostream>
#include<stack>
#define MAXN 25
using namespace std;

double g[MAXN][MAXN][MAXN],fa[MAXN][MAXN][MAXN];

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("104.txt","w",stdout);

	int n,i,j,k,s;
	while(cin>>n)
	{
		memset(g,0,sizeof(g));
		memset(fa,0,sizeof(fa));
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				if(i==j)
					g[i][j][1]=1;
				else
					cin>>g[i][j][1];
		for(s=2;s<=n;++s)
			for(k=1;k<=n;++k)
				for(i=1;i<=n;++i)
					for(j=1;j<=n;++j)
						if(g[i][j][s]<g[i][k][s-1]*g[k][j][1])
						{
							g[i][j][s]=g[i][k][s-1]*g[k][j][1];
							fa[i][j][s]=k;
						}
		bool got=false;
		for(s=1;s<=n && !got;++s)	//是按s从小到大..
			for(i=1;i<=n && !got;++i)
				if(g[i][i][s]>1.01)
				{
					got=true;
					cout<<i<<' ';
					stack<int> si;
					si.push(fa[i][i][s]);
					while(--s>1)
						si.push(fa[i][si.top()][s]);
					while(!si.empty())
					{
						cout<<si.top()<<' ';
						si.pop();
					}
					cout<<i<<endl;
				}
		if(!got)
			cout<<"no arbitrage sequence exists"<<endl;
	}

	return 0;
}

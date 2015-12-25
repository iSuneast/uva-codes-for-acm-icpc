/*
436 - Arbitrage (II)

floyd_warshall...
好经典的算法啊...
不过这题比起104要简单好多...
*/

#include<iostream>
#include<map>
#include<string>
#define MAXN 35
#define max(a,b) ((a)>(b))?(a):(b)
using namespace std;

double g[MAXN][MAXN];
int n,m;

bool floyd_warshall()
{
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				g[i][j]=max(g[i][j],g[i][k]*g[k][j]);
	for(int i=0;i<n;++i)
		if(g[i][i]>1)
			return true;
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int cas=1;
	while(cin>>n && n)
	{
		map<string,int> msi;
		string buf,buf1;
		double cur;
		int i;
		for(i=0;i<n;++i)
		{
			cin>>buf;
			msi[buf]=i;
		}
		cin>>m;
		memset(g,0,sizeof(g));
		for(i=0;i<m;++i)
		{
			cin>>buf>>cur>>buf1;
			g[msi[buf]][msi[buf1]]=cur;
		}
		cout<<"Case "<<cas++<<": ";
		if(floyd_warshall())
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

	return 0;
}

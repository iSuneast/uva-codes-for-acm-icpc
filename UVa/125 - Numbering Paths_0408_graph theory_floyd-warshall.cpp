/*
125 - Numbering Paths

graph theory...
floyd-warshall...

算法...
用floyd求出有向图的传递闭包...
若某一个点存在环...必有g[k][k]!=0.
此时只需要删除所有与i关联的边即可...
即,判断g[i][k] && g[k][j],成立则g[i][j]=-1;
*/

#include<iostream>
#define MAXN 110
using namespace std;
int g[MAXN][MAXN],key,cas=0;

void floyd_warshall()
{
	for(int k=0;k<=key;++k)
		for(int i=0;i<=key;++i)
			for(int j=0;j<=key;++j)
				g[i][j]+=g[i][k]*g[k][j];
}

void print()
{
	cout<<"matrix for city "<<cas++<<endl;
	for(int i=0;i<=key;++i)
	{
		cout<<g[i][0];
		for(int j=1;j<=key;++j)
			cout<<' '<<g[i][j];
		cout<<endl;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("125.txt","w",stdout);

	int n,s,e,i,j,k;
	while(cin>>n)
	{
		key=0;
		memset(g,0,sizeof(g));
		while(n--)
		{
			cin>>s>>e;
			key=key>s?key:s;
			key=key>e?key:e;
			++g[s][e];
		}
		floyd_warshall();
		for(k=0;k<=key;++k)
			if(g[k][k])		//存在环...则将与带环的点连接的边置为-1
				for(i=0;i<=key;++i)
					for(j=0;j<=key;++j)
						if(g[i][k] && g[k][j])
							g[i][j]=-1;
		print();
	}

	return 0;
}

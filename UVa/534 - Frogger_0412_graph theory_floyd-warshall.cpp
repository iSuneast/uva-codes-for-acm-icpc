/*
534 - Frogger

graph theory...
floyd_warshall...
最大最小问题...
*/

#include<iostream>
#include<cmath>
#define MAXN 210
#define INF 1e9
using namespace std;

double g[MAXN][MAXN],point[2][MAXN];
int n;

double floyd_warshall()
{
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				g[i][j]=min(g[i][j],max(g[i][k],g[k][j]));
	return g[1][2];
}

int main()
{
//	freopen("in.txt","r",stdin);

	int cas=1;
	while(cin>>n && n)
	{
		int i,j;
		double dx,dy;
		for(i=1;i<=n;++i)
			cin>>point[0][i]>>point[1][i];
		memset(g,0,sizeof(g));
		for(i=1;i<=n;++i)
			for(j=1;j<i;++j)
			{
				dx=point[0][i]-point[0][j];
				dy=point[1][i]-point[1][j];
				g[i][j]=g[j][i]=sqrt(dx*dx+dy*dy);
			}
		cout<<"Scenario #"<<cas++<<endl;
		printf("Frog Distance = %.3lf\n\n",floyd_warshall());
	}

	return 0;
}

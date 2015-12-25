/*
423 - MPI Maelstrom

Dijkstra
*/

#include<iostream>
#define MAXN 110
#define INF 1e9
using namespace std;
int w[MAXN][MAXN],v[MAXN],d[MAXN];

int main()
{
//	freopen("in.txt","r",stdin);

	int n,i,j;
	cin>>n;
	char buf[10];
	memset(w,0,sizeof(w));
	memset(v,0,sizeof(v));
	d[0]=0;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			cin>>buf;
			if(buf[0]!='x')
				w[i][j]=w[j][i]=atoi(buf);
		}
		d[i]=INF;
	}
	for(i=0;i<n;i++)
	{
		int x,m=INF;
		for(j=0;j<n;j++)
			if(!v[j] && d[j]<m)
				m=d[x=j];
		v[x]=1;
		for(j=0;j<n;j++)	//ËÉ³Ú²Ù×÷
			if(w[x][j])
				d[j]=min(d[j],d[x]+w[x][j]);
	}
	for(i=j=0;i<n;i++)
		j=max(j,d[i]);
	cout<<j<<endl;

return 0;
}

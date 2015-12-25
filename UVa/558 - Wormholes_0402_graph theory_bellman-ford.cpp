/*
558 - Wormholes

bellman-ford..
又一历史上的大悲剧...
*/

#include<iostream>
#define min(a,b) ((a)<(b))?(a):(b)
#define INF 2e9
#define MAXN 2010
using namespace std;

int n,m,u[MAXN],v[MAXN],w[MAXN],d[MAXN];

bool bellman_ford()
{
	int i,k;
	d[0]=0;
	for(k=0;k<n-1;++k)
		for(i=0;i<m;++i)
			d[v[i]]=min(d[v[i]],d[u[i]]+w[i]);
	for(i=0;i<m;++i)
		if(d[v[i]]>d[u[i]]+w[i])
			return true;
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		memset(w,0,sizeof(w));
		cin>>n>>m;
		for(int i=0;i<m;++i)	//n和m弄反了...衰啊...竟然一直没有发现..
		{
			scanf("%d %d %d",&u[i],&v[i],&w[i]);
			d[i]=INF;
		}
		if(bellman_ford())
			cout<<"possible"<<endl;
		else
			cout<<"not possible"<<endl;
	}

	return 0;
}

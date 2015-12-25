/*
10072 - Bob Laptop Woolmer and Eddie Desktop Barlow

graph theory...
km...
二分图的最大权匹配...
建图貌似也没什么难度..
理解了km算法就显得很简单了...

注意说,算出了的权是要取最接近的整数...
*/

#include<iostream>
#include<cmath>
#define MAXN 103
#define INF 0x3f3f3f3f
#define eps 1e-9
using namespace std;

int n,m,data[MAXN][3],bt,bl,ar;
int w[MAXN][MAXN];
int match[MAXN],x[MAXN],y[MAXN];
bool visx[MAXN],visy[MAXN];

bool dfs(int u)
{
	visx[u]=true;
	for(int v=0;v<m;++v)
		if(!visy[v] && x[u]+y[v]==w[u][v])
		{
			visy[v]=true;
			if(match[v]==-1 || dfs(match[v]))
			{
				match[v]=u;
				return true;
			}
		}
	return false;
}

int km()
{
	memset(match,-1,sizeof(match));
	memset(y,0,sizeof(y));
	memset(x,0,sizeof(x));

	for(int i=0;i<n;++i)
	{
		x[i]=w[i][0];
		for(int j=1;j<m;++j)
			x[i]=max(x[i],w[i][j]);
	}

	for(int k=0;k<m;++k)
	{
		while(true)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(dfs(k))
				break;

			int d=INF;
			for(int i=0;i<n;++i)
				if(visx[i])
					for(int j=0;j<m;++j)
						if(!visy[j])
							d=min(d,x[i]+y[j]-w[i][j]);

			for(int i=0;i<n;++i)
				if(visx[i])
					x[i]-=d;
			for(int j=0;j<m;++j)
				if(visy[j])
					y[j]+=d;
		}
	}

	int key=0;
	for(int i=0;i<m;++i)
		key+=w[ match[i] ][i];

	return key;
}

void output()
{
	printf("Batsmen :");
	for(int i=0;i<m;++i)
		if(0<=match[i] && match[i]<bt)
			printf("%3d",i+1);

	printf("\nBowlers :");
	for(int i=0;i<m;++i)
		if(bt<=match[i] && match[i]<bt+bl)
			printf("%3d",i+1);

	printf("\nAll-rounders :");
	for(int i=0;i<m;++i)
		if(bt+bl<=match[i] && match[i]<n)
			printf("%3d",i+1);
	putchar(10);
}

int format(double t)
{
	if(t-floor(t)<=ceil(t)-t)
		return (int)t;
	else
		return (int)t+1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&m)!=EOF && m)
	{
		if(cas!=1)
			putchar(10);

		for(int i=0;i<m;++i)
			for(int j=0;j<3;++j)
				scanf("%d",&data[i][j]);
		scanf("%d%d%d",&bt,&bl,&ar);

		n=bt+bl+ar;
		memset(w,0,sizeof(w));
		for(int i=0;i<m;++i)
		{
			int j=0,var=format(0.8*data[i][0]+0.2*data[i][2]+eps);
			for(;j<bt;++j)
				w[j][i]=var;

			var=format(0.1*data[i][0]+0.7*data[i][1]+0.2*data[i][2]+eps);
			for(;j<bt+bl;++j)
				w[j][i]=var;

			var=format(0.4*data[i][0]+0.4*data[i][1]+0.2*data[i][2]+eps);
			for(;j<n;++j)
				w[j][i]=var;
		}

		printf("Team #%d\n",cas++);
		printf("Maximum Effective Score = %d\n",km());
		output();
	}

	return 0;
}

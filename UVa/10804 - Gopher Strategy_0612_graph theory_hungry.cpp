/*
10804 - Gopher Strategy

graph theory...
hungry...
二分解...
独立建图匹配...

不是对数字直接二分,而是对所有可行解二分...
先把所有的距离保存到ls[]数组,
然后对数组的下标二分即可...

为了验证建图的正确性,可以先线性求解...
然后与二分比较..
鉴于二分比较容易出错...
后面加了句while判定...

每次使用ls[]数组时要记得初始化...
*/

#include<iostream>
#include<cmath>
#include<algorithm>
#define MAXN 110
using namespace std;

struct POINT
{
	double x,y;
}gopher[MAXN],hole;

int n,m,k,tot,pnt_n;
double dis[MAXN][MAXN],ls[MAXN*MAXN];
bool g[MAXN][MAXN];
int match[MAXN];
bool flag[MAXN];

void make_graph(double bound)
{
	memset(g,0,sizeof(g));
	for(int i=0;i<tot;++i)
		for(int j=0;j<tot;++j)
			if(dis[i][j]!=-1 && dis[i][j]<=bound)
				g[i][j]=true;
}

int dfs(int u)
{
	for(int v=0;v<tot;++v)
		if(g[u][v] && !flag[v])
		{
			flag[v]=true;
			int t=match[v];
			match[v]=u;
			if(t==-1 || dfs(t))
				return 1;
			match[v]=t;
		}
	return 0;
}

int hungry()
{
	int key=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<tot;++i)
	{
		memset(flag,0,sizeof(flag));
		key+=dfs(i);
	}
	return key>>1;
}

int b_located()
{
/*
	cout<<pnt_n<<endl;
	for(int i=0;i<pnt_n;++i)
	{
		make_graph(ls[i]);
		if(hungry()>=m-k)
			return i;
	}
	return -1;
/**/
	int s=0,e=pnt_n;
	while(s<e)
	{
		int mid=(s+e)>>1;
		make_graph(ls[mid]);
		int key=hungry();
		if(key>=m-k)
			e=mid;
		else
			s=mid+1;
	}

	if(s==pnt_n)
		return -1;

	++s;
	while(s)
	{
		make_graph(ls[s-1]);
		int key=hungry();
		if(key>=m-k)
			--s;
		else
			break;
	}

	return s;
}

double dist(POINT a,POINT b)
{
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d%d%d",&m,&n,&k);
		memset(dis,-1,sizeof(dis));
		tot=n+m;
		memset(ls,0,sizeof(ls));

		for(int i=0;i<m;++i)
			scanf("%lf%lf",&gopher[i].x,&gopher[i].y);
		for(int j=0;j<n;++j)
		{
			scanf("%lf%lf",&hole.x,&hole.y);
			for(int i=0;i<m;++i)
			{
				dis[i][j+m]=dis[j+m][i]=dist(hole,gopher[i]);
				ls[i+j*m]=dis[i][j+m];
			}
		}

		sort(ls,ls+n*m);
		pnt_n=0;
		for(int i=0;i<n*m;++i)
			if(ls[pnt_n]<ls[i])
				ls[++pnt_n]=ls[i];
		++pnt_n;

		int key=b_located();

		printf("Case #%d:\n",cas);
		if(key==-1)
			puts("Too bad.");
		else
			printf("%.3lf\n",ls[key]);

		putchar('\n');
	}

	return 0;
}

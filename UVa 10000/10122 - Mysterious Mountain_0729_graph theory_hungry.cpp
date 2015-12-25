/*
10122 - Mysterious Mountain

graph theory...
hungry...
���ƥ��...
Ӧ����Ҫ�ö����Ż���...
30s,ֱ�ӱ���ö�ټ���

��Ŀ�м�������Ҫ������
@	"(x,0)(where x is an integer - 
they do not want to take time to work out an accurate place)"
��ʵҪ��ע�⵽��������Ļ�,��Ŀһ�����ѶȽ��Ͳ���

@	"then climb directly to the destination along a straight line"
������ɽ����ֱ�ߵ�,Ҳ����˵����������ĳ�����ٹ���

@	"no part of the path that he follows can be OVER the mountain"

����,����ĿҪ����...
*/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<ctime>
#define MAXN 103
#define INF 0x3f3f3f3f
#define eps 1e-9
using namespace std;

struct POINT
{
	int x,y;
}pnt[MAXN];
int n,c,w,s;
int sx[MAXN],ex[MAXN];
double g[MAXN][MAXN];

double calc(int x0,int x1,int xe,int ye)
{
	double dx1=x1-x0;
	double dx2=xe-x1;
	return sqrt(dx1*dx1+0.0)/w+sqrt(dx2*dx2+ye*ye+0.0)/c+eps;
}

int match[MAXN],tot;
double dis[MAXN*MAXN];
bool flag[MAXN],edge[MAXN][MAXN];

bool dfs(int u)
{
	for(int v=0;v<n;++v)
		if(!flag[v] && edge[u][v])
		{
			flag[v]=true;
			int t=match[v];
			match[v]=u;
			if(t==-1 || dfs(t))
				return true;
			match[v]=t;
		}
	return false;
}

bool hungry()
{
	memset(match,-1,sizeof(match));
	for(int i=0;i<n;++i)
	{
		memset(flag,0,sizeof(flag));
		if(!dfs(i))
			return false;
	}
	return true;
}

void build(double bound)
{
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(g[i][j]<eps+bound)
				edge[i][j]=true;
			else
				edge[i][j]=false;
}

double b_section()
{
	for(int i=0;i<tot;++i)
	{
		build(dis[i]);
		if(hungry())
			return dis[i];
	}
}

void rand_data();

int main()
{
#ifndef ONLINE_JUDGE
//	rand_data();return 0;
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<n+2;++i)
			scanf("%d%d",&pnt[i].x,&pnt[i].y);

		for(int i=1;i<=n;++i)
		{
			double st=pnt[0].x,ed=pnt[n+1].x;
			for(int j=0;j<i;++j)
				if(pnt[j].y<pnt[i].y)
					st=max(st,pnt[i].x-(pnt[i].x-pnt[j].x)*pnt[i].y/(pnt[i].y-pnt[j].y)+eps);

			for(int j=i+1;j<n+2;++j)
				if(pnt[j].y<pnt[i].y)
					ed=min(ed,pnt[i].x-(pnt[i].x-pnt[j].x)*pnt[i].y/(pnt[i].y-pnt[j].y)+eps);
			sx[i]=(int)ceil(st-eps),ex[i]=(int)floor(ed+eps);
		}

		memset(g,0,sizeof(g));
		tot=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d",&c,&w,&s);
			for(int j=1;j<=n;++j)
			{
				g[i][j-1]=INF;
				for(int k=sx[j];k<=ex[j];++k)
					g[i][j-1]=min(g[i][j-1],calc(s,k,pnt[j].x,pnt[j].y) );
				dis[tot++]=g[i][j-1];
			}
		}
		sort(dis,dis+tot);

		printf("%.2lf\n",b_section());
	}

	return 0;
}

void rand_data()
{
	freopen("in.txt","w",stdout);
	srand((unsigned)time(NULL));
	int dataset=10;
	while(dataset--)
	{
		int n=rand()%10+1;
		cout<<n<<endl;
		int s=0,e=rand()%20;
		cout<<s<<" 0"<<endl;
		for(int i=0;i<n;++i)
			cout<<rand()%20<<"  "<<rand()%20<<endl;
		cout<<e<<" 0"<<endl;
		while(n--)
		{
			cout<<rand()%20<<" "<<rand()%20<<" "<<rand()%20<<endl;
		}
		cout<<endl;
	}
}

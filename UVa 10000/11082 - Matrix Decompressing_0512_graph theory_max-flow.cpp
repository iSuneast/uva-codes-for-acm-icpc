/*
11082 - Matrix Decompressing

graph theory..
max-flow...
经过无数个日夜的不懈奋斗...
无数次WA的纠结后....
finally got AC : )

感觉说自己对网络流的理解进一步加深...
而且似乎是更加深刻地懂得了说整个算法的运行流程...
期间看了无数网络流的文章...
也懂了很多关于网络流的高效的算法...
也就是说...此题让我收获了很多很多...

题目意思很简单...
给出矩阵的行列的和,要我们还原矩阵...
貌似是纯数学的问题...
但是我可以想到用网络流去做可以说是一个很大的进步了...

之前的无数次WA...
开始时是拖没看清题意的福...
后来终于知道该怎么建图了...
赞一个先...

源点-->行和
列和-->汇点

图就是这么建的...
具体的...靠自己发挥了...
*/

#include<iostream>
#include<queue>
#define MAXN 900
#define MAXVAR 19	//在最后给每个格子累加1
#define INF 0x7f7f7f7f
using namespace std;

int r,c;
int cap[MAXN][MAXN],flow[MAXN][MAXN],start,end;
int next[MAXN][MAXN],cnt[MAXN],fa[MAXN],remflow[MAXN];
bool fresh[MAXN];

void link(int s,int e,int v)
{
	cap[s][e]=v;
	next[s][cnt[s]++]=e;
	next[e][cnt[e]++]=s;	//创造回流的边,而回流的边cap[][]=0
}

void make_graph()	//拆点建图...矩阵20*20则要有20*20*2+20+20+2个点
{
	memset(flow,0,sizeof(flow));
	memset(cap,0,sizeof(cap));
	memset(cnt,0,sizeof(cnt));
	start=0;
	end=r*c*2+r+c+1;
	int cur=0,t=0;
	for(int i=0;i<r;++i)
	{
		t+=cur;
		scanf("%d",&cur);
		if(i)
			cur-=t;
		int u=c*r*2+i+1;
		link(start,u,cur-c);
		for(int j=0;j<c;++j)
		{
			int v=c*2*i+j*2+1;
			link(u,v,MAXVAR);
			link(v,v+1,MAXVAR);
		}
	}
	t=cur=0;
	for(int i=0;i<c;++i)
	{
		t+=cur;
		scanf("%d",&cur);
		if(i)
			cur-=t;
		int u=c*r*2+r+i+1;
		link(u,end,cur-r);
		for(int j=0;j<r;++j)
		{
			int v=2*i+1+j*c*2;
			link(v,v+1,MAXVAR);
			link(v+1,u,MAXVAR);
		}
	}
}

int E_K()
{
	queue<int> q;
	int f=0;
	while(true)
	{
		q.push(start);
		memset(remflow,0,sizeof(remflow));
		remflow[start]=INF;
		while(!q.empty())
		{
			int u=q.front();	q.pop();
			for(int i=0;i<cnt[u];++i)
			{
				int v=next[u][i];
				if(!remflow[v])		//正负边都考虑
				{
					if(cap[u][v]>flow[u][v])
					{
						fa[v]=u;
						q.push(v);
						remflow[v]=min(remflow[u],cap[u][v]-flow[u][v]);
					}
					if(flow[v][u]>0)
					{
						remflow[v]=min(remflow[u],flow[v][u]);
						fa[v]=u;
						q.push(v);
					}
				}
			}
		}
		if(!remflow[end])
			return f;
		int cur=INF;
		for(int u=end;u!=start;u=fa[u])
			cur=min(cur,remflow[u]);
		for(int u=end;u!=start;u=fa[u])
		{
			flow[fa[u]][u]+=cur;
			flow[u][fa[u]]-=cur;
		}
		f+=cur;
	}
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
		scanf("%d%d",&r,&c);
		make_graph();
		E_K();
		printf("Matrix %d\n",cas);
		for(int i=0;i<r;++i)
		{
			for(int j=0;j<c;++j)
			{
				if(j)
					putchar(' ');
				int u=i*c*2+j*2+1;
				printf("%d",flow[u][u+1]+1);	//直接在最后的解加1就...Orz...
			}
			putchar('\n');
		}
		putchar('\n');
	}

	return 0;
}

/*
			**************************make-mat.cpp*************************
			随机生成解矩阵

#include<iostream>
#include<ctime>
#define MAXN 20
using namespace std;

int main()
{
	freopen("make-mat.txt","w",stdout);

	srand((unsigned)time(NULL));
	int cas=100;
	int mat[MAXN][MAXN];
	cout<<cas<<endl;
	while(cas--)
	{
		int a=rand()%MAXN+1;
		int b=rand()%MAXN+1;
		cout<<a<<" "<<b<<endl;
		memset(mat,0,sizeof(mat));
		for(int i=1;i<=a;++i)
		{
			for(int j=1;j<=b;++j)
				cout<<rand()%MAXN+1<<" ";
			cout<<endl;
		}
	}

	return 0;
}

*/

/*
			**************************check.cpp*************************
			将解矩阵弄成in.txt即输入文件.

//算出矩阵的行列的和
#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("my_ans.txt","r",stdin);
	freopen("chk_out.txt","w",stdout);
#endif

	int dataset;
	scanf("%d",&dataset);
	printf("%d\n",dataset);
	while(dataset--)
	{
		int r,w,mat[50][50];
		memset(mat,0,sizeof(mat));
		scanf("%d%d",&r,&w);
		printf("%d %d\n",r,w);
		for(int i=0;i<r;++i)
			for(int j=0;j<w;++j)
				scanf("%d",&mat[i][j]);
		int t=0;
		int key=0;
		for(i=0;i<r;++i)
		{
			t=0;
			for(int j=0;j<w;++j)
				t+=mat[i][j];
			key+=t;
			printf("%d ",key);
		}
		putchar('\n');
		key=0;
		for(int j=0;j<w;++j)
		{
			t=0;
			for(int i=0;i<r;++i)
				t+=mat[i][j];
			key+=t;
			printf("%d ",key);
		}
		putchar('\n');
	}
	return 0;
}
*/

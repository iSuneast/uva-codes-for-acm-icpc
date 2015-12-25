/*
11601 - Avoiding Overlaps

data struct...
2D-Segment tree...
猥琐无敌啊...

用2D线段树可以快速判断矩形是否相交...
但是由于存在很多特殊相交情况所以写起来很麻烦...
于是想到说,用暴力判断...但是暴力的话一定会超时的...
如果二者结合...
用线段树先判一次..
如果没有相交,再用暴力判断一次...
还没有相交的话,这个矩形就是合法的...

暴力方法是模拟填充...
把合法的矩形填充到矩阵里面...
O(n^2)的扫描即可,由于用线段树优化过,所以暴力实际上用到的次数不会很多...
于是.....水过去了...
*/

#include<iostream>
#include<ctime>
#define MAXN 512
using namespace std;

struct Segment
{
	int x1,x2,y1,y2;
	bool flag;
}seg[MAXN][MAXN];
const int bgn_x=-100,end_x=100,bgn_y=-100,end_y=100;
int x1,y_1,x2,y2;

void build_y(int p1,int p2,int sx,int ex,int sy,int ey)
{
	seg[p1][p2].x1=sx;	seg[p1][p2].x2=ex;
	seg[p1][p2].y1=sy;	seg[p1][p2].y2=ey;
	seg[p1][p2].flag=false;

	if(sy==ey)
		return ;
	int my=(ey+sy)>>1;
	build_y(p1,p2<<1,sx,ex,sy,my);
	build_y(p1,(p2<<1)+1,sx,ex,my+1,ey);
}

void build(int p1,int sx,int ex)
{
	build_y(p1,1,sx,ex,bgn_y,end_y);
	if(sx==ex)
		return ;
	int mx=(ex+sx)>>1;
	build(p1<<1,sx,mx);
	build((p1<<1)+1,mx+1,ex);
}

bool ok,chg;

void chk(int p1,int p2)
{
	for(int i=p1;i && ok;i/=2)
		for(int j=p2;j && ok;j/=2)
			if(seg[i][j].flag)
				ok=false;
}

void insert_y(int p1,int p2,int sy,int ey)
{
	if(sy==seg[p1][p2].y1 && ey==seg[p1][p2].y2)
	{
		if(chg)
			seg[p1][p2].flag=true;
		else
			chk(p1,p2);
		return ;
	}

	int my=(seg[p1][p2].y1+seg[p1][p2].y2)>>1;
	if(ey<=my)
		insert_y(p1,p2<<1,sy,ey);
	else if(my<sy)
		insert_y(p1,(p2<<1)+1,sy,ey);
	else
	{
		insert_y(p1,p2<<1,sy,my);
		insert_y(p1,(p2<<1)+1,my+1,ey);
	}
}

void insert(int p1,int sx,int ex)
{
	if(sx==seg[p1][1].x1 && ex==seg[p1][1].x2)
		insert_y(p1,1,y_1,y2);
	else
	{
		int mx=(seg[p1][1].x1+seg[p1][1].x2)>>1;
		if(ex<=mx)
			insert(p1<<1,sx,ex);
		else if(mx<sx)
			insert((p1<<1)+1,sx,ex);
		else
		{
			insert(p1<<1,sx,mx);
			insert((p1<<1)+1,mx+1,ex);
		}
	}
}

bool g[205][205];

bool well()
{
	for(int i=x1;i<=x2;++i)
		for(int j=y_1;j<=y2;++j)
		{
			int a=i+100,b=j+100;
			if(g[a][b])
				return false;
		}
		return true;
}

void filled()
{
	for(int i=x1;i<=x2;++i)
		for(int j=y_1;j<=y2;++j)
			g[i+100][j+100]=true;
}

void segment()
{
	int dataset,n;
	scanf("%d",&dataset);
	build(1,bgn_x,end_x);

	for(int cas=1;cas<=dataset;++cas)
	{
		for(int i=0;i<MAXN;++i)
			for(int j=0;j<MAXN;++j)
				seg[i][j].flag=false;

		scanf("%d",&n);
		int key=0;
		memset(g,0,sizeof(g));
		while(n--)
		{
			scanf("%d%d%d%d",&x1,&y_1,&x2,&y2);
			if(x1==x2 || y_1==y2)
				continue;
			ok=true;	chg=false;
			int s=(x2-x1)*(y2-y_1);
			--x2,--y2;
			insert(1,x1,x2);
			if(ok && well())
			{
				chg=true;
				insert(1,x1,x2);
				filled();
				key+=s;
			}
		}

		printf("Case %d: %d\n",cas,key);
	}
}

void random_data();
void brute();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	segment();

	return 0;
}

void random_data()
{
	freopen("in","w",stdout);
	srand((unsigned)time(NULL));

	int dataset=10;
	cout<<dataset<<endl;
	while(dataset--)
	{
		int n=rand()*rand()%20;
		cout<<n<<endl;
		while(n--)
		{
			x1=x2=0;
			while(x1==x2 || y_1==y2)
			{
				x1=rand()*rand()%19-9;
				y_1=rand()*rand()%19-9;
				x2=rand()*rand()%19-9;
				y2=rand()*rand()%19-9;
			}
			if(x1>x2)
				swap(x1,x2);
			if(y_1>y2)
				swap(y_1,y2);
			cout<<x1<<" "<<y_1<<" "<<x2<<" "<<y2<<endl;
		}
		cout<<endl;
	}
}

void brute()
{
	int dataset,n;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		memset(g,0,sizeof(g));
		scanf("%d",&n);
		int ans=0,s;
		while(n--)
		{
			scanf("%d%d%d%d",&x1,&y_1,&x2,&y2);
			s=(x2-x1)*(y2-y_1);
			--x2,--y2;
			if(well())
			{
				filled();
				ans+=s;
			}
		}
		printf("Case %d: %d\n",cas,ans);
	}
}

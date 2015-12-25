/*
11800 - Determine the Shape

geometry...
计算几何的水题...
敲起来虽然很多,但是思路清晰也还是很快的...
能过sample基本就可以ac了...

我是先判一对平行边---梯形,再判两对平行边---平行四边形
判边相等---菱形,判边垂直---矩形,两者都满足---正方形
否则就是普通四边形
*/

#include<iostream>
#define MAXN 4
using namespace std;

struct POINT
{
	long long x,y;
}pnt[MAXN];

long long dist(POINT a,POINT b)
{
	long long dx=a.x-b.x;
	long long dy=a.y-b.y;
	return dx*dx+dy*dy;
}

int parallel(POINT a,POINT b,POINT c,POINT d)
{
	long long dx1=b.x-a.x;
	long long dy1=b.y-a.y;
	long long dx2=c.x-d.x;
	long long dy2=c.y-d.y;
	return dx2*dy1==dy2*dx1;
}

bool vertical(POINT a,POINT b,POINT c)
{
	long long dx1=b.x-a.x;
	long long dy1=b.y-a.y;
	long long dx2=c.x-a.x;
	long long dy2=c.y-a.y;
	return dx1*dx2+dy1*dy2==0;
}

void Parallelogram(int a,int b,int c,int d)
{
	bool Rhombus=false;
	if(dist(pnt[a],pnt[b])==dist(pnt[a],pnt[c]))
		Rhombus=true;
	bool Rectangle=false;
	if(vertical(pnt[a],pnt[b],pnt[c]))
		Rectangle=true;

	if(Rhombus && Rectangle)
		puts("Square");
	else if(Rhombus)
		puts("Rhombus");
	else if(Rectangle)
		puts("Rectangle");
	else
		puts("Parallelogram");
}

void Trapezium(int a,int b,int c,int d)
{
	if(parallel(pnt[a],pnt[c],pnt[b],pnt[d]))
	{
		Parallelogram(a,b,c,d);
		return ;
	}
	else if(parallel(pnt[a],pnt[d],pnt[b],pnt[c]))
	{
		Parallelogram(a,b,d,c);
		return ;
	}
	puts("Trapezium");
}

void judge()
{
	for(int a=0;a<MAXN;++a)
		for(int b=0;b<MAXN;++b)
			for(int c=0;c<MAXN;++c)
				for(int d=0;d<MAXN;++d)
					if(a!=b && a!=c && a!=d
						&& b!=c && b!=d && c!=d)
					{
						if(parallel(pnt[a],pnt[b],pnt[c],pnt[d]))
						{
							Trapezium(a,b,c,d);
							return ;
						}
					}
					puts("Ordinary Quadrilateral");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	for(int cas=1;cas<=dataset;++cas)
	{
		for(int i=0;i<MAXN;++i)
			cin>>pnt[i].x>>pnt[i].y;
		cout<<"Case "<<cas<<": ";
		judge();
	}

	return 0;
}

/*
10242 - Fourth Point !!

geometry...
给定平行四边形的两条相邻边的三个点
求第四个点...
枚举即可
*/

#include<iostream>
#include<cmath>
#define eps 1e-9
using namespace std;

struct POINT
{
	double x,y;
	bool operator==(const POINT &t)const
	{
		return fabs(x-t.x)<eps && fabs(y-t.y)<eps;
	}
}pnt[4];

bool input()
{
	int cnt=0;
	while(cnt!=4 && scanf("%lf%lf",&pnt[cnt].x,&pnt[cnt].y)!=EOF)
		++cnt;
	return cnt==4;
}

void output(POINT &a,POINT &b,POINT &c)
{
	printf("%.3lf %.3lf\n",a.x+b.x-c.x,a.y+b.y-c.y);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(input())
	{
		if(pnt[0]==pnt[2])
			output(pnt[1],pnt[3],pnt[0]);
		else if(pnt[0]==pnt[3])
			output(pnt[1],pnt[2],pnt[0]);
		else if(pnt[1]==pnt[2])
			output(pnt[0],pnt[3],pnt[1]);
		else if(pnt[1]==pnt[3])
			output(pnt[0],pnt[2],pnt[1]);
	}

	return 0;
}

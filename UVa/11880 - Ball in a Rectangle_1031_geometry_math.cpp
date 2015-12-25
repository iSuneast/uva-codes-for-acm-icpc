/*
 * 11880 - Ball in a Rectangle
 *
 * Geometry...
 * it's a simple Middle School Math problem
 *
 * we can treat the ball with radius R as a point
 * run in area {(r,r) -> (L-r,W-r)}
 * so in the new area L'=L-2r, W'=W-2r
 * and also x'=x-r, y'=y-r
 *
 * the final position should be
 * Target = ( x'+v*s*cos(a) , y'+v*s*sin(a) ) = (NewX , NewY)
 *
 * relocated the Target into original area
 * it's a simple mession...
 *
 * set CountX = NewX/L' , CountY = NewY/W'
 * NewX = NewX (+/-) CountX*L'
 * if CountX is odd then CountX = L'-CountX
 * the same to CountY
 *
 * the answer is (r,r) + Target
*/

#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int L,W,x,y,r,a,v,s;
	const double pi=acos(-1.0);

	while(scanf("%d%d%d%d%d%d%d%d",&L,&W,&x,&y,&r,&a,&v,&s)!=EOF
		&& (L||W||x||y||r||a||v||s))
	{
		L-=2*r;
		W-=2*r;
		x-=r;
		y-=r;

		double ex,ey;
		ex=x+v*s*cos(a/180.0*pi);
		ey=y+v*s*sin(a/180.0*pi);

		int cnt=0;
		while(ex>L)
		{
			ex-=L;
			++cnt;
		}
		if(cnt%2)
			ex=L-ex;

		cnt=0;
		while(ex<0)
		{
			ex+=L;
			++cnt;
		}
		if(cnt%2)
			ex=L-ex;

		cnt=0;
		while(ey>W)
		{
			ey-=W;
			++cnt;
		}
		if(cnt%2)
			ey=W-ey;

		cnt=0;
		while(ey<0)
		{
			ey+=W;
			++cnt;
		}
		if(cnt%2)
			ey=W-ey;

		printf("%.2lf %.2lf\n",ex+r,ey+r);
	}

	return 0;
}


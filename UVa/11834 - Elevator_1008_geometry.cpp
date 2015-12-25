/*
11834 - Elevator

Geometry...
try to put the two cylinders in the opposite conner of elevator
then located the center coordinate of the two cylinders
if distance<=(r1+r2)^2, "S"
*/

#include<iostream>
using namespace std;

struct POINT
{
	int x,y;
}a,b;
int l,c,r1,r2;

int dist(POINT &a,POINT &b)
{
	int dx=a.x-b.x;
	int dy=a.y-b.y;
	return dx*dx+dy*dy;
}

bool chk()
{
	if(r1*2>l || r1*2>c || r2*2>l || r2*2>c)
		return false;

	a.x=a.y=r1;
	b.x=l-r2;
	b.y=c-r2;

	return dist(a,b)>=(r1+r2)*(r1+r2);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d%d%d",&l,&c,&r1,&r2)!=EOF && (l||c||r1||r2))
	{
		puts(chk()?"S":"N");
	}

	return 0;
}

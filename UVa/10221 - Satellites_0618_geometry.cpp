/*
10221 - Satellites

geometry...
当角度a>180的时候应该当做360-a来处理...
不是a-=360...
*/

#include<iostream>
#include<cmath>
#define r 6440
#define pi (2*acos(0.0))
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int s,a;
	char buf[10];
	while(scanf("%d%d%s",&s,&a,buf)!=EOF)
	{
		a%=360;
		if(a>180)
			a=360-a;

		if(buf[0]=='d')
			printf("%.6lf %.6lf\n",a/180.0*pi*(r+s),
									(r+s)*sin(a/360.0*pi)*2);
		else
			printf("%.6lf %.6lf\n",a/60.0/180.0*pi*(r+s),
								(r+s)*sin(a/60.0/360.0*pi)*2);
	}

	return 0;
}

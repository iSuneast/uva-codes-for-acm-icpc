/*
10250 - The Other Two Trees

geometry...
真的不知道这题浪费了我多少时间了...

其实就是已知正方形的对角线的两点坐标
求另外两点...
由于是几何题...
精度要求又是暴变态的...
所以...

(x1,y1) (x2,y2)
令	mx=(x1+x2)/2
	my=(y1+y2)/2
	dx=mx-x1
	dy=my-y1(不要加绝对值)
则解为
(mx-dy,my+dx)
(mx+dy,my-dx)
*/

#include<iostream>
#include<iomanip>
#include<cmath>
#define eps 1e-15
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	long double x1,y1,x2,y2;
	while(cin>>x1>>y1>>x2>>y2)
		if(fabs(x1-x2)<eps && fabs(y1-y2)<eps)
			puts("Impossible.");
		else
		{
			long double mx=(x1+x2)/2;
			long double my=(y1+y2)/2;
			long double dx=mx-x1;
			long double dy=my-y1;

			cout.precision(10);

			cout<<fixed<<showpoint<<mx-dy<<" "<<my+dx<<" "<<mx+dy<<" "<<my-dx<<endl;
		}

	return 0;
}

/*
11701 - Cantor

math...
最近UVa的数学题特别多...
求康托集...
由于精度误差,set里面的值比较大小的时候要重载算符,加精度判定
其实就是判定一个数字可不可以表示为3的分数而已
*/

#include<iostream>
#include<cmath>
#include<set>
#define eps 1e-9
using namespace std;

struct cantor
{
	double x;
	bool operator<(const cantor &t)const
	{
		if(fabs(x-t.x)<eps)
			return false;
		return x<t.x;
	}
};

bool member(double x)
{
	while(x>=1)
		x/=10.0;
	set<cantor> s;
	while(true)
	{
		cantor tmp;
		tmp.x=x-floor(x);
		if(s.find(tmp)!=s.end())
			return true;
		s.insert(tmp);
		x*=3;
		int t=floor(x);
		if(t==1)
			return false;
		x-=t;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	double x;
	while(cin>>x)
	{
		if(member(x))
			puts("MEMBER");
		else
			puts("NON-MEMBER");
	}

	return 0;
}

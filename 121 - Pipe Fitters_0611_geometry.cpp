/*
121 - Pipe Fitters

geometry..
根本就不要考虑特殊情况...
其实也没什么特殊情况...
-----------------------
O O O O O O O O O O O O
 O O O O O O O O O O O 
-----------------------
个人感觉说n或m<2.0时应该可以放更多的...
*/

#include<iostream>
#include<cmath>
#define r 0.5
using namespace std;
typedef pair<int,bool> pib;

pib calc(double n,double m)
{
	int grid=((int)n)*((int)m);
	int first=(int)n;
	int second=(int)(n-r);
	int height=(int)( (m-1)*2.0/sqrt(3.0) )+1;
	int skew=(first+second)*(height>>1);
	if(height&1)
		skew+=first;

	if(grid>skew || !first || !second)
		return make_pair(grid,false);
	else
		return make_pair(skew,true);
}
/*
pib spj(double n,double m)
{
	int grid=((int)n)*((int)m);
	if(n>m)
		swap(n,m);
	int skew=(int)( (m-1)/sqrt( -n*n+2.0*n ) )+1;
	if(grid>skew)
		return make_pair(grid,false);
	else
		return make_pair(skew,true);
}
*/
void out(pib key)
{
	printf("%d ",key.first);
	if(key.second)
		puts("skew");
	else
		puts("grid");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	double n,m;
	pib a,b;
	while(scanf("%lf%lf",&n,&m)!=EOF)
	{
		if(n<1.0 || m<1.0)
			out( make_pair(0,false) );
		else if((a=calc(n,m)).first>(b=calc(m,n)).first)
			out(a);
		else if(a.first==b.first)
		{
			if(!a.second)
				out(a);
			else
				out(b);
		}
		else
			out(b);
	}

	return 0;
}

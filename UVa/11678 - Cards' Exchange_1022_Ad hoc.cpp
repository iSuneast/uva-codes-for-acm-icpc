/*
11678 - Cards' Exchange

Ad hoc...
just calc how many elements only exist in x[] || y[]
the min of this two number is the answer
*/

#include<iostream>
#include<algorithm>
#define MAXN 10003
using namespace std;

int a,b,x[MAXN],y[MAXN];

void process(int var[MAXN],int &sz)
{
	sort(var,var+sz);
	int t=sz;
	sz=0;
	for(int i=0;i<t;++i)
		if(var[i]!=var[sz])
			var[++sz]=var[i];
	++sz;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&a,&b)!=EOF && (a||b))
	{
		for(int i=0;i<a;++i)
		{
			scanf("%d",&x[i]);
		}
		process(x,a);
		for(int i=0;i<b;++i)
		{
			scanf("%d",&y[i]);
		}
		process(y,b);

		int px=0,py=0,cntX=0,cntY=0;
		while(px<a || py<b)
		{
			if(px==a)
			{
				cntY+=b-py;
				break;
			}
			if(py==b)
			{
				cntX+=a-px;
				break;
			}
			if(x[px]==y[py])
				++px,++py;
			else if(x[px]>y[py])
			{
				++py;
				++cntY;
			}
			else
			{
				++px;
				++cntX;
			}
		}

		printf("%d\n",min(cntX,cntY));
	}

	return 0;
}

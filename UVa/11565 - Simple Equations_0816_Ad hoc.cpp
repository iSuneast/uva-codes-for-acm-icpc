/*
11565 - Simple Equations

Ad hoc...
题目没看清楚...
x,y,z是可以为负数的,并且要满足
x<y<z的关系,可以求出b的因子
枚举因子即可...
由x+y+z=a,可得
z=a-x-y.
所以枚举x,y,就可以O(1)获得z,
然后判断几个等式是否成立即可...
*/

#include<iostream>
#include<algorithm>
#define MAXN 100003
using namespace std;

int fac[MAXN],cnt,a,b,c;

void process()
{
	scanf("%d%d%d",&a,&b,&c);
	cnt=0;
	for(int i=1;i<=b;++i)
		if(b%i==0)
		{
			fac[cnt++]=i;
			fac[cnt++]=-i;
		}
	sort(fac,fac+cnt);

	for(int i=0;i<cnt;++i)
		for(int j=i+1;j<cnt;++j)
		{
			int x=fac[i],y=fac[j],z=a-x-y;
			long long var=1;
			var=var*x*y*z;
			if(z<=y || var<=0 || var!=b)
				continue;

			if(x*x+y*y+z*z==c)
			{
				printf("%d %d %d\n",x,y,z);
				return ;
			}
		}
	puts("No solution.");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
		process();

	return 0;
}

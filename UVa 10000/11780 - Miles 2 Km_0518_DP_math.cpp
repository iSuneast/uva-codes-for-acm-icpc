/*
11780 - Miles 2 Km

DP...
math...
数学题很耗脑细胞啊...

这题只要先算出fib数列
然后对i进行迭代
用upper_bound找>i的最小fib的位置p
然后枚举i前面的所有数
构造出的新的解如果比fib[b]更优的话更新就可以了
*/

#include<iostream>
#include<cmath>
#include<algorithm>
#define MAXN 1000
#define CON 1.6
using namespace std;

double p[MAXN+3],var[MAXN+3],fib[20];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	fib[0]=0;
	fib[1]=1;
	int cnt,n;
	for(cnt=2;fib[cnt-1]<=1000;++cnt)
		fib[cnt]=fib[cnt-1]+fib[cnt-2];
	for(int i=1;i<=MAXN;++i)
	{
		int pos=upper_bound(fib,fib+cnt,i)-fib;
		var[i]=fib[pos];
		double key=i*CON;
		for(int j=1;j<pos;++j)
		{
			double t=var[ (int)fib[j] ]+var[ i-(int)fib[j] ];
			if(fabs(t-key)<fabs(var[i]-key))
				var[i]=t;
		}
		p[i]=fabs(var[i]-key);
	}
	while(scanf("%d",&n)!=EOF && n)
		printf("%.2lf\n",p[n]);

	return 0;
}

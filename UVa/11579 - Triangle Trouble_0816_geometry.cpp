/*
11579 - Triangle Trouble

geometry...
greedy...
按三角形的边长排序...
从大到小取相邻的三条边求面积,取最大的即可...
*/

#include<iostream>
#include<cmath>
#include<algorithm>
#define MAXN 10003
using namespace std;

double len[MAXN];
int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%lf",&len[i]);
		sort(len,len+n);

		double s=0;
		for(int i=n-1;i>=2;--i)
			if(len[i-1]+len[i-2]>len[i])
			{
				double t=len[i]+len[i-1]+len[i-2];
				t/=2.0;
				s=max(s,sqrt(t*(t-len[i])*(t-len[i-1])*(t-len[i-2])));
			}
		printf("%.2lf\n",s);
	}

	return 0;
}

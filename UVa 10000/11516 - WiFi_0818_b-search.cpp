/*
11516 - WiFi

b-search...
二分答案,判断是否合法即可...
*/

#include<iostream>
#include<algorithm>
#define MAXN 100003
#define INF 0x3f3f3f3f
#define eps 1e-4
using namespace std;

int n,m;
double pos[MAXN];

bool chk(double r)
{
	int p=0,cnt=0;
	while(p<m)
	{
		double cur=pos[p]+r*2.0;
		++cnt;
		while(p<m && pos[p]<=cur)
			++p;
	}
	return cnt<=n;
}

double b_located()
{
	double st=0,end=INF,mid;
	while(st+eps<end)
	{
		mid=(st+end)/2.0;
		if(!chk(mid))
			st=mid+eps;
		else
			end=mid;
	}
	return st;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i)
			scanf("%lf",&pos[i]);
		sort(pos,pos+m);
		printf("%.1lf\n",b_located());
	}

	return 0;
}

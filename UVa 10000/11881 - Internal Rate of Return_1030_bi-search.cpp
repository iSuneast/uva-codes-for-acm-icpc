/*
 * 11881 - Internal Rate of Return
 *
 * Binary Search...
 *
 * there's something wrong with problem description
 * the giving format should be
 * NPV = CF0 + CF1/(1+IRR) + CF2/(1+IRR)^2 + ...
 *
 * we can devide the answer into two section (-1,0) && [0,+INF)
 * NPV's value is monotonic depend only on IRR
 * use binary search to solve it
 * and try to find IRR in the two different section independent
 */

#include<cstdio>
#include<cmath>
#include<vector>
#define MAXN 10003
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;

int cf[MAXN],n;

double process(double bgn,double end)
{
	while(fabs(bgn-end)>1e-13)
	{
		double mid=(bgn+end)/2.0;
		double NPV=cf[0],irr=1.0;
		for(int i=1;i<=n;++i)
		{
			irr*=mid;
			NPV+=cf[i]/irr;
		}

		if(fabs(NPV)<eps)
		{
			if(fabs(mid)<eps || fabs(mid-INF)<eps)
				return -1;
			else
				return mid-1.0;
		}

		else if(NPV>0)
			bgn=mid;
		else
			end=mid;
	}

	return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	vector<double> key;
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<=n;++i)
		{
			scanf("%d",&cf[i]);
		}

		key.clear();
		double t=process(eps,1);
		if(fabs(t+1)>eps)
			key.push_back(t);

		t=process(1+eps,INF);
		if(fabs(t+1)>eps)
			key.push_back(t);

		if(key.size()==2)
			puts("Too many");
		else if(!key.size())
			puts("No");
		else
			printf("%.2lf\n",key[0]);
	}

	return 0;
}


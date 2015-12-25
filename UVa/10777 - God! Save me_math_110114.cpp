/*
 * 10777 - God! Save me
 * 
 * math..
 * posTime = PI( pi * ti ) for every ti>=0
 * negTime = PI( pi * -ti ) for every ti<0
 * so the total time we spend = posTime + negTime
 * the probability we can get out is P = SUM( pi ) for every ti>=0
 * so the AverageTime we spend to get out
 * AverageTime * p = TotalTime = posTime + negTime
 * then -> AverageTime = ( posTime + negTime ) / P
 * 
 * happy coding...
 */

#include<cstdio>
#include<cmath>
#define MAXN 100
using namespace std;
const double eps=1e-4;

struct TIME
{
	double p,t;
	void init()
	{
		p=t=0;
	}
}data,pos,neg;
int n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
    	scanf("%d",&n);
    	pos.init();	neg.init();
    	for(int i=0;i<n;++i)
    	{
    		scanf("%lf%lf", &data.t, &data.p);
    		if(data.t>=0)
    		{
    			pos.t += data.t * data.p;
    			pos.p += data.p;
    		}
    		else
    		{
    			neg.t -= data.t * data.p;
    			neg.p += data.p;    			
    		}
    	}
    	
    	if(pos.p<eps)
    		printf("Case %d: God! Save me\n",cas);
    	else
       		printf("Case %d: %.2lf\n", cas, (pos.t+neg.t)/pos.p);
    }

    return 0;
}


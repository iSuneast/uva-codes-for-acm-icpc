/*
 * 11648 - Divide The Land
 * 
 * math...
 * divide and conquer...
 * a straight forward math problem...
 * try to find the format and happy coding...
 * : )
 */

#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-9;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset;
    double ab,ad,cd,bc;
    
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
    	scanf("%lf%lf%lf%lf",&ab,&cd,&ad,&bc);
    	
    	double bgn=0, end=ad;
    	double t=cd*ad/(ab-cd);
    	while(fabs(bgn-end)>eps)
    	{
    		double ae=(bgn+end)/2.0, de=ad-ae;
    		double ef=cd*(t+de)/t;
    		
    		if( (cd+ef)*de > (ef+ab)*ae )
    			bgn=ae;
    		else
    			end=ae;
    	}
    	
    	printf("Land #%d: %.6lf %.6lf\n", cas, bgn, bgn*bc/ad);
    }

    return 0;
}


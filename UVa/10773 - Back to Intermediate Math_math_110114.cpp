/*
 * 10773 - Back to Intermediate Math
 * 
 * math...
 * In fact, I think there is something with judge's data when I got WA
 * but then I see "all are nonnegative, d is positive", I know where my bug lies..
 */

#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset;
    double d,u,v;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
    	scanf("%lf%lf%lf",&d,&v,&u);
    	
    	if(u<=v || u==0 || v==0)
        	printf("Case %d: can't determine\n",cas);
    	else
        	printf("Case %d: %.3lf\n", cas, fabs( d/u*(1.0/cos( asin(v/u) ) - 1.0) ) );
    }

    return 0;
}


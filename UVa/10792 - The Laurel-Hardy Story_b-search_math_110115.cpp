/*
 * 10792 - The Laurel-Hardy Story
 * 
 * b-search...
 * 
 * according to senior math knowledge
 * 0<= h2 <= r+r-h1
 * so just b-search the answer and find in which h2, we can achieve d
 */

#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-7;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset;
	double r,d,h1;
	
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
    	scanf("%lf%lf%lf",&r,&d,&h1);
    	double bgn=0, end=r+r-h1;

    	while(fabs(bgn-end)>eps)
    	{
    		double mid=(end+bgn)/2.0;
    		double hor= sqrt( pow(r,2) - pow(r-mid,2) ) + sqrt( pow(r,2) - pow(r-h1,2) );
    		double len= sqrt( pow(hor,2) + pow(h1-mid,2) );
    		double curD= r - sqrt( pow(r,2) - pow(len/2.0,2) );
    		
    		if(curD>d)
    			end=mid;
    		else
    			bgn=mid;
    	}
    	
    	printf("Case %d: %.4lf\n", cas, bgn );
    }

    return 0;
}


/*
 * 10787 - Modular Equations
 * 
 * number theory...
 * (a+b)%m = (a-b)%m
 * (a+b)%m - (a-b)%m = (2*b)%m = 0
 * no sense with a
 * so the final answer is 
 * for every b%m==0 ++ans;
 *        b->[bmin, bmax], m->[mmin, mmax]
 * ans = ans * (amax-amin+1)
 */

#include<cstdio>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
    	int amin, amax, bmin, bmax, mmin, mmax;
    	scanf("%d%d",&amin,&amax);
    	scanf("%d%d",&bmin,&bmax);
    	scanf("%d%d",&mmin,&mmax);

    	long long key=0;
    	for(; bmin<=bmax; ++bmin)
    	{
    		for(int m=mmin; m<=mmax; ++m)
    		{
    			if((2*bmin)%m==0)
    				++key;
    		}
    	}
    	
    	printf("Case %d: %lld\n",cas,key*(amax-amin+1));
    }

    return 0;
}


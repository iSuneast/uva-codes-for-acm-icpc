/*
 * 11866 - Triangle
 *
 * math...
 * in fact...
 * the function process is a brute force solution
 *
 * x , x , {x, x+1, ..., 2*x-1} x solutions
 * x , x+1 , {x+1, x+2, ..., 2*x} x solutions
 * ...
 * x , y-1 , {y-1, y} 2 solutions
 * x , y , {y} only 1 solution
 *
 * so we can enum for i = x ->y
 *          t = y-i+1
 *          if( t>x )   ans = (t-x)*x+(1+x)*x/2
 *          else        ans = (1+t)*t/2
 *
 * but in fact, this method is so slow
 * if u know the format
 *      sum(s,e) = (s+e)*(e-s+1)/2
 *      sqrSum(n) = 1^2 + 2^2 + 3^2 + ... + n^2 = (n)*(n+1)*(2n+1)/6
 * you can try to compress above roop into a single format
 *
 * t = y-i+1>i  ==> y-i>=i ==> i<=y/2
 *
 * @ if x<=y/2      ans = sum(x,y/2)*(3/2+y)-(sqrSum(y/2)-sqrSum(x-1))*3/2;
 *                  x=y/2
 * @ ans += ( sum(1,y-x+1) +sqrSum(y-x+1) )/2
 *
 * Happy coding : )
 */

#include<cstdio>
using namespace std;

long long sqrSum(long long x)
{
    return (x)*(x+1)*(2*x+1)/6;
}

long long sum(long long s,long long e)
{
    return (s+e)*(e-s+1)/2;
}

long long process(int x,int y)
{
    long long t=y-x+1;
    if(t>x)
        return (t-x)*x+(1+x)*x/2;
    return (1+t)*t/2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    long long x,y;
    scanf("%d",&dataset);
    while(dataset--)
    {
        scanf("%lld%lld",&x,&y);
        
        long long ans=0;
        if(x<=y/2)
        {
            long long t=sum(x,y/2);
            ans=t*3/2+t*y-(sqrSum(y/2)-sqrSum(x-1))*3/2;
            x=y/2+1;
        }
        ans+=( sum(1,y-x+1) +sqrSum(y-x+1) )/2;

        printf("%lld\n",ans);
    }

    return 0;
}


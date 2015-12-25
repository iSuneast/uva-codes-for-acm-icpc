/*
 * 701 - The Archeologists' Dilemma
 *
 * math...
 *
 * according to the problem description, we can get the following format :
 * n * 10^y <= x^e < (n+1) * 1o^y
 * so
 * log(n) + y*log(10) <= e < log(n+1) + y*log(10)
 * the smallest y = n.length()+1, and the log() function is base on 2
 * so, try to calculate "e", if "e" is too large, maybe it's "no power of 2" : )
 * 
 * just do it~
 */

#include<cstdio>
#include<cmath>
#define BOUND 1000000
using namespace std;

int length(long long n)
{
    int key=0;
    for(;n;n/=10,++key) ;
    return key;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    long long n;
    const double mul=log(10.0)/log(2.0);
    double bgn,end;

    while(scanf("%lld",&n)!=EOF)
    {
        double left=log(static_cast<double>(n))/log(2.0),right=log(static_cast<double>(n+1))/log(2.0);
        for(int key=length(n)+1;;++key)
        {
            if(key==BOUND)
            {
                puts("no power of 2");
                break;
            }
            else
            {
                bgn=left+key*mul;
                end=right+key*mul;
                if(ceil(bgn)<=floor(end) && ceil(bgn)>=4)
                {
                    printf("%lld\n",static_cast<long long>( ceil(bgn) ) );
                    break;
                }
            }
        }
    }

    return 0;
}


/*
 * 10311 - Goldbach and Euler
 *
 * number theory...
 * brute force...
 *
 * sieve the prime till 10^8...
 * then O(N) scan and check for the right answer...
 *
 * if N is odd then must be N = 2 + (N-2)
 *      because, all the primes (except 2) is odd...
 *
 * and notice that
 * "always make sure that (p2-p1) is positive and minimized."
 * so N = p1 + p2 , (p1!=p2)
 */

#include<cstdio>
#include<algorithm>
#define MAXN 100000001
#define SZ 5761500
using namespace std;

bool fade[MAXN];
int prime[SZ],tot;

void init()
{
    for(int i=0;i<MAXN;++i)
        fade[i]=(i%2==0);
    fade[1]=true;   fade[2]=false;
    
    for(int i=3;i*i<MAXN;i+=2)
    {
        if(!fade[i])
            for(int j=i<<1;j<MAXN;j+=i)
                fade[j]=true;
    }

    prime[0]=2; tot=1;
    for(int i=3;i<MAXN;i+=2)
    {
        if(!fade[i])
            prime[tot++]=i;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    init();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n%2)
        {
            if(n-2>=0 && !fade[n-2])
                printf("%d is the sum of 2 and %d.\n",n,n-2);
            else
                printf("%d is not the sum of two primes!\n",n);
        }
        else
        {
            int l=lower_bound(prime,prime+tot,n>>1)-prime,t;
            if(prime[l]>=(n>>1))
                --l;
            bool bk=false;
            for(int i=l;i>=0 && !bk;--i)
            {
                t=n-prime[i];
                if(!fade[t])
                {
                    printf("%d is the sum of %d and %d.\n",n,prime[i],t);
                    bk=true;
                }
            }

            if(!bk)
                printf("%d is not the sum of two primes!\n",n);
        }
    }

    return 0;
}


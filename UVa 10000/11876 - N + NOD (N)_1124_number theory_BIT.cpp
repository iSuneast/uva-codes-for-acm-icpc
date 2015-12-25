/*
 * 11876 - N + NOD (N)
 *
 * number theory...
 * we should quick general the divisors of an integer
 *  make a prime table at first, sieve the integer into ( p1^n1 * p2^n2 * ... )
 *  the divisors' number is (n1+1) * (n2+1) * ...
 *
 * after the initialization, we should be able to statistics Ns in the rand[a,b]
 *  as fast as possible, so use binary indexed tree to handle this in O(logN) time
 */

#include<cstdio>
#define MAXN 1000001
#define PRIME_SIZE 1001
#define lowbit(n) ((n)&(-(n)))
using namespace std;

int sum[MAXN];
bool fade[PRIME_SIZE];
int prime[PRIME_SIZE],cnt;

void Eratosthenes()
{
    prime[cnt++]=2;
    for(int i=3;i<PRIME_SIZE;i+=2)
    {
        if(fade[i])
            continue;
        prime[cnt++]=i;
        for(int j=i<<1;j<PRIME_SIZE;j+=i)
            fade[j]=true;
    }
}

int s(int p)
{
    int key=0;
    for(;p;p-=lowbit(p))
        key+=sum[p];
    return key;
}

void insert(int p)
{
    for(;p<MAXN;p+=lowbit(p))
        sum[p]++;
}

int divisor(int cur)
{
    int key=1,t;
    for(int i=0;i<cnt && cur!=1;++i)
    {
        if(cur%prime[i])
            continue;
        t=1;
        while(cur%prime[i]==0)
        {
            ++t;
            cur/=prime[i];
        }
        
        key*=t;
    }

    if(cur!=1)
        key*=2;
    
    return key;
}

void init()
{
    Eratosthenes();

    int cur=1;
    while(cur<MAXN)
    {
        insert(cur);
        cur+=divisor(cur);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    init();
    int dataset,l,u;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
        scanf("%d%d",&l,&u);
        printf("Case %d: %d\n",cas,s(u)-s(l-1));
    }

    return 0;
}


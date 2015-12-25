/*
 * 897 - Anagrammatic Primes
 *
 * number theory...
 * prime...
 *
 * just sieve all the primes till 10^7 and chk whether these primes is ok
 * for each input N, use b-search to find the final answer and chk again wheter it's ok...
 * (indeed, there are only 22 numbers is suitable for the problem...)
 *
 * take notice of "larger than n and less than the next power of 10 greater than n."
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 10000001
#define SZ 664600
using namespace std;

bool fade[MAXN];
int prime[SZ],tot;
char ok[MAXN];
int key[SZ],sz;
int buf[5100];

bool isprime(int n)
{
    if(n%2==0)
        return n==2;
    return !fade[n];
}

bool chk(int n)
{
    if(ok[n]==1 || n<10)
        return true;
    else if(ok[n]==-1)
        return false;
    
    char s[10];
    sprintf(s,"%d",n);
    int l=0,p=0;
    for(;s[l];++l)
    {
        if( (((s[l]-'2')>>1)<<1)==(s[l]-'2'))
            return false;
    }

    sort(s,s+l);
    bool bk=false;
    do{
        sscanf(s,"%d",&n);
        buf[p++]=n;
        if(!isprime(n))
            bk=true;
    }while(!bk && next_permutation(s,s+l));
    
    if(bk)
    {
        for(int i=0;i<p;++i)
            ok[ buf[i] ]=-1;
        return false;
    }
    else
    {
        for(int i=0;i<p;++i)
            ok[ buf[i] ]=1;
        return true;
    }
}

void init()
{
    tot=0;  prime[tot++]=2;
    for(int i=3;i<MAXN;i+=2)
    {
        if(fade[i])
            continue;
        prime[tot++]=i;
        for(int j=i<<1;j<MAXN;j+=i)
            fade[j]=true;
    }

    sz=0;
    for(int i=0;i<tot;++i)
    {
        if(chk(prime[i]))
            key[sz++]=prime[i];
    }
}

int bad(int ans,int n)
{
    char a[10],b[10];
    sprintf(a,"%d",ans);
    sprintf(b,"%d",n);
    return (strlen(a)<=strlen(b))?ans:0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    init();
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        int p=lower_bound(key,key+sz,n)-key;
        if(key[p]==n)
            ++p;

        printf("%d\n",bad(key[p],n));
    }

    return 0;
}


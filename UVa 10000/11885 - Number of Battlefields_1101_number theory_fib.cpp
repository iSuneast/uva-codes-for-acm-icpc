/*
 * 11885 - Number of Battlefields
 *
 * number theory
 * fib
 *
 * it's a little hard to find the law by hand
 * I try the website
 * http://www.research.att.com/~njas/sequences/A060843
 * the finally format is fib[p-3]-p/2+1
 * which fib[0]=0,fib[1]=1
 */

#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll MOD=987654321;

const ll E[2][2]=
{
    1,0,
    0,1
};

const ll A[2][2]=
{
    1,1,
    1,0
};
ll D[2][2],R[2][2];

void mul(ll x[2][2],ll y[2][2])
{
    ll z[2][2];
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
        {
            z[i][j]=0;
            for(int k=0;k<2;++k)
                z[i][j]=(z[i][j]+x[i][k]*y[k][j])%MOD;
        }
    memcpy(x,z,sizeof(E));
}

void pow_mod(const ll A[2][2],int b)
{
    memcpy(D,A,sizeof(E));
    memcpy(R,E,sizeof(E));
    for(;b;b/=2)
    {
        if(b&1)
            mul(R,D);
        mul(D,D);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        if(n<8 || n%2)
            puts("0");
        else
        {
            pow_mod(A,n-3);
            printf("%lld\n", (R[0][1]-n/2+1+MOD)%MOD );
        }
    }

    return 0;
}


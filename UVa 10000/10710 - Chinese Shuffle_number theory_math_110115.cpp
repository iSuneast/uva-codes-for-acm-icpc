/*
 * 10710 - Chinese Shuffle
 * 
 * number theory...
 * if N is even, the answer is "not"
 * if N is odd, 
 *        for p <= (n-1)/2, next position is 2*p
 *        for p > (n-1)/2,  next position is ( p-(n-1)/2 )*2-1 = 2*p-n
 * so for every p, next position is ( 2*p )%n
 * we must go n-1 pace and finally go back so ( 2^(n-1) * p )%n == p
 * finally, the format is 2^(n-1) % n == 1
 * 
 * happy coding...
 */

#include<cstdio>
using namespace std;

bool ok(int n)
{
	long long key=1,mul=2;
	for(int b=n-1;b;b/=2)
	{
		if(b&1)
			key=(key*mul)%n;
		mul=(mul*mul)%n;
	}
	
	return key==1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    for(int n; scanf("%d",&n)!=EOF && n!=-1; )
    {
    	printf("%d is %sa Jimmy-number\n",n,ok(n)?"":"not ");
    }

    return 0;
}


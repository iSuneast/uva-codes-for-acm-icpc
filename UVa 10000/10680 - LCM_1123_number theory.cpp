/*
10680 - LCM

number theory...
1*2*3*...*n
if we represent number in prime factors format
we can got
2 = {(2,1)}
3 = {(3,1)}
4 = {(2,2)}
5 = {(5,1)}
6 = {(2,1)(3,1)}

so for the final answer
{(2,logN/log2), (3,logN/log3), (5,logN/log5), ...}
try to merge these all up, we can got the final result...

we know that Integer has a tail zero
if and only if Integer = Temp * 2 * 5...
so we should process (2,logN/log2) and (5,logN/log5) at first
Two = logN/log2, Five = logN/log5
TempAnswer = pow(Two>Five?2:5, Two+Five-2*min(Two,Five) )
and then process with other factors...
*/

#include<iostream>
#define MAXN 1000001
#define SZ 78500
using namespace std;

bool fade[MAXN];
int prime[SZ],sz,n;

void init()
{
	sz=0;
	for(int i=3;i<MAXN;i+=2)
	{
		if(fade[i])
			continue;
		prime[sz++]=i;
		for(int j=i+i;j<MAXN;j+=i)
			fade[j]=true;
	}
	prime[1]=3;
}

int TwoFive(int n,int p)
{
	int key=1;
	while(n>=p)
	{
		++key;
		n/=p;
	}
	return key;
}

int done(int n,int p,int mul)
{
	int key=1;
	while(n>=p)
	{
		key=(key*mul)%10;
		n/=p;
	}

	return key;
}

int process()
{
	int two=TwoFive(n,2),five=TwoFive(n,5);
	int var=(two>five?2:5),t=two+five-min(two,five)*2;
	int key=1;

	while(t--)
		key=(key*var)%10;

	for(int i=1;i<sz && prime[i]<=n;++i)
		key=(key*done(n,prime[i],prime[i]%10))%10;

	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	while(scanf("%d",&n)!=EOF && n)
	{
		printf("%d\n",process());
	}

	return 0;
}

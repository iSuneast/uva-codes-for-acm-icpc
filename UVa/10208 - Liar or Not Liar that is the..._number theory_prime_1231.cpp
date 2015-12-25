/*
10208 - Liar or Not Liar that is the...

number theory...
prime...

-------------------------------------------
O(NlogN) time to make a prime table till 10^7
-------------------------------------------
consider that: a^2 + b^2 = c^2
if a = m^2 - n^2, b= 2mn, c = m^2 + n^2
the format above is fine, so we just need to enum m,n to get "c"
we can initiate the table fine[c], like

#define MAXN 10^7
for( i:1->INF)
   if(i*i>MAXN) break
      for( j:i->INF)
	     if(i*i+j*j>MAXN) break;
		 else fine[i*i+j*j]=true
-------------------------------------------
N(N!):
factorize N (N!), into p1^n1 *... pi^ni * ....
if( ni is odd && fine[pi]=false ), "He is a liar."
otherwise, "He might be honest."
if the input is N!, just store no more than 50 pi,
and finally output
*/

#include<iostream>
#include<algorithm>
#define SQUARE 10000001
#define PRIME_SIEVE 10000001
#define PRIME_N 664600
#define BOUND 3163
using namespace std;

bool fine[SQUARE];
bool fade[PRIME_SIEVE];
int prime[PRIME_N],tot,n,prune;

void generate_square()
{
	for(int i=1;;++i)
	{
		int x=i*i;
		if(x>=SQUARE)
			break;
		for(int j=i;;++j)
		{
			int t=x+j*j;
			if(t>=SQUARE)
				break;
			fine[t]=true;
		}
	}
}

void init()
{
	generate_square();

	prime[0]=2;	tot=1;
	for(int i=3;i<BOUND;i++)
	{
		if(!fade[i])
			for(int j=i<<1;j<PRIME_SIEVE;j+=i)
				fade[j]=true;
	}

	for(int i=3;i<PRIME_SIEVE;i+=2)
	{
		if(!fade[i])
			prime[tot++]=i;
	}
	prune=upper_bound(prime,prime+tot,BOUND)-prime;
}

void output(bool yes)
{
	puts(yes?"He might be honest.":"He is a liar.");
}

int key[54],sz;

void factor()
{
	sz=0;
	for(int i=0;i<tot && prime[i]<=n && sz<50;++i)
	{
		int cnt=0,t=n;
		while(t)
		{
			t/=prime[i];
			cnt+=t;
		}
		if(cnt&1)
		{
			if(!fine[ prime[i] ])
				key[sz++]=prime[i];
		}
	}

	if(sz)
	{
		output(false);
		for(int i=0;i+1<sz;++i)
			printf("%d ",key[i]);
		printf("%d\n",key[sz-1]);
	}
	else
		output(true);
}

void general()
{
	if(fine[n])
		return output(true);

	bool fade=false;
	for(int i=0;i<prune && n!=1;++i)
	{
		if(n%prime[i])
			continue;
		int t=0;
		while(n%prime[i]==0)
		{
			++t;
			n/=prime[i];
		}
		if(t&1)
		{
			if(!fine[ prime[i] ])
				return output(false);
		}
	}

	if(n!=1 && !fine[n])
		fade=true;

	return output(!fade);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	bool first=true;
	for(char s[20];scanf("%s",s)!=EOF;first=false)
	{
		if(!first)
			putchar(10);

		int l=strlen(s);
		if(s[l-1]=='!')
		{
			s[l-1]=0;
			sscanf(s,"%d",&n);
			factor();
		}
		else
		{
			sscanf(s,"%d",&n);
			general();
		}
	}

	return 0;
}

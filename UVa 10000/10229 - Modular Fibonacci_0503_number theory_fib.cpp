/*
10229 - Modular Fibonacci

number theory...
神奇的数论...
http://www.ics.uci.edu/~dan/class/161/notes/7/Fib.html
具体什么原理我还真的不懂....
_      _  n        _           _
|  0  1  |         |  fn-2  fn-1  |
|        |     =   |              |
|_ 1  1 _|         |_ fn-1  fn   _|
*/

#include<iostream>
using namespace std;
long long n,m;

long long fib()
{
	long long i=1,j=0,k=0,h=1,t;
	while(n>0)
	{
		if(n&1)
		{
			t=j*h;
			j=i*h+j*k+t;
			i=i*k+t;
		}
		t=h*h;
		h=2*k*h+t;
		k=k*k+t;
		n=n/2;
		i%=m;
		j%=m;
		k%=m;
		h%=m;
		t%=m;
	}
	return j;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		m=1<<m;
		printf("%d\n",fib());
	}

	return 0;
}

/*
11042 - Complex, difficult and complicated

math...
(a+bi)^n
n should only be 1,2,4
(a+bi)^1 = a+bi
(a+bi)^2 = a^2 + 2abi - b^2
		 = (a^2 - b^2) + 2abi
	let a'=(a^2 - b^2) b'=2ab
	we get (a+bi)^2 = a' + b'i
there only a few function...
if b=0 , answer=1
if a=0 , answer=2
if a'=0. amswer=4
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,n,m;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&n,&m);
		if(m==0)
			puts(abs(n)<=(1<<30)?"1":"TOO COMPLICATED");
		else if(n==0)
			puts(abs(m)<=(1<<15)?"2":"TOO COMPLICATED");
		else if(abs(n)==abs(m))
			puts(abs(2*n)<=(1<<15)?"4":"TOO COMPLICATED");
		else
			puts("TOO COMPLICATED");
	}

	return 0;
}

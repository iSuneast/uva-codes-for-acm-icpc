/*
294 - Divisors

number theoryµÄÌâ...

The bounds are too large to pregenerate, so you'll have to calculate on the fly.

Iterate through all numbers i between L and U inclusive. For each number, iterate through all numbers j 
between 1 and sqrt(i) inclusive. If i % j == 0, add 2 to a running count. For all numbers, half of 
the divisors are below the square root, and half are above, so we only need to search the lower half.

If i is a perfect square, then subtract 1 from the total number of divisors, as perfect squares
have one divisor that is exactly *on* the square root, so it has no counterpart.

Output the number with the greatest number of divisors. Make sure that you print the 
smallest number in the case of ties.

I used BufferedReader and StringTokenizer to be safe, as the bounds are quite large 
(up to a billion numbers searched per case), but it only took a second to run,
 so it's probably safe to use Scanner.

http://www.questtosolve.com/browse.php?vol=2
*/

#include<iostream>
#include<cmath>
#define MAXN 
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int p,l,u,i,j,t,key,buf,dataset;
	cin>>dataset;
	while(dataset--)
	{
		cin>>l>>u;
		p=l;
		key=0;	
		for(i=l;i<=u;++i)
		{
			t=sqrt(i);
			buf=0;
			for(j=1;j<=t;++j)
				if(i%j==0)
					buf+=2;
			if(t*t==i)
				--buf;
			if(buf>key)
			{
				key=buf;
				p=i;
			}
		}
		cout<<"Between "<<l<<" and "<<u<<", "<<p
			<<" has a maximum of "<<key<<" divisors."<<endl;
	}

	return 0;
}

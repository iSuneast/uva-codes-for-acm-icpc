/*
11236 - Grocery store

brute force...

@ a+b+c+d = n
@ a*b*c*d = n
@ n<=20.0
so, we can get
@ a+b+c+d=a*b*c*d, of which a<=b<=c<=d
and then
we can calculate d by d=(a+b+c)/(a*b*c-1)

O(n^3) enum [1,2000], you will find out all solutions
*/

#include<iostream>
#define MAXN 2000
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	for(int a=1;a<=MAXN;++a)
	{
		int endB=MAXN-a;
		for(int b=a;b<=endB;++b)
		{
			if(a*b>MAXN*100)
				break;

			int endC=endB-b;
			for(int c=b;c<=endC;++c)
			{
				int t=a*b*c;
				if(t>MAXN*10000)
					break;

				if(t==1000000 || (1000000*(a+b+c))%(t-1000000) )
					continue;

				int d=(1000000*(a+b+c))/(t-1000000);
				if(d>=c && a+b+c+d<=MAXN)
					printf("%.2lf %.2lf %.2lf %.2lf\n",
					a/100.0,b/100.0,c/100.0,d/100.0);
			}
		}
	}

	return 0;
}

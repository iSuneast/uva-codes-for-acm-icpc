/*
11892 - ENimEN

game theory...
it's a fun problem...

we can easy find out the answer by a few times of try

@ if there is a pile > 1 then First will always win
for example, we got a pile A B C D ... x y z...
	which A,B,C,D... > 1 ; x,y,z... = 1

	$ First got A-1, Second have to got A - (A-1)
	$ First got B-1, Second have to got B - (B-1)
	...

	so the exact value of A,B,C,D... is of no use

	$ if OnesCount is odd
		First got D, the state for First turn to EvenOnes
	$ if OnesCount is even
		First got D-1, Second have to got D - (D-1)
		, the state for First is also EvenOnes
	$refer to the principle below

@ else if Ones is odd First will win
@ else Second will win
	this two is easy to understand
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,n,var;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		bool big=false;
		int one=0;
		while(n--)
		{
			scanf("%d",&var);
			if(var>1)
				big=true;
			else if(var==1)
				++one;
		}

		puts(big || one%2?"poopi":"piloop");
	}

	return 0;
}

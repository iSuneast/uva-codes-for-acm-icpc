/*
694 - The Collatz Sequence
*/

#include<iostream>

using namespace std;

int main()
{
	int cas=1,t;
	unsigned long a,l,num;
	while(cin>>a>>l&&(a!=-1&&l!=-1))
	{
		t=1;
		num=a;
		while(num<=l&&num!=1)
		{
			if(!(num%2))
				num/=2;
			else
				num=3*num+1;
				t++;
		}
		if(num>l)
			t--;
		printf("Case %d: A = %d, limit = %d, number of terms = %d\n",cas,a,l,t);
		cas++;
	}

return 0;
}
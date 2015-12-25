/*
543 - Goldbach's Conjecture
...
just believe in myself
...
the program won't tle...
*/

#include<iostream>
#include<cmath>

using namespace std;

int isprime(int n)
{
	int t,i;
	t=sqrt(n)+2;
	for(i=2;i<t;i++)
		if(n%i==0)
			return 0;
	return 1;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int n,i,t,flag;
	while(cin>>n&&n)
	{
		t=n/2+1;
		flag=0;
		for(i=2;i<t;i++)
			if(isprime(i)&&isprime(n-i))
			{
				cout<<n<<" = "<<i<<" + "<<n-i<<endl;
				flag=1;
				break;
			}
		if(!flag)
			cout<<"Goldbach's conjecture is wrong."<<endl;
	}

return 0;
}
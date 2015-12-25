/*
10235 - Simply Emirp
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
	char n[10],t[10];
	int l,i,a,b;
	while(gets(n))
	{
		sscanf(n,"%d",&a);
		if(isprime(a))
		{
			l=strlen(n);
			for(i=0;i<l;i++)
				t[l-i-1]=n[i];
			t[l]='\0';
			sscanf(t,"%d",&b);
			if(a!=b&&isprime(b))		//a,b is different
				cout<<n<<" is emirp."<<endl;
			else
				cout<<n<<" is prime."<<endl;
		}
		else
			cout<<n<<" is not prime."<<endl;

	}


return 0;
}
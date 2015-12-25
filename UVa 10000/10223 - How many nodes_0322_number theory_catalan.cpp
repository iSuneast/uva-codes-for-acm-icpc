/*
10223 - How many nodes ?

catalan
*/

#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	long long n;
	while(cin>>n)
	{
		if(n==1)
		{
			cout<<n<<endl;
			continue;
		}
		long long catalan=1;
		int i;
		for(i=3;catalan!=n;i++)
			catalan=catalan*(4*i-10)/(i-1);
		cout<<i-3<<endl;
	}

return 0;
}

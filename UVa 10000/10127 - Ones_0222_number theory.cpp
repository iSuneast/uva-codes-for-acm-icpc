/*
10127 - Ones
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int n;
	while(cin>>n)
	{
		int cnt=1,a=1;
		while(a%n)
		{
			a=(a*10+1)%n;
			cnt++;
		}
		cout<<cnt<<endl;
	}

return 0;
}

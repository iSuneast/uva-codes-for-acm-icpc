/*
11332 - Summing Digits

Ad hoc...
recursion...
*/

#include<iostream>
using namespace std;

int final(int n)
{
	if(n<10)
		return n;
	int key=0;
	while(n)
	{
		key+=n%10;
		n/=10;
	}
	return final(key);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n;
	while(cin>>n && n)
		cout<<final(n)<<endl;

	return 0;
}

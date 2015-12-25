/*
11384 - Help is needed for Dexter

bitset..
位运算...
只要看一下n的二进制长度就可以了...
因为所有的数字都可以表示成111...111(2进制,ans个1)
则每次每个数都减去1<<i的话,只需减ans次就可以了
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n;
	while(cin>>n)
	{
		int ans=0;
		while(n)
		{
			n/=2;
			++ans;
		}
		cout<<ans<<endl;
	}

	return 0;
}

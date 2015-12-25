/*
10165 - Stone Game

game theory...
NIM取子游戏...
异或所有数字即可...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,t,key;
	while(cin>>n && n)
	{
		cin>>key;
		while(--n)
		{
			cin>>t;
			key^=t;
		}
		cout<<(key?"Yes":"No")<<endl;
	}

	return 0;
}

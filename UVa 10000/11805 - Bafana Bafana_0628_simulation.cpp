/*
11805 - Bafana Bafana

simulation...
math...
数学题...
推一下公式,直接输出即可..
其实也是一道环状队列的模拟题...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	for(int cas=1;cas<=dataset;++cas)
	{
		int n,k,p;
		cin>>n>>k>>p;
		cout<<"Case "<<cas<<": "<<(k+n-1+p)%n+1<<endl;
	}

	return 0;
}

/*
11714 - Blind Sorting

math...
找最大至少要比较n-1
第二大比较(int)log2(n-1)
相加就是解了...

还是有
算出的解会遇到精度问题
所有要用unsigned int
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	unsigned int n;
	while(cin>>n)
		cout<<n-1+(unsigned int)(floor)(log(n-1.0)/log(2.0))<<endl;

	return 0;
}

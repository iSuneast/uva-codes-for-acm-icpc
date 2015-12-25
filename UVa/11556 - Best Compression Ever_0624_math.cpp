/*
11556 - Best Compression Ever

math...
****************
b		n
--------------
0		1
1		2
2		4
....
b		2^b
---------------
	1+2+4+...+2^b
	=2^(b+1)-1
****************
也就是说b字节可以最多表示2^(b+1)-1个文件
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	long long n,b;
	while(cin>>n>>b)
	{
		b=((long long)1<<(b+1))-1;
		if(n>b)
			puts("no");
		else
			puts("yes");
	}

	return 0;
}

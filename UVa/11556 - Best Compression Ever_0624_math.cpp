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
Ҳ����˵b�ֽڿ�������ʾ2^(b+1)-1���ļ�
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

/*
10110 - Light, more light
...
这种题目竟然也会一直TLE.....
...
*/

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	unsigned int n,key;
	while(cin>>n&&n)
	{
		key=sqrt(n);
		if(n==key*key)
			puts("yes");
		else
			puts("no");
	}

return 0;
}

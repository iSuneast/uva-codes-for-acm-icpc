/*
10110 - Light, more light
...
������Ŀ��ȻҲ��һֱTLE.....
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

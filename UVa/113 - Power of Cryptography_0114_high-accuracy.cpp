/*
113 - Power of Cryptography
*/

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double n,p;
	while(cin>>n>>p)
	{
		printf("%.0f\n",pow(p,1/n));
	}

return 0;
}
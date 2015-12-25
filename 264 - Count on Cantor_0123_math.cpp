/*
264 - Count on Cantor
...
orz.....
*/

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,k,s;
	while(cin>>n)
	{
		k=(int)floor((sqrt(8.0*n+1)-1)/2-1e-9)+1;
		s=(k+1)*k/2;
		if(k%2)
			printf("TERM %d IS %d/%d\n",n,s-n+1,k-s+n);
		else
			printf("TERM %d IS %d/%d\n",n,k-s+n,s-n+1);
	}

return 0;
}

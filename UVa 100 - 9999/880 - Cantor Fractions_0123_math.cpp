/*
880 - Cantor Fractions
...
Ϊʲô�տ�ʼʱһֱWA��.........
����û�����װ�...
*/

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int i,k;
	while(cin>>i)
	{
		k=sqrt(2.0*i)+0.5;
		if(k%2)
			i-=(k-1)/2*k;
		else
			i-=k/2*(k-1);
		
		printf("%d/%d\n",k-i+1,i);
	}

return 0;
}

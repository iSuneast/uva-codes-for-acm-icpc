/*
10931 - Parity

number theory
*/

#include<iostream>
using namespace std;

int key;
void mod(int n)
{
	if(n)
	{
		mod(n/2);
		key+=n%2;
		cout<<n%2;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	int n;
	while(cin>>n && n)
	{
		key=0;
		cout<<"The parity of ";
		mod(n);
		cout<<" is "<<key<<" (mod 2)."<<endl;
	}

return 0;
}

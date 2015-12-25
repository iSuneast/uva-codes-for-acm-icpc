/*
10469 - To Carry or not to Carry
*/

#include<iostream>
#include<bitset>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	unsigned long a,b;
	while(cin>>a>>b)
	{
		bitset<32> bit_a(a),bit_b(b),bit(0);
		for(int i=0;i<32;i++)
			if(!bit_a.test(i) || !bit_b.test(i))
				bit[i]=bit_a[i]+bit_b[i];
		cout<<bit.to_ulong()<<endl;
	}
return 0;
}

/*
991 - Safe Salutations

catalan...
*/

#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int n,i;
	bool first=true;;
	while(cin>>n)
	{
		if(first)
			first=false;
		else
			cout<<endl;
		long catalan=1;
		for(i=3;i<=n+2;i++)
			catalan=catalan*(4*i-10)/(i-1);
		cout<<catalan<<endl;
	}

return 0;
}

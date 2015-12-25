/*
382 - Perfection
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int n;
	cout<<"PERFECTION OUTPUT"<<endl;
	while(cin>>n && n)
	{
		printf("%5d  ",n);
		int key=0;
		for(int i=1;i<=n/2;i++)
			if(n%i == 0)
				key+=i;
		if(key==n)
			cout<<"PERFECT"<<endl;
		else if(key<n)
			cout<<"DEFICIENT"<<endl;
		else
			cout<<"ABUNDANT"<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;

return 0;
}

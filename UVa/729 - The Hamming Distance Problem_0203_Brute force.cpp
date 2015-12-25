/*
729 - The Hamming Distance Problem_0203_Brute force
*/

#include<iostream>

using namespace std;

int n,h;

void calc(int num)
{
	int ans[20]={0},cnt=0,p=h,i=n-1;
	do
	{
		if(ans[cnt++]=num%2)
			p--;
		num/=2;
	}while(num&&p);

	if(num||p)
		return ;

	for(;i>=0;i--)
		cout<<ans[i];
	cout<<endl;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int cas,i;
	while(cin>>cas)
		while(cas--)
		{
			cin>>n>>h;
			for(i=1;i<(1<<n);i++)
				calc(i);
			if(cas)
				cout<<endl;
		}

return 0;
}

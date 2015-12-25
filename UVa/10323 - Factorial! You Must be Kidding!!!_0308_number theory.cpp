/*
10323 - Factorial! You Must be Kidding!!!
*/

#include<iostream>
#define MAXN 14
using namespace std;

long long ans[MAXN],n;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10323.txt","w",stdout);

	ans[0]=1;
	for(int i=1;i<=MAXN;i++)
		ans[i]=ans[i-1]*i;
	while(cin>>n)
	{
		if(n>=MAXN)
			cout<<"Overflow!"<<endl;
		else if(n<0)		//��nΪ�������.���ҷֲ����й���
		{
			n=-n;
			if(n%2)
				cout<<"Overflow!"<<endl;
			else
				cout<<"Underflow!"<<endl;
		}
		else if(ans[n]<10000)
			cout<<"Underflow!"<<endl;
		else
			cout<<ans[n]<<endl;
	}

return 0;
}

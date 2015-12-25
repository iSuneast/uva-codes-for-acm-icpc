/*
10013 - Super long sums
*/

#include<iostream>
#include<string>

using namespace std;

int n,i,m,num[1000000];

int main()
{
	string s;
	cin>>n;
	while(n--)
	{
		cin>>m;getchar();
		memset(num,0,sizeof(num));
		for(i=0;i<m;i++)
			getline(cin,s),num[m-i-1]=s[0]+s[2]-2*'0';
		for(i=0;i<m;i++)
			if(num[i]/10)
				num[i+1]+=num[i]/10,num[i]%=10;
		while(!num[i])
			i--;
		for(;i>=0;i--)
			printf("%d",num[i]);
		cout<<endl;
		if(n)
			cout<<endl;
	}

return 0;
}
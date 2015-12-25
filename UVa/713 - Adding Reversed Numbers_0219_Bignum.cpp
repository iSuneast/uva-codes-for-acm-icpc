/*
713 - Adding Reversed Numbers
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	char n1[210],n2[210];
	int n,i,l,carry;
	cin>>n;
	while(n--)
	{
		memset(n1,0,sizeof(n1));
		memset(n2,0,sizeof(n2));
		cin>>n1>>n2;
		l=strlen(n1)>strlen(n2)?strlen(n1):strlen(n2);
		carry=0;
		for(i=0;i<l;i++)
		{
			n1[i]=n1[i]+n2[i]+carry;
			if(n1[i]>='0'+'0')
				n1[i]-='0'+'0';
			else
				n1[i]-='0';
			carry=n1[i]/10;
			n1[i]%=10;
		}
		i=0;
		while(!n1[i])
			i++;
		for(;i<l;i++)
			cout<<n1[i]%10;
		if(carry)
			cout<<carry;
		cout<<endl;
	}

return 0;
}

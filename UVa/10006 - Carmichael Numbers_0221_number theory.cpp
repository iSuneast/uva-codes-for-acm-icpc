/*
10006 - Carmichael Numbers
*/

#include<iostream>

using namespace std;

int num[15]={561,1105,1729,2465,2821,6601,8911,10585,15841,29341,41041,46657,52633,62745,63973};

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,flag;
	while(cin>>n && n)
	{
		flag=0;
		for(i=0;i<15;i++)
			if(n==num[i])
				flag=1;
		if(flag)
			cout<<"The number "<<n<<" is a Carmichael number."<<endl;
		else
			cout<<n<<" is normal."<<endl;
	}

return 0;
}

/*
10038 - Jolly Jumpers

∆Ÿ≤º∫π...
WA¡À3¥Œ...
*/

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int i,t,n,mat[3000],flag[3000];
	while(cin>>n)
	{
		memset(flag,0,sizeof(flag));
		for(i=0;i<n;i++)
			cin>>mat[i];
		for(i=1;i<n;i++)
		{
			t=abs(mat[i]-mat[i-1]);
			if(0<t&&t<n)
				flag[t]=1;
		}
		for(i=1;i<n;i++)
			if(!flag[i])
			{
				cout<<"Not jolly"<<endl;
				break;
			}
		if(i==n)
			cout<<"Jolly"<<endl;
	}

return 0;
}
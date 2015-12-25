/*
414 - Machined Surfaces
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n,num[14],m,res,i,j;
	string mac;
	while(cin>>n&&n)
	{
		getchar();
		memset(num,0,sizeof(num));
		m=res=0;
		for(i=0;i<n;i++)
		{
			getline(cin,mac);
			for(j=0;j<25;j++)
			{
				if(mac[j]=='X')
					num[i]++;
			}
			m=m>num[i]?m:num[i];
		}
		for(i=0;i<n;i++)
			res+=m-num[i];
		cout<<res<<endl;
	}

return 0;
}
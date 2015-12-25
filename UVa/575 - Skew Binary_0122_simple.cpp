/*
575 - Skew Binary
....
*/

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	char skew[50];
	unsigned long ans;
	int len,i;
	while(gets(skew)&&strcmp(skew,"0"))
	{
		ans=0;
		len=strlen(skew);
		for(i=0;i<len;i++)
		{
			if(skew[i]!='0')
				ans+=((2<<(len-i-1))-1)*(skew[i]-'0');
		}
		cout<<ans<<endl;
	}

return 0;
}

/*
10473 - Simple Base Conversion

sample那边的数据不是很清晰...
输出的十六进制应该是大写的字母...
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10473.txt","w",stdout);

	string str;
	while(getline(cin,str) && str[0]!='-')
	{
		int l=str.length();
		if(l>2 && str.substr(0,2)=="0x")
		{
			int ans=0;
			for(int i=2;i<l;++i)
			{
				if(isdigit(str[i]))
					ans=ans*16+str[i]-'0';
				else if(isupper(str[i]))
					ans=ans*16+str[i]-'A'+10;
				else
					ans=ans*16+str[i]-'a'+10;
			}
			cout<<ans<<endl;
		}
		else
		{
			string ans="",empty="";
			int key=atoi(str.c_str()),carry;
			do
			{
				carry=key%16;
				if(carry<10)
					ans=empty+(char)('0'+carry)+ans;
				else
					ans=empty+(char)('A'+carry-10)+ans;		//大写
				key/=16;
			}while(key);
			cout<<"0x"<<ans<<endl;
		}
	}

	return 0;
}

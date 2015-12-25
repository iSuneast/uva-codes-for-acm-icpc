/*
444 - Encoder and Decoder

string...
*/

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	string code;
	while(getline(cin,code))
	{
		int l=code.length(),i,t;
		string ans="";
		if(isdigit(code[0]))
		{
			for(i=l-1;i>=0;--i)
			{
				t=code[i]-'0';
				if(t==1)
					t=t*100+(code[i-1]-'0')*10+code[i-2]-'0',i-=2;
				else
					t=t*10+code[--i]-'0';
				ans+=(char)('\0'+t);
			}
		}
		else
		{
			char buf[5];
			int len;
			for(i=l-1;i>=0;--i)
			{
				sprintf(buf,"%d",code[i]);
				len=strlen(buf);
				for(int j=0;j<len/2;++j)
					swap(buf[j],buf[len-j-1]);
				ans+=buf;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}

/*
446 - Kibbles "n" Bits "n" Bits "n" Bits

bits.
*/

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	char buf[10];
	char table[][5]={"0000","0001","0010","0011",
					"0100","0101","0110","0111",
					"1000","1001","1010","1011",
					"1100","1101","1110","1111"};
	int n;
	cin>>n;getchar();
	while(n--)
	{
		gets(buf);
		char *token=strtok(buf," ");
		int l=strlen(token),t=0,a=0,b=0,flag=0;
		cout<<0;

		int i=3;
		while(i-- != l)
			cout<<"0000";
		while(t<l)
		{
			if(isdigit(token[t]))
			{
				token[t]=token[t]-'0';
				a+=(token[t])*(1<<((4*(l-1-t))));
				cout<<table[token[t]];
			}
			else
			{
				token[t]=token[t]-'A'+10;
				a+=(token[t])*(1<<((4*(l-1-t))));
				cout<<table[token[t]];
			}
			t++;
		}
		token=strtok(NULL," ");
		cout<<" "<<token<<" ";
		if(token[0]=='-')
			flag=1;
		token=strtok(NULL," ");
		l=strlen(token);t=0;
		cout<<0;
		i=3;
		while(i-- != l)
			cout<<"0000";

		while(t<l)
		{
			if(isdigit(token[t]))
			{
				token[t]=token[t]-'0';
				b+=(token[t])*(1<<((4*(l-1-t))));
				cout<<table[token[t]];
			}
			else
			{
				token[t]=token[t]-'A'+10;
				b+=(token[t])*(1<<((4*(l-1-t))));
				cout<<table[token[t]];
			}
			t++;
		}
		cout<<" = ";
		if(flag)
			cout<<a-b<<endl;
		else
			cout<<a+b<<endl;
	}

return 0;
}

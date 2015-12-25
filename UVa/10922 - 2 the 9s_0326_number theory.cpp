/*
10922 - 2 the 9s

number theory
*/

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	char num[1010];
	while(gets(num) && strcmp(num,"0"))
	{
		cout<<num;
		int key=0,sum;
		do 
		{
			++key;
			sum=0;
			int l=strlen(num);
			for(int i=0;i<l;++i)
				sum+=num[i]-'0';
			sprintf(num,"%d",sum);
		}while(sum>=10);
		if(sum==9)
			cout<<" is a multiple of 9 and has 9-degree "<<key<<"."<<endl;
		else
			cout<<" is not a multiple of 9."<<endl;
	}

return 0;
}

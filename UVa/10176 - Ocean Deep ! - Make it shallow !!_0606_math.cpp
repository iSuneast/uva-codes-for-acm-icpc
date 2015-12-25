/*
10176 - Ocean Deep ! - Make it shallow !!

math...
判断一个二进制数能否被整除...
数论同余方程...
*/

#include<iostream>
#define MOD 131071
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	char c;
	while((c=getchar())!=EOF)
	{
		if(c=='#')
		{
			puts("NO");
			continue;
		}
		int cur=0;
		do 
		{
			if(c=='1')
				cur=(cur*2+1)%MOD;
			else if(c=='0')
				cur=cur*2%MOD;
		}while((c=getchar())!='#' && c!=EOF);

		if(c=='#')
		{
			if(!cur)
				puts("YES");
			else
				puts("NO");
		}
	}

	return 0;
}

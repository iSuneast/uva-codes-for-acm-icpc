/*
10705 - The Fun Number System

math...
base conversion...
进制转换...
按题目说的模拟即可...
if(n%2)则flag=true;	---	当前位为1,否则为0
s=='p'	--n		(正数,向0取整)
s=='n'	++n		(负数,向0取整)
n/=2
最后看看n是否为0
否则无解...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		long long l,n;
		char s[66];
		cin>>l>>s>>n;
		bool flag[66]={0};

		for(int i=l;i;--i)
		{
			if(n%2)
			{
				flag[i]=true;
				if(s[i-1]=='p')
					--n;
				else
					++n;
			}
			n=n/2;
		}

		if(n)
			puts("Impossible");
		else
		{
			for(int i=1;i<=l;++i)
				putchar(flag[i]?'1':'0');
			putchar('\n');
		}
	}

	return 0;
}

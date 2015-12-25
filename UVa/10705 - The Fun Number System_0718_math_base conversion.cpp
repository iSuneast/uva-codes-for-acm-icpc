/*
10705 - The Fun Number System

math...
base conversion...
����ת��...
����Ŀ˵��ģ�⼴��...
if(n%2)��flag=true;	---	��ǰλΪ1,����Ϊ0
s=='p'	--n		(����,��0ȡ��)
s=='n'	++n		(����,��0ȡ��)
n/=2
��󿴿�n�Ƿ�Ϊ0
�����޽�...
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

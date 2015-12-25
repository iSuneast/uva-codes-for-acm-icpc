/*
594 - One Little, Two Little, Three Little Endians

Ad hoc...
数组一定要记得清空...

位运算
翻转的是字节不是位...
*/

#include<iostream>
#define MAXN 32
using namespace std;

int buf[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	long long n;
	while(cin>>n)
	{

		cout<<n<<" converts to ";

		bool flag=false;
		if(n<0)
		{
			flag=true;
			n=-n;
		}

		memset(buf,0,sizeof(buf));
		int p=0;
		while(n)
		{
			buf[p++]=n%2;
			n/=2;
		}

		if(flag)
		{
			for(int i=0;i<MAXN;++i)
				if(buf[i])
				{
					for(int j=i+1;j<MAXN;++j)
						buf[j]=1-buf[j];
					break;
				}
		}

		for(int i=0;i<8;++i)
		{
			swap(buf[i],buf[i+24]);
			swap(buf[i+8],buf[i+16]);
		}

		int key=0;
		for(int i=MAXN-1;i>=0;--i)
			key=key*2+buf[i];

		cout<<key<<endl;
	}

	return 0;
}

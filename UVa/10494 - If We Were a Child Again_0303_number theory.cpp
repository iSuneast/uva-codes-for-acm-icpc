/*
10494 - If We Were a Child Again
*/

#include<iostream>

using namespace std;

char a[1000000];
int ans[10000];

int main()
{
//	freopen("in.txt","r",stdin);

	long long b,carry;
	char ope;
	while(cin>>a>>ope>>b && b)
	{
		int p=0;
		if(ope=='/')
		{
			memset(ans,0,sizeof(ans));
			carry=0;
			while(a[p])
			{
				carry=(carry%b)*10+a[p]-'0';
				ans[p++]=carry/b;
			}
			int i=0;
			while(i<p && !ans[i])	//如果a==0的话.未加边界的while循环会溢出
				i++;
			if(i==p)		//这里也有个潜在的威胁,也是a==0的边界情况
				cout<<0;
			else for(;i<p;i++)
				cout<<ans[i];
			cout<<endl;
		}
		else
		{
			carry=a[0]-'0';
			while(a[++p])
				carry=(carry%b)*10+a[p]-'0';
			cout<<carry%b<<endl;
		}
	}

return 0;
}

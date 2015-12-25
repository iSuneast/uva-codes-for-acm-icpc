/*
495 - Fibonacci Freeze
...
无语。。。O__O"…
以后再犯这种错误。。。
⊙﹏⊙b。。。
*/

#include<iostream>

using namespace std;

int f[5010][1050];
int i=2,n;

void fib()
{
	int j,k,carry;
	for(;i<=n;i++)
	{
		carry=0;		//carry使用的时候忘记清空...
		j=1049;
		while(!f[i-1][j])
			j--;
		for(k=0;k<=j;k++)
		{
			f[i][k]=f[i-1][k]+f[i-2][k]+carry;
			if(f[i][k]>=10)
			{
				f[i][k]%=10;
				carry=1;
			}
			else
				carry=0;
		}
		f[i][k]=carry;
	}
	j=1049;
	while(!f[n][j])
		j--;
	do
	cout<<f[n][j];
	while(j--);
}

int main()
{//
//	freopen("in.txt","r",stdin);
//	freopen("495.txt","w",stdout);
	memset(f,0,sizeof(f));
	f[1][0]=1;
	while(cin>>n)
		if(n)
			cout<<"The Fibonacci number for "<<n<<" is ",fib(),cout<<endl;
		else
			cout<<"The Fibonacci number for "<<n<<" is "<<0<<endl;

return 0;
}

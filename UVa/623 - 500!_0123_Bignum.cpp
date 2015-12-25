/*
623 - 500!
...
我倒...
算个阶乘也要用到DP啊....
不然tle....
...
还WA一次.......
0!没考虑到....
orz....
*/

#include<iostream>

using namespace std;

int ans[1001][3000],n,i,j,carry,buf,p=2;

void calc()
{
	if(n<=p)
		return ;
	for(;p<=n;p++)
		{
			carry=0;
			for(j=0;j<3000;j++)
			{
				buf=p*ans[p-1][j]+carry;
				ans[p][j]=buf%10;
				carry=buf/10;
			}
		}

}

int main()
{
	memset(ans,0,sizeof(ans));
	ans[0][0]=ans[1][0]=1;

	while(cin>>n)
	{
		calc();
		j=2999;
		cout<<n<<'!'<<endl;
		while(!ans[n][j])
			j--;
		for(i=j;i>=0;i--)
			cout<<ans[n][i];
		cout<<endl;
	}

return 0;
}

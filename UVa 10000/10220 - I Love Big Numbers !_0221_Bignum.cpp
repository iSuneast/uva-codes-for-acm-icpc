/*
10220 - I Love Big Numbers !
*/

#include<iostream>

using namespace std;

int ans[1010][3000],key[1010],n,i,j,carry,buf,p=2;

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
				key[p]+=ans[p][j];
				carry=buf/10;
			}
		}
}

int main()
{
//	freopen("in.txt","r",stdin);

	memset(ans,0,sizeof(ans));
	memset(key,0,sizeof(key));
	ans[0][0]=ans[1][0]=1;
	while(cin>>n)
	{
		calc();
		cout<<key[n]<<endl;
	}

return 0;
}

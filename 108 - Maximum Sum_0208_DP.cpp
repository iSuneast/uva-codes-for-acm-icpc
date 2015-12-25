/*
108 - Maximum Sum
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int n,i,j,ans,mat[110][110],k,t,l,m;
	while(cin>>n)
	{
		memset(mat,0,sizeof(mat));
		ans=-128;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				cin>>mat[i][j],
				ans=ans>mat[i][j]?ans:mat[i][j],
				mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];

		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				for(k=0;k<i;k++)
					t=mat[i][j]-mat[k][j],
					ans=ans>t?ans:t;
				for(k=0;k<j;k++)
					t=mat[i][j]-mat[i][k],
					ans=ans>t?ans:t;
				for(l=1;l<i;l++)			//之前...这种情况完全没有考虑到...
					for(m=1;m<j;m++)
						t=mat[i][j]-mat[l][j]-mat[i][m]+mat[l][m],
						ans=ans>t?ans:t;
			}
		cout<<ans<<endl;
	}

return 0;
}

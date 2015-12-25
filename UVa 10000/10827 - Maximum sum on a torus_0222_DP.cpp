/*
10827 - Maximum sum on a torus
*/

#include<iostream>

using namespace std;

#define MAXN 200

int n,mat[MAXN][MAXN],mat_r[MAXN][MAXN],mat_d[MAXN][MAXN],ans;

int maximum(int a,int b)
{
	return a>b?a:b;
}

void dp_d(int start,int end)
{
	int i,j;
	for(i=1;i<=n;i++)
		mat_d[end-1][i]=mat_d[end-2][i];		
	for(i=1;i<=n;i++)
	{
		for(j=end-2;j>=start;j--)
			ans=maximum(ans,mat_d[j][i]-=mat_d[start-1][i]);
	}
}

void dp_r(int start,int end)
{
	int i,j,i2,j2;
	for(i=1;i<=n;i++)
		mat_r[i][end-1]=mat_r[i][end-2];
	for(i=1;i<=n;i++)
	{
		for(j=end-2;j>=start;j--)
			ans=maximum(ans,mat_r[i][j]-=mat_r[i][start-1]);
	}
	memset(mat_d,0,sizeof(mat_d));
	for(i=1,i2=1;i<=n;i2++,i++)
		for(j2=1,j=start;j<end;j2++,j++)
			mat_d[i2][j2]=mat_r[i][j];
	for(i=2;i<=n;i++)			//在这里写成i<end....傻×错误...
		dp_d(i,i+n);
}

void dp(int start,int end)
{
	int i,j,k;
	for(i=1;i<=n;i++)
		for(j=start;j<end;j++)
		{
			for(k=1;k<i;k++)
				ans=maximum(ans,mat[i][j]-mat[k][j]);
			for(k=start-1;k<j;k++)
				ans=maximum(ans,mat[i][j]-mat[i][k]);
		}
	memcpy(mat_d,mat,sizeof(mat_d));
	for(i=2;i<end;i++)
		dp_d(i,i+n);
	memcpy(mat_r,mat,sizeof(mat));
	for(i=2;i<end;i++)
		dp_r(i,i+n);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		memset(mat,0,sizeof(mat));
		cin>>n;
		ans=-8000;
		int i,j;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				cin>>mat[i][j];
				ans=maximum(ans,mat[i][j]);
				mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
			}
		if(ans<0)
		{
			cout<<0<<endl;
			continue;
		}
		dp(1,1+n);
		cout<<ans<<endl;
	}

return 0;
}

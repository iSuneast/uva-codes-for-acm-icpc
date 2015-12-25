/*
348 - Optimal Array Multiplication Sequence

DP超级经典之矩阵链乘.
*/

#include<iostream>
#define MAXN 15
#define INF 1e8		//INF不能太小
using namespace std;

int p[2][MAXN],flag[MAXN][MAXN],s[MAXN][MAXN];

void print(int i,int j)
{
	if(i==j)
		cout<<'A'<<i;
	else
	{
		cout<<'(';
		print(i,s[i][j]);
		cout<<" x ";
		print(s[i][j]+1,j);
		cout<<')';
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("348.txt","w",stdout);

	int n,i,j,l,k,q,cas=1;
	while(cin>>n && n)
	{
		for(i=1;i<=n;i++)
			cin>>p[0][i]>>p[1][i];

		memset(flag,0,sizeof(flag));
		for(l=2;l<=n;l++)		//chain length
			for(i=1;i<=n-l+1;i++)
			{
				j=i+l-1;
				flag[i][j]=INF;
				for(k=i;k<=j-1;k++)
				{
					q=flag[i][k]+flag[k+1][j]+p[0][i]*p[1][k]*p[1][j];
					if(q<flag[i][j])
					{
						flag[i][j]=q;
						s[i][j]=k;
					}
				}
			}
		cout<<"Case "<<cas++<<": ";
		print(1,n);
		cout<<endl;
	}

return 0;
}

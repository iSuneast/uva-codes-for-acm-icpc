/*
836 - Largest Submatrix

DP...
竟然是O(n^4)的复杂度...
*/

#include<iostream>
#include<string>
#define MAXN 30
#define max(a,b) ((a)>(b))?(a):(b)
using namespace std;

int mat[MAXN][MAXN];

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	bool first=true;
	while(dataset--)
	{
		if(first)
			first=false;
		else
			cout<<endl;
		string buf;
		int i,j=1,a,b,n=0,key=0;
		memset(mat,0,sizeof(mat));
		do
		{
			cin>>buf;
			if(!n)
				n=buf.length();
			for(i=1;i<=n;++i)
			{
				mat[j][i]=mat[j-1][i]-mat[j-1][i-1]+mat[j][i-1];
				if(buf[i-1]=='1')
					++mat[j][i];
			}
		}while(++j<=n);
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				for(a=0;a<i;++a)
					for(b=0;b<j;++b)
					{
						int v=(i-a)*(j-b);
						if(mat[i][j]+mat[a][b]==mat[i][b]+mat[a][j]+v)
							key=max(v,key);
					}
		cout<<key<<endl;
	}

	return 0;
}

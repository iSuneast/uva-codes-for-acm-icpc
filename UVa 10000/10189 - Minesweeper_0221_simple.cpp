/*
10189 - Minesweeper
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int x,y,i,j,cas=1,flag=0;
	char mat[110][110];
	while(cin>>x>>y && (x||y))
	{
		memset(mat,0,sizeof(mat));
		for(i=1;i<=x;i++)
			for(j=1;j<=y;j++)
				cin>>mat[i][j];
		if(flag)
			cout<<endl;
		flag=1;
		cout<<"Field #"<<cas++<<":"<<endl;
		for(i=1;i<=x;i++)		//从1开始计数可以很好的避免了边界检查
		{
			for(j=1;j<=y;j++)
			{
				if(mat[i][j]!='*')
				{
					if(mat[i][j-1]=='*')
						mat[i][j]++;
					if(mat[i][j+1]=='*')
						mat[i][j]++;
					if(mat[i-1][j-1]=='*')
						mat[i][j]++;
					if(mat[i-1][j+1]=='*')
						mat[i][j]++;
					if(mat[i+1][j-1]=='*')
						mat[i][j]++;
					if(mat[i+1][j+1]=='*')
						mat[i][j]++;
					if(mat[i-1][j]=='*')
						mat[i][j]++;
					if(mat[i+1][j]=='*')
						mat[i][j]++;
					cout<<mat[i][j]-'.';
				}
				else
					cout<<'*';
			}
			cout<<endl;
		}
	}

return 0;
}

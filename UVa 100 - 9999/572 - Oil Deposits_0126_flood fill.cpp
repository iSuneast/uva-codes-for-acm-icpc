/*
572 - Oil Deposits
...
UVa---Mission 2 Cleared...
...
It,s really so hard to believe....
...
But I make it...
Now...
I am waiting for this for a few days...
ans now it finally comes to me...
..
I am so grade now...
I am very exciting....
for overcoming so much of the difficult during
my winter holiday...
.....
I must go now...
returning to my hometown to celebrate the coming
spring festival...
...
I will keep moving...
Never stop....
It is my believe....
....
now ...as usual...
you will see my stater from the UVa OnlineJudge
*/

#include<iostream>

using namespace std;

char mat[110][110];

void dfs(int i,int j)
{
	if(mat[i][j]!='@')
		return ;
	mat[i][j]='*';
	dfs(i,j+1);
	dfs(i,j-1);
	dfs(i+1,j+1);
	dfs(i+1,j-1);
	dfs(i+1,j);
	dfs(i-1,j+1);
	dfs(i-1,j-1);
	dfs(i-1,j);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int m,n,cnt,i,j;
	while(cin>>m>>n&&m)
	{
		memset(mat,0,sizeof(mat));
		cnt=0;
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				cin>>mat[i][j];
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				if(mat[i][j]=='@')
					dfs(i,j),cnt++;
		cout<<cnt<<endl;
	}

return 0;
}

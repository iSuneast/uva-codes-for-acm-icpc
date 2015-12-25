/*
352 - The Seasonal War
.....
竟然给我PE....
...
晕...sample 那边有空格啊....
"Image number 1 contains 3 war eagles. "
"Image number 2 contains 6 war eagles."
*/

#include<iostream>

using namespace std;

int cnt,len;
char mat[30][30];

void dfs(int i,int j)
{
	if(i<0||j<0||i>=cnt||j>=len)
		return ;
	else if(mat[i][j]!='1')
		return ;
	mat[i][j]=0;
	dfs(i-1,j-1);	dfs(i-1,j);	dfs(i-1,j+1);
	dfs(i,j-1);					dfs(i,j+1);
	dfs(i+1,j-1);	dfs(i+1,j);	dfs(i+1,j+1);
}

int main()
{
	freopen("in.txt","r",stdin);
	int i,j,ans,cas=1;
	while(cin>>cnt)
	{
		ans=0;
		memset(mat,0,sizeof(mat));
		for(i=0;i<cnt;i++)
			cin>>mat[i];
		len=strlen(mat[0]);
		for(i=0;i<cnt;i++)
			for(j=0;j<len;j++)
				if(mat[i][j]=='1')
					dfs(i,j),ans++;
			cout<<"Image number "<<cas++<<" contains "<<ans<<" war eagles."<<endl;
	}

return 0;
}

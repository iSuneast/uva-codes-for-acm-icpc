/*
469 - Wetlands of Florida

dfs
flood fill
*/

#include<iostream>
#include<cctype>

using namespace std;

char mat[110][110];
int flag[110][110],ans,cnt,len;

void dfs(int i,int j)
{
	if(i<0||j<0||i>=cnt||j>=len)
		return ;
	else if(flag[i][j]||mat[i][j]!='W')
		return ;
	flag[i][j]=1;
	ans++;
	dfs(i-1,j-1);	dfs(i-1,j);	dfs(i-1,j+1);
	dfs(i,j-1);					dfs(i,j+1);
	dfs(i+1,j-1);	dfs(i+1,j);	dfs(i+1,j+1);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int cas,i,j;
	cin>>cas;getchar();getchar();
	while(cas--)
	{
		memset(mat,0,sizeof(mat));
		memset(flag,0,sizeof(flag));
		cnt=0;
		while(gets(mat[cnt]))
			if(!isalpha(mat[cnt][0]))
				break;
			else
				cnt++;

		len=strlen(mat[0]);
		do
		{
			ans=0;
			sscanf(mat[cnt],"%d %d",&i,&j);
			memset(flag,0,sizeof(flag));
			dfs(i-1,j-1);
			cout<<ans<<endl;
		}while(gets(mat[cnt])&&mat[cnt][0]);
		if(cas)
			cout<<endl;
	}

return 0;
}

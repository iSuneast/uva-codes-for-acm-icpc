/*
705 - Slash Maze
*/

#include<iostream>
#include<algorithm>

using namespace std;

int w,h,mat[250][250],cycles[10000],cnt,flag,len;
int table[2][9]={
		{1,0,0,0,1,0,0,0,1},
		{0,0,1,0,1,0,1,0,0}};

void make(int i,int j,char c)
{
	int a,b,t=0,k;
	i=3*i-2;
	j=3*j-2;
	k=0;
	if(c=='/')
		t=1;
	for(a=i;a<i+3;a++)
		for(b=j;b<j+3;b++)
			mat[a][b]=table[t][k++];
}

void dfs(int i,int j)
{
	if(mat[i][j]==-1)
	{
		flag=1;
		return ;
	}
	else if(mat[i][j]==1)
		return ;
	mat[i][j]=1,len++;
	dfs(i+1,j);
	dfs(i-1,j);
	dfs(i,j+1);
	dfs(i,j-1);
}

int cmp(const int a,const int b)
{
	return a<b;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,cas=1;
	char c;
	while(cin>>w>>h&&(w||h))
	{
		memset(mat,-1,sizeof(mat));
		cnt=0;
		for(i=1;i<=h;i++)
			for(j=1;j<=w;j++)
				cin>>c,make(i,j,c);
		for(i=1;i<=3*h;i++)
			for(j=1;j<=3*w;j++)
				if(!mat[i][j])
				{
					flag=len=0,dfs(i,j);
					if(!flag)
						cycles[cnt++]=len;
				}
		sort(cycles,cycles+cnt,cmp);
		cout<<"Maze #"<<cas++<<':'<<endl;
		if(cnt)
			cout<<cnt<<" Cycles; the longest has length "<<cycles[cnt-1]/3<<'.'<<endl<<endl;
		else
			cout<<"There are no cycles."<<endl<<endl;
	}

return 0;
}

/*
164 - String Computer

dp...
edit step
编辑距离...
要输出方案,所以会显得麻烦点...
可以参考http://en.wikipedia.org/wiki/Levenshtein_distance
*/

#include<iostream>
#define MAXN 25
using namespace std;

char a[MAXN],b[MAXN];
int dp[MAXN][MAXN],fa[MAXN][MAXN];
int la,lb,d;

void print(int i,int j)
{
	if(!i || !j)
	{
		if(i)
			for(int k=1;k<=i;++k)
				printf("D%c%02d",a[k],k-d),++d;
		if(j)
			for(int k=1;k<=j;++k)
				printf("I%c%02d",b[k],k),--d;
		return ;
	}
	else if(fa[i][j]==0)
	{
		print(i-1,j-1);
		if(dp[i][j]==dp[i-1][j-1]+1)
			printf("C%c%02d",b[j],j);
	}
	else if(fa[i][j]==1)
	{
		print(i-1,j);
		printf("D%c%02d",a[i],i-d),++d;
	}
	else if(fa[i][j]==2)
	{
		print(i,j-1);
		printf("I%c%02d",b[j],j),--d;
	}
}

void edit_step(char *a,char *b)
{
	la=strlen(a),lb=strlen(b);
	memset(dp,0,sizeof(dp));
	for(int i=0;i<la;++i)	//delete
		dp[i][0]=i;
	for(int j=0;j<lb;++j)	//insert
		dp[0][j]=j;

	for(int j=1;j<lb;++j)
	{
		for(int i=1;i<la;++i)
			if(a[i]==b[j])
			{
				dp[i][j]=dp[i-1][j-1];
				fa[i][j]=0;
			}
			else if(dp[i-1][j-1]<dp[i-1][j] && dp[i-1][j-1]<dp[i][j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;	//change
				fa[i][j]=0;
			}
			else if(dp[i][j-1]<dp[i-1][j])
			{
				dp[i][j]=dp[i][j-1]+1;		//insert
				fa[i][j]=2;
			}
			else
			{
				dp[i][j]=dp[i-1][j]+1;		//delete
				fa[i][j]=1;
			}
	}
	d=0;		//计算,增删字母后的偏移量
	print(la-1,lb-1);
	puts("E");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	a[0]=b[0]='X';
	while(scanf("%s%s",a+1,b+1)!=EOF && strcmp(a,"X#"))
		edit_step(a,b);

	return 0;
}

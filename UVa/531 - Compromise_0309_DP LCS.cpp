/*
531 - Compromise
*/

#include<iostream>
using namespace std;

char dic1[110][35],dic2[110][35];
int cnt1=1,cnt2=1,flag[110][110],fa[110][110];
bool first;

void print(int i,int j)
{
	if(!i || !j)
		return ;
	else if(fa[i][j]==0)
	{
		print(i-1,j-1);
		if(first)
			first=false;
		else
			cout<<' ';
		cout<<dic1[i];
	}
	else if(fa[i][j]==1)
		print(i-1,j);
	else
		print(i,j-1);
}

int main()
{
//	freopen("in.txt","r",stdin);
	while(cin>>dic1[cnt1])
	{
		if(dic1[cnt1++][0]!='#')
			while(cin>>dic1[cnt1] && dic1[cnt1][0]!='#')
				cnt1++;
		while(cin>>dic2[cnt2] && dic2[cnt2][0]!='#')
			cnt2++;
		memset(flag,0,sizeof(flag));
		memset(fa,0,sizeof(fa));
		int i,j;
		for(i=1;i<cnt1;i++)		//用递推的LCS效率比递归的LCS高,而且便于打印解.
			for(j=1;j<cnt2;j++)
				if(!strcmp(dic1[i],dic2[j]))
				{
					flag[i][j]=flag[i-1][j-1]+1;
					fa[i][j]=0;
				}
				else if(flag[i-1][j]>=flag[i][j-1])
				{
					flag[i][j]=flag[i-1][j];
					fa[i][j]=1;
				}
				else
				{
					flag[i][j]=flag[i][j-1];
					fa[i][j]=2;
				}
		first=true;
		print(cnt1-1,cnt2-1);
		cout<<endl;
		cnt1=cnt2=1;
	}

return 0;
}

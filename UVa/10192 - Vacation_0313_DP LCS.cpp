/*
10192 - Vacation

¾­µäµÄLCS...
*/

#include<iostream>
#define MAXN 110
using namespace std;

char city1[MAXN],city2[MAXN],flag[MAXN][MAXN];
int main()
{
//	freopen("in.txt","r",stdin);

	int cas=1,l1,l2;
	while(gets(city1) && city1[0]!='#')
	{
		gets(city2);
		l1=strlen(city1);
		l2=strlen(city2);
		memset(flag,0,sizeof(flag));
		for(int i=0;i<l1;i++)
			for(int j=0;j<l2;j++)
				if(city1[i]==city2[j])
					flag[i+1][j+1]=flag[i][j]+1;
				else if(flag[i][j+1]>flag[i+1][j])
					flag[i+1][j+1]=flag[i][j+1];
				else
					flag[i+1][j+1]=flag[i+1][j];
				cout<<"Case #"<<cas++<<": you can visit at most "<<(int)flag[l1][l2]<<" cities."<<endl;
	}

return 0;
}

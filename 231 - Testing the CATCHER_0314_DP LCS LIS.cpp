/*
231 - Testing the CATCHER

��һ�γ��Զ�ά��LCS...
ʵ�������鷳һ��,����������һ����...
����,
ǧ��Ҫע��һ��һά�±��Ƿ����.
*/

#include<iostream>
#include<algorithm>
#define MAXN 32770
using namespace std;
int num1[MAXN],num2[MAXN],flag[2][MAXN];

int cmp(const int a,const int b)
{
	return a>b;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int i,j,cnt,cas=1;
	bool first=true;
	while(1)
	{
		cnt=1;
		while(cin>>num1[cnt] && num1[cnt]!=-1)
			cnt++;
		if(cnt==1)
			break;
		if(first)
			first=false;
		else
			cout<<endl;
		memcpy(num2+1,num1+1,sizeof(int)*cnt);
		sort(num2+1,num2+cnt,cmp);	//�������LCS.
		memset(flag,0,sizeof(flag));
		for(i=1;i<cnt;i++)
			for(j=1;j<cnt;j++)
			{
				if(num1[i]==num2[j])
					flag[i%2][j]=flag[(i+1)%2][j-1]+1;
				else if(flag[(i+1)%2][j]>=flag[i%2][j-1])
					flag[i%2][j]=flag[(i+1)%2][j];
				else
					flag[i%2][j]=flag[i%2][j-1];
			}
			cout<<"Test #"<<cas++<<":"<<endl
				<<"  maximum possible interceptions: "
				<<flag[(cnt+1)%2][cnt-1]<<endl;
	}

return 0;
}

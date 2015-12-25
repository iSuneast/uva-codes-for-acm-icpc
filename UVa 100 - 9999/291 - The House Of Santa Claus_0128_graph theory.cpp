/*
291 - The House Of Santa Claus
...
欧拉回路....
原来如此....
*/

#include<iostream>

using namespace std;

int flag[10][10];
int ans[10]={1};

void euler(int u,int cur)		//cur当前位置...
{
	int i;					//i不能弄成全局变量
	if(cur==9)
	{
		for(i=0;i<9;i++)
			cout<<ans[i];
		cout<<endl;
		return ;
	}
	for(i=1;i<6;i++)
		if(flag[u][i])
		{
			ans[cur]=i;
			flag[u][i]=flag[i][u]=0;
			euler(i,cur+1);
			flag[u][i]=flag[i][u]=1;	//一定记得改回标记
		}
}

int main()
{
	memset(flag,0,sizeof(flag));		//初始化图
	flag[1][2]=flag[1][3]=flag[1][5]=1;
	flag[2][1]=flag[2][3]=flag[2][5]=1;
	flag[3][2]=flag[3][1]=flag[3][4]=flag[3][5]=1;
	flag[4][3]=flag[4][5]=1;
	flag[5][2]=flag[5][1]=flag[5][3]=flag[5][4]=1;
	euler(1,1);

return 0;
}

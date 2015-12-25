/*
10400 - Game Show Math
*/

#include<iostream>

using namespace std;

char opera[]={'+','-','*','/'};
int num[110],ans[110],p,key;
bool flag[65000][110];				//加入flag...记忆化搜索

int dfs(int t,int cur,int o)
{
	if(t>=32000 || t<=-32000 || flag[t+32500][cur])
		return 0;
	flag[t+32500][cur]=true;
	ans[cur-1]=o;
	if(cur==p)
	{
		if(t==key)
			return 1;
		return 0;
	}
	else if(dfs(t+num[cur],cur+1,0)	||
			dfs(t-num[cur],cur+1,1) ||
			dfs(t*num[cur],cur+1,2)	||
			(num[cur] && t%num[cur]==0 && dfs(t/num[cur],cur+1,3) ) )
			return 1;
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int cas,i;
	cin>>cas;
	while(cas--)
	{
		memset(flag,0,sizeof(flag));
		cin>>p;
		for(i=0;i<p;i++)
			cin>>num[i];
		cin>>key;
		if(!dfs(num[0],1,0))
			cout<<"NO EXPRESSION"<<endl;
		else
		{
			cout<<num[0];
			for(i=1;i<p;i++)
				cout<<opera[ans[i]]<<num[i];
			cout<<'='<<key<<endl;
		}
	}

return 0;
}

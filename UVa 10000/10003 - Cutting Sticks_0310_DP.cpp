/*
10003 - Cutting Sticks
*/

#include<iostream>
#define MAXN 60
using namespace std;
int l,n,flag[MAXN][MAXN],s[MAXN];
int dp(int p1,int p2)		//经典的DP模型
{
	if(p2-p1<=1)
		return 0;
	else if(flag[p1][p2])
		return flag[p1][p2];
	else for(int i=p1+1;i<p2;i++)
	{
		int t=dp(p1,i)+dp(i,p2);
		if(!flag[p1][p2])
			flag[p1][p2]=t;
		else if(flag[p1][p2]>t)
			flag[p1][p2]=t;
	}
	return flag[p1][p2]+=s[p2]-s[p1];
}
int main()
{
//	freopen("in.txt","r",stdin);
	while(cin>>l && l)
	{
		cin>>n;
		s[0]=0;
		for(int i=1;i<=n;i++)
			cin>>s[i];
		if(s[n]!=l)
			s[++n]=l;
		memset(flag,0,sizeof(flag));
		cout<<"The minimum cutting is "<<dp(0,n)<<"."<<endl;
	}

return 0;
}

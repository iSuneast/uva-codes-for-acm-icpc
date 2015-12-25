/*
10066 - The Twin Towers
*/

#include<iostream>
using namespace std;
int n,m,n1[110],n2[110],flag[110][110],cas=1;

int dp(int p1,int p2)
{
	if(p1>=n || p2>=m)
		return 0;
	else if(flag[p1][p2])
		return flag[p1][p2];
	else for(int i=p1;i<n;i++)
		for(int j=p2;j<m;j++)
			if(n1[i]==n2[j])
			{
				int t=dp(i+1,j+1)+1;	//晕,看清楚了,这里是p1,p2,不是i,j
				flag[p1][p2]=flag[p1][p2]>t?flag[p1][p2]:t;
			}
	return flag[p1][p2];
}
int main()
{
//	freopen("in.txt","r",stdin);

	while(cin>>n>>m && (n||m))
	{
		int i;
		for(i=0;i<n;i++)
			cin>>n1[i];
		for(i=0;i<m;i++)
			cin>>n2[i];
		memset(flag,0,sizeof(flag));
		cout<<"Twin Towers #"<<cas++<<endl;
		cout<<"Number of Tiles : "<<dp(0,0)<<endl<<endl;
	}

return 0;
}

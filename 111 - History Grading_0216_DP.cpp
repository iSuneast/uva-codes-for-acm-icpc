/*
111 - History Grading
*/

#include<iostream>

using namespace std;

int n,ran[25],key[25],d[25];

int dp(int cur,int k)
{
	if(cur>=n || k>=n)
		return 0;
	if(d[cur])
		return d[cur];
	for(int i=cur;i<n;i++)
		for(int j=k;j<n;j++)
			if(ran[i]==key[j])
			{
				int max=dp(i+1,j+1)+1;
				d[cur]=d[cur]>max?d[cur]:max;
			}
	return d[cur];
}

int main()
{
//	freopen("in.txt","r",stdin);

	int i,t;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>t,key[t-1]=i;
	while(cin>>t)
	{
		ran[t-1]=0;
		for(i=1;i<n;i++)
			cin>>t,ran[t-1]=i;
		memset(d,0,sizeof(d));
		dp(0,0);
		cout<<d[0]<<endl;
	}

return 0;
}

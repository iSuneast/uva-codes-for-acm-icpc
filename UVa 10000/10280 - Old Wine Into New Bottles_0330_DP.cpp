/*
10280 - Old Wine Into New Bottles

DP...
*/

#include<iostream>
#define max(a,b) ((a)>(b))?(a):(b)
#define MAXN 110
#define MAXSZ 4510
#define MAXSTATE 5000000
using namespace std;

int cap[2][MAXN],dp[MAXSTATE],flag[MAXSZ];

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int v,n,i,j;
		cin>>v>>n;
		v*=1000;
		bool got=false;
		memset(flag,0,sizeof(flag));
		for(i=0;i<n;++i)
		{
			cin>>cap[0][i]>>cap[1][i];
			for(j=cap[0][i];j<=cap[1][i];++j)
				flag[j]=1;
			if((v/cap[0][i])*(cap[1][i]-cap[0][i])>=v%cap[0][i])
				got=true;
		}
		if(got)
			cout<<0<<endl;
		else
		{
			memset(dp,0,sizeof(dp));
			for(i=MAXSZ;i;--i)
				if(flag[i])
					for(j=0;j<=v;++j)
						if(j>=i)
							dp[j]=max(dp[j],dp[j-i]+i);
			cout<<v-dp[v]<<endl;
		}
		if(dataset)
			cout<<endl;
	}

	return 0;
}

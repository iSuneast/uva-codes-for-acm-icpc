/*
674 - Coin Change
*/

#include<iostream>

using namespace std;

int coin[7500],p=1;
int v[]={1,5,10,25,50};

void dp()
{
	memset(coin,0,sizeof(coin));
	coin[0]=1;
	for(int i=0;i<5;i++)
		for(int j=v[i];j<7500;j++)
			coin[j]+=coin[j-v[i]];
}

int main()
{
//	freopen("in.txt","r",stdin);
	dp();
	int n;
	while(cin>>n)
		cout<<coin[n]<<endl;

return 0;
}

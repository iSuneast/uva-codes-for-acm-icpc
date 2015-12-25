/*
357 - Let Me Count The Ways
*/

#include<iostream>
#define MAXN 30010
#define COINS 5
using namespace std;

long long key[MAXN];		//晕,竟然会溢出...
int coin[COINS]={1,5,10,25,50};
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("357.txt","w",stdout);

	int i,j,n;
	memset(key,0,sizeof(key));
	key[0]=1;
	for(i=0;i<COINS;i++)		//把能表示的全部表示了.
		for(j=coin[i];j<MAXN;j++)
				key[j]+=key[j-coin[i]];
	while(cin>>n)
		if(key[n]==1)
			cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
		else
			cout<<"There are "<<key[n]<<" ways to produce "<<n<<" cents change."<<endl;

return 0;
}

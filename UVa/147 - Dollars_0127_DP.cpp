/*
147 - Dollars
*/

#include<iostream>
#include<cmath>

using namespace std;

long key[30010];

void init()
{
	memset(key,0,sizeof(key));
	int dollar[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
	int i,j;
	key[0]=1;
	for(i=0;i<11;i++)
		for(j=dollar[i];j<30001;j++)
			key[j]+=key[j-dollar[i]];
}

int main()
{
//	freopen("in.txt","r",stdin);
	double amount;
	init();
	while(cin>>amount&&amount)
	{
		printf("%6.2lf%17ld\n",amount,key[(long)floor(amount*100+0.5)]);
	}

return 0;
}

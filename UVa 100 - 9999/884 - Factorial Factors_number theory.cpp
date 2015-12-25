/*
884 - Factorial Factors
....
就是这样.....
要学会聪明一点...
不然TLE可不爽...
*/

#include<iostream>
#include<cmath>

using namespace std;

int map[1000010],tab[1000010],n,p=2;

void calc()
{
	int i,flag,t;
	if(n<p)
		return ;
	for(;p<=n;p++)
	{
		flag=0;
		t=sqrt(p)+1;
		for(i=2;i<t;i++)
			if(!(p%i))
			{
				tab[p]=tab[p/i]+1;
				map[p]=tab[p]+map[p-1];
				flag=1;
				break;
			}
		if(!flag)
			map[p]=1+map[p-1],tab[p]=1;;

//	cout<<p<<'\t'<<map[p]<<endl;
	}
}

int main()
{
	freopen("in.txt","r",stdin);

	int ans,i;
	memset(map,0,sizeof(map));
	memset(tab,0,sizeof(tab));

	while(cin>>n)
	{
		calc();
//		ans=0;
//		for(i=2;i<=n;i++)
//			ans+=map[i];
//		cout<<ans<<endl;
		cout<<map[n]<<endl;
	}

return 0;
}

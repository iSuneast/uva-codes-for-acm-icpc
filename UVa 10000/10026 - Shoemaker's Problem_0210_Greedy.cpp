/*
10026 - Shoemaker's Problem
....
晕纳....
UVa的编译器....
太不兼容我了....CE...
....
*/

#include<iostream>
#include<algorithm>

using namespace std;

struct shoemaker
{
	int p;
	double s;
}key[1010];				//用index...CE

int cmp(const shoemaker a,const shoemaker b)
{
	if(a.s==b.s)
		return a.p < b.p;
	return a.s > b.s;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int cas,n,i,t,s;
	cin>>cas;
	while(cas--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>t>>s,
			key[i].p=i+1,
			key[i].s=(double)s/t;
		sort(key,key+n,cmp);
		cout<<key[0].p;
		for(i=1;i<n;i++)
			cout<<' '<<key[i].p;
		cout<<endl;
		if(cas)
			cout<<endl;
	}

return 0;
}

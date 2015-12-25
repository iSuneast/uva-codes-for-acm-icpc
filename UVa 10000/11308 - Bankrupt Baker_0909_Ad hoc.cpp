/*
11308 - Bankrupt Baker

Ad hoc...
it's not a dp problem
so just check whether the total cost is less than b
final sort all the legal cake as the problem description
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#define MAXN 103
using namespace std;

struct CAKE
{
	string name;
	int cost;
	bool operator<(const CAKE &t)const
	{
		if(cost==t.cost)
			return name<t.name;
		return cost<t.cost;
	}
}cake[MAXN];
string buf;
map<string,int> msi;
int tot,m,n,b,cost;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		getline(cin,buf);	getline(cin,buf);
		int l=buf.length(),t;
		for(int i=0;i<l;++i)
			buf[i]=toupper(buf[i]);
		cout<<buf<<endl;

		cin>>m>>n>>b;
		msi.clear();
		while(m--)
		{
			cin>>buf>>cost;
			msi[buf]=cost;
		}

		tot=0;
		while(n--)
		{
			getline(cin,buf);getline(cin,buf);
			cake[tot].name=buf;
			cin>>t;
			cake[tot].cost=0;
			while(t--)
			{
				cin>>buf>>cost;
				cake[tot].cost+=msi[buf]*cost;
			}
			if(cake[tot].cost<=b)
				++tot;
		}
		sort(cake,cake+tot);

		if(!tot)
			cout<<"Too expensive!"<<endl;
		else for(int i=0;i<tot;++i)
			cout<<cake[i].name<<endl;
		cout<<endl;
	}

	return 0;
}

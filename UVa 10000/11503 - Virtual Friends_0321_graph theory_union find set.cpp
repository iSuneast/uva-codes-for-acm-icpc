/*
11503 - Virtual Friends

graph theory
union find set
*/

#include<iostream>
#include<string>
#include<map>
#define MAXN 100010
using namespace std;

int fa[MAXN],key[MAXN];

int find(int p)
{
	return p==fa[p]?p:fa[p]=find(fa[p]);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int n,i,a,b,cnt=1;
		string name;
		cin>>n;
		for(i=1;i<MAXN;i++)
		{
			fa[i]=i;
			key[i]=1;
		}
		map<string,int> m;
		while(n--)
		{
			cin>>name;
			if(m.find(name)==m.end())
				m[name]=cnt++;
			a=find(m[name]);
			cin>>name;
			if(m.find(name)==m.end())
				m[name]=cnt++;
			b=find(m[name]);
			if(a!=b)
			{
				fa[a]=b;
				key[b]+=key[a];
				key[a]=0;
				cout<<key[b]<<endl;
			}
			else
				cout<<key[a]<<endl;
		}
	}


return 0;
}

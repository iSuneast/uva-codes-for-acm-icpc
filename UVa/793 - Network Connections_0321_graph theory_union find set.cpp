/*
793 - Network Connections

graph theory
union find set
*/

#include<iostream>
#include<sstream>
#include<string>
#define MAXN 10000
using namespace std;
int fa[MAXN];

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
		int n,i,j,key1=0,key2=0;
		cin>>n;getchar();
		for(i=1;i<=n;i++)
			fa[i]=i;
		string buf;
		while(getline(cin,buf) && buf!="")
		{
			stringstream sin(buf);
			char c;
			sin>>c>>i>>j;
			i=find(i);
			j=find(j);
			if(c=='c')
				fa[i]=j;
			else
				if(i!=j)
					key2++;
				else
					key1++;
		}
		cout<<key1<<','<<key2<<endl;
		if(dataset)
			cout<<endl;
	}

return 0;
}

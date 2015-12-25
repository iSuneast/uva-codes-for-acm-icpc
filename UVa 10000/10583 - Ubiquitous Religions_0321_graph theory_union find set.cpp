/*
10583 - Ubiquitous Religions

graph theory
union find set
*/

#include<iostream>
#define MAXN 50010
using namespace std;

int fa[MAXN];

int find(int p)
{	return p==fa[p]?p:fa[p]=find(fa[p]);	}

int main()
{
//	freopen("in.txt","r",stdin);

	int n,m,cas=1;
	while(cin>>n>>m && (n||m))
	{
		int i,a,b;
		for(i=1;i<=n;i++)
			fa[i]=i;
		for(i=0;i<m;i++)
		{
			cin>>a>>b;
			a=find(a);
			b=find(b);
			if(a!=b)
			{
				fa[a]=b;
				n--;
			}
		}
		cout<<"Case "<<cas++<<": "<<n<<endl;
	}

return 0;
}

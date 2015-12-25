/*
459 - Graph Connectivity

graph theory
union find set
*/

#include<iostream>
#include<set>
#include<string>
#define MAXN 30
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
		string nodes;
		cin>>nodes;getchar();
		int n=nodes[0]-'A'+1,i;
		for(i=0;i<n;i++)
			fa[i]=i;
		while(getline(cin,nodes) && nodes!="")
		{
			int a=find(nodes[0]-'A');
			int b=find(nodes[1]-'A');
			if(a!=b)
				fa[a]=b;
		}
		set<int> si;
		int key=0;
		for(i=0;i<n;i++)
			if(si.find(find(i))==si.end())
			{
				si.insert(fa[i]);
				key++;
			}
		cout<<key<<endl;
		if(dataset)
			cout<<endl;
	}

return 0;
}
/*

#include<iostream>
#include<cstring>

using namespace std;

int g[300][300],flag[300],n,cnt;

void dfs(int p)
{
	flag[p]=1;
	for(int i=0;i<n;i++)
		if(g[p][i])
		{
			g[p][i]=0;
			if(!flag[i])
				dfs(i);
		}
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	bool first=true;
	char s[3];
	cin>>dataset;getchar();getchar();	//先前的几次WA,RE都是因为输入不正确导致的

	while(dataset--)
	{
		if(first)
			first=false;
		else
			cout<<endl;
		gets(s);
		n=s[0]-'A'+1;		//n个节点
		memset(g,0,sizeof(g));
		while(gets(s) && s[0])
			g[s[0]-'A'][s[1]-'A']=g[s[1]-'A'][s[0]-'A']=1;
		cnt=0;
		memset(flag,0,sizeof(flag));
		for(int i=0;i<n;i++)
			if(!flag[i])
				dfs(i),cnt++;
		cout<<cnt<<endl;
	}

return 0;
}

*/
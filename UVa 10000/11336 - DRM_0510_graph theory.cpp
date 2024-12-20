/*
11336 - DRM

graph theory...
原来我对题意的理解也是有误的...
题目意思是要求图的一个点能不能只经过新增加的点到达旧图得另一个点...
只需要求一条路径即可...
直接dfs...
没必要用floyd求出图的传递闭包...

还有,题目说,新图必须包括了旧图里面的所有点.
若有发现没有完全包括的话应该输出无解...
此外还要注意说.用dfs找路径的时候一定要记录节点的访问情况.
图是无向的...没记录的话会无限递归...导致RE...
*/

#include<iostream>
#include<string>
#include<map>
#define MAXN 1010
using namespace std;

int g[MAXN][MAXN],g1[MAXN][2],sz1,edges,sz;
string name1,name2;
bool flag[MAXN];

bool input()
{
	memset(g,0,sizeof(g));
	sz1=0;
	edges=0;
	map<string,int> msi;
	string buf;
	while(cin>>buf && buf!="*")
	{
		if(msi.find(buf)==msi.end())
			msi[buf]=sz1++;
		g1[edges][0]=msi[buf];
		cin>>buf;
		if(msi.find(buf)==msi.end())
			msi[buf]=sz1++;
		g1[edges][1]=msi[buf];
		++edges;
	}
	getline(cin,buf);
	sz=sz1;
	int u,v;
	cin>>name2;
	memset(flag,0,sizeof(flag));
	while(cin>>buf && buf!="*")
	{
		if(msi.find(buf)==msi.end())
			msi[buf]=sz++;
		u=msi[buf];
		cin>>buf;
		if(msi.find(buf)==msi.end())
			msi[buf]=sz++;
		v=msi[buf];
		g[u][v]=g[v][u]=1;
		flag[u]=flag[v]=true;
	}
	getline(cin,buf);

	for(int i=0;i<sz1;++i)
		if(!flag[i])
			return false;
	return true;
}

bool dfs(int u,int v)
{
	if(g[u][v])
		return true;
	flag[u]=1;
	for(int cur=sz1;cur<sz;++cur)
		if(g[u][cur] && !flag[cur] && dfs(cur,v))
			return true;
	return false;
}

bool solve()
{
	for(int i=0;i<edges;++i)
	{
		memset(flag,0,sizeof(flag));
		if(!dfs(g1[i][0],g1[i][1]))
			return false;
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(getline(cin,name1) && name1!="END")
	{
		if(input() && solve())
			cout<<"YES: "<<name2<<" is a more detailed version of "<<name1<<endl;
		else
			cout<<"NO: "<<name2<<" is not a more detailed version of "<<name1<<endl;
	}

	return 0;
}

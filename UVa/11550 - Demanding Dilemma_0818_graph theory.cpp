/*
11550 - Demanding Dilemma

graph theory...
给一个关联矩阵...
判断是否是一张简单图...
提取给定的矩阵,每一列为1元素位置
如果位置不为2个,则无解
如果同样的位置已经出现过无解(simple图)...
*/

#include<iostream>
#include<vector>
#define MAXN 10
using namespace std;

int n,m,data[MAXN][MAXN*MAXN];
bool g[MAXN][MAXN];

bool chk()
{
	memset(g,0,sizeof(g));
	for(int j=0;j<m;++j)
	{
		vector<int> node;
		for(int i=0;i<n;++i)
			if(data[i][j])
				node.push_back(i);
		if(node.size()!=2)
			return false;
		if(g[ node[0] ][ node[1] ])
			return false;
		g[ node[0] ][ node[1] ]=true;
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,t;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",&data[i][j]);

		puts(chk()?"Yes":"No");
	}

	return 0;
}

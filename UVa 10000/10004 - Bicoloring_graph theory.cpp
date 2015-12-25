/*
10004 - Bicoloring
...
这题是对点着色...
不是对边...
*/

#include<iostream>

using namespace std;

int n,l,map[210][210],flag,node[210];

void dfs(int a,int color)
{
	node[a]=color;
	color=(color==2?3:2);
	for(int i=0;i<n;i++)
		if(map[a][i])
		{
			if(!node[i])
				dfs(i,color);
			else if(node[i]!=color)
			{
				flag=1;
				return ;
			}
		}
}

int main()
{
//	freopen("in.txt","r",stdin);

	while(cin>>n && n)
	{
		int a,b;
		memset(map,0,sizeof(map));
		memset(node,0,sizeof(node));
		cin>>l;
		while(l--)
		{
			cin>>a>>b;
			map[a][b]=1;
		}
		flag=0;
		dfs(0,2);
		if(!flag)
			cout<<"BICOLORABLE."<<endl;
		else
			cout<<"NOT BICOLORABLE."<<endl;
	}

return 0;
}

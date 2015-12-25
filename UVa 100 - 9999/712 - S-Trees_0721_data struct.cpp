/*
712 - S-Trees

data struct...
好长的题目...
看了很多遍才懂...
看懂了就会做了...
水题...没几行代码...

其实就是给定一颗完全二叉树的最后一层节点的bfs遍历
然后给定一系列从根节点出发的遍历
求遍历到最后的叶子节点的值
直接化二进制为十进制,然后输出最后一层对应的值即可
*/

#include<iostream>
#define MAXN 256
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,m,cas=1;
	char s[MAXN],t[16];
	while(scanf("%d",&n)!=EOF && n)
	{
		while(n--)
			scanf("%s",s);
		scanf("%s",s);
		scanf("%d",&m);

		printf("S-Tree #%d:\n",cas++);
		while(m--)
		{
			scanf("%s",t);
			int i=0,var=0;
			while(t[i])
				var=var*2+t[i++]-'0';
			cout<<s[var];
		}
		puts("\n");
	}

	return 0;
}

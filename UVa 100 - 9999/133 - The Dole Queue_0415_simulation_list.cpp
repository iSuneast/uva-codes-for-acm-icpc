/*
133 - The Dole Queue

simulation...
模拟了好久...
*/

#include<iostream>
#define MAXN 25
using namespace std;

int var[MAXN],front[MAXN],back[MAXN];

inline void erase(int p)
{
	back[ front[p] ]=back[p];
	front[ back[p] ]=front[p];
}

int main()
{
//	freopen("in.txt","r",stdin);

	int n,k,m;
	while(cin>>n>>k>>m && (n||k||m))
	{
		int i,begin=n,end=0;
		memset(var,0,sizeof(var));		//初始化...没有初始化的话好像有问题.
		memset(front,0,sizeof(front));
		memset(back,0,sizeof(back));
		for(i=0;i<n;++i)
		{
			var[i]=i+1;
			front[i]=(i+n+1)%n;
			back[i]=(i+n-1)%n;
		}
		bool first=true;
		while(n>0)
		{
			if(first)
				first=false;
			else
				putchar(',');
			int pase=k%n+n;
			while(pase--)
				begin=front[begin];
			pase=m%n+n;		//这里要求余,不然UVa的BT数据估计是什么眼的服务器都受不了的...
			while(pase--)
				end=back[end];
			if(begin==end)
			{
				printf("%3d",var[begin]);
				erase(begin);
				--n;
			}
			else
			{
				printf("%3d%3d",var[begin],var[end]);
				if(front[begin]==end)		//特殊情况...只需交换begin 和 end 就可以轻松转换了...
				{
					begin=front[begin];
					end=back[end];
				}
				erase(begin);
				erase(end);
				n-=2;
			}
		}
		putchar('\n');
	}

	return 0;
}

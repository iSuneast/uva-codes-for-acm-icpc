/*
10620 - A Flea on a Chessboard

simulation...
直接照题目意思模拟...
仔细观察可以发现,有效的状态其实集中在[0-2s,0-2s]区间
将x,y对2s取模后,用set保存...
如果发现值重复出现,则无解
是解的情况在两个区间[0-s,s-2s],[s-2s,0-s].
此外注意,先判断再转移...
这样就不要特殊考虑在0点退出的情况了
*/

#include<iostream>
#include<set>
using namespace std;

set<int> si;

int hash(int x,int y)
{
	return x*10000+y;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int s,x,y,dx,dy,h,mod;
	while(scanf("%d%d%d%d%d",&s,&x,&y,&dx,&dy)!=EOF && (s||x||y||dx||dy))
	{
		mod=2*s;
		si.clear();
		int jump=0;
		while(true)
		{
			if(si.find( h=hash(x%mod,y%mod) )==si.end())
			{
				int tx=x%mod,ty=y%mod;
				if((0<tx && tx<s && s<ty && ty<mod) || (s<tx && tx<mod && 0<ty && ty<s))
					break;
				si.insert(h);
			}
			else
			{
				jump=-1;
				break;
			}
			x+=dx,y+=dy;
			++jump;
		}

		if(jump==-1)
			puts("The flea cannot escape from black squares.");
		else
			printf("After %d jumps the flea lands at (%d, %d).\n",jump,x,y);
	}

	return 0;
}

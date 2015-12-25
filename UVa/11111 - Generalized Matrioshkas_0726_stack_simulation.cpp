/*
11111 - Generalized Matrioshkas

stack...
simulation...
按照题目的意思模拟入栈出栈操作
并用一个sz数组记录当前某个位置的盒子里面东西的大小
东西太大的话装不下就false
如果装到最后发现栈非空也是false
否则就是true
*/

#include<iostream>
#define MAXN 1000000
#define INF 0x3f3f3f3f
using namespace std;

char s[MAXN];
int stack[MAXN],sz[MAXN];

bool chk()
{
		char *token=strtok(s," ");
		int cur=1,n;
		stack[0]=INF;sz[0]=0;
		while(token)
		{
			sscanf(token,"%d",&n);
			if(n<0)
			{
				stack[cur]=-n;
				sz[cur]=0;
				++cur;
			}
			else
			{
				if(cur>1 && stack[cur-1]==n)
				{
					sz[cur-2]+=n;
					if(stack[cur-2]<=sz[cur-2])
						return false;
					--cur;
				}
				else
					return false;
			}
			token=strtok(NULL," ");
		}
		return cur==1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(gets(s))
		if(chk())
			puts(":-) Matrioshka!");
		else
			puts(":-( Try again.");

	return 0;
}

/*input
-3
*/

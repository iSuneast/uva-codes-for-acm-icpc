/*
11111 - Generalized Matrioshkas

stack...
simulation...
������Ŀ����˼ģ����ջ��ջ����
����һ��sz�����¼��ǰĳ��λ�õĺ������涫���Ĵ�С
����̫��Ļ�װ���¾�false
���װ�������ջ�ǿ�Ҳ��false
�������true
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

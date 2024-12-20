/*
11412 - Dig the Holes

brute force...
猜数字游戏...
判断某状态是否有解...
预先算出所有可能状态后.
暴力枚举即可...
*/

#include<iostream>
#define MAXN 400
#define MAXSTATE 6
using namespace std;

const char color[]="RGBYOV";
char state[MAXN][4],buf[4];
bool flag[MAXSTATE];
int tot=0;

void dfs(int dep)
{
	if(dep==4)
		memcpy(state[tot++],buf,sizeof(buf));
	else for(int i=0;i<MAXSTATE;++i)
		if(!flag[i])
		{
			flag[i]=true;
			buf[dep]=color[i];
			dfs(dep+1);
			flag[i]=false;
		}
}

void done(char *a,char *b,int &n1,int &n2)
{
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			if(a[i]==b[j])
			{
				if(i==j)
					++n1;
				else
					++n2;
			}
}

bool chk_more(char *t)
{
	for(int i=0;i<4;++i)
		for(int j=i+1;j<4;++j)
			if(t[i]==t[j])
				return false;
	return true;
}

bool chk()
{
	char tmp[2][5];
	int n[2][2];
	scanf("%s%d%d",tmp[0],&n[0][0],&n[0][1]);
	scanf("%s%d%d",tmp[1],&n[1][0],&n[1][1]);

	if(!chk_more(tmp[0]) || !chk_more(tmp[1]))
		return false;

	for(int i=0;i<tot;++i)
	{
		int t1=0,t2=0;
		done(state[i],tmp[0],t1,t2);
		if(!(t1==n[0][0] && t2==n[0][1]))
			continue;
		done(state[i],tmp[1],t1=0,t2=0);
		if(t1==n[1][0] && t2==n[1][1])
			return true;
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	dfs(0);
	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
		if(chk())
			puts("Possible");
		else
			puts("Cheat");

	return 0;
}

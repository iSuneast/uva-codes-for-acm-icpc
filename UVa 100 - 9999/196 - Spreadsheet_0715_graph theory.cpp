/*
196 - Spreadsheet

graph theory...
其实就是搜索题...
由于不存在死循环所以直接dfs可以了...

题目数据规模给的不是很清楚...
公式长度开10000
公式个数开10000就可以了...
至于公式里面的元素个数...
可能会出现很多的情况用vector开就可以了
*/

#include<iostream>
#include<algorithm>
#include<vector>
#define INF 0x3f3f3f3f
using namespace std;

int excel[1010][18300],pos[10000],r,c,cnt;
vector<int> dic[10000];
char buf[10000];

int hash(int x,int y)
{
	return x*18300+y;
}

int toInt(char *s)
{
	int x=0,y=0,p=0;
	while(s[p])
	{
		if(s[p]>='A')
			y=y*26+s[p]-'A'+1;
		else
			x=x*10+s[p]-'0';
		++p;
	}
	return hash(x,y);
}

void insert(int p)
{
	dic[p].clear();
	char *token=strtok(buf+1,"+");
	while(token)
	{
		int pos=toInt(token);
		dic[p].push_back(pos);
		token=strtok(NULL,"+");
	}
}

int dfs(int p)
{
	int x=p/18300,y=p%18300;

	if(excel[x][y]<INF)
		return excel[x][y];

	int k=lower_bound(pos,pos+cnt,p)-pos;
	int sz=dic[k].size(),key=0;
	for(int i=0;i<sz;++i)
		key+=dfs( dic[k][i] );

	return excel[x][y]=key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		cnt=0;
		scanf("%d%d",&c,&r);
		for(int i=1;i<=r;++i)
		{
			for(int j=1;j<=c;++j)
			{
				excel[i][j]=INF;
				scanf("%s",buf);
				if(buf[0]=='=')
				{
					pos[cnt]=hash(i,j);
					excel[i][j]+=pos[cnt];
					insert(cnt++);
				}
				else
					sscanf(buf,"%d",&excel[i][j]);
			}
		}
		for(int i=1;i<=r;++i)
		{
			for(int j=1;j<=c;++j)
			{
				if(j!=1)
					putchar(' ');
				if(excel[i][j]>=INF)
					dfs(excel[i][j]-INF);
				printf("%d",excel[i][j]);
			}
			putchar('\n');
		}
	}


	return 0;
}

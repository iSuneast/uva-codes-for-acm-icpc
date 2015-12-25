/*
417 - Word Index

backtracking...
*/

#include<iostream>
#include<algorithm>
#define MAXN 83700
#define MAXLEN 6
using namespace std;

char key[MAXN][MAXLEN],buf[MAXLEN];
int len,cnt,hash[30],p[MAXLEN];

void dfs(int cur,char p)
{
	if(cur==len)
		memcpy(key[cnt++],buf,sizeof(buf));
	else for(char i='a';i<='z';++i)
		if(!hash[i-'a'] && i>p)
		{
			hash[i-'a']=1;
			buf[cur]=i;
			dfs(cur+1,i);
			hash[i-'a']=0;
		}
}

int main()
{
//	freopen("in.txt","r",stdin);

	for(len=1;len<MAXLEN;++len)
	{
		p[len]=cnt;
		dfs(0,'a'-1);
	}
	while(gets(buf))
	{
		char buf2[MAXLEN];
		strcpy(buf2,buf);
		sort(buf2,buf2+strlen(buf2));
		if(strcmp(buf,buf2))
			cout<<0<<endl;
		else
		{
			int cur=p[strlen(buf)];
			while(true)
				if(!strcmp(buf,key[cur++]))
					break;
				cout<<cur<<endl;
		}
	}

	return 0;
}

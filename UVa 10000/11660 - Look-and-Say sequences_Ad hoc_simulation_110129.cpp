/*
11660 - Look-and-Say sequences

Ad hoc...
simulation....
不懂怎么做，于是就直接模拟，然后就过了~
开大小1000的数组，来模拟就可以了
估计是数据比较水~

happy coding~
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 1003
using namespace std;

int n,m,len;
char x[2][MAXN],buf[10];

bool link(char *s,int cnt,int n)
{
	sprintf(buf,"%d",cnt);
	int l=strlen(buf);
	if(len+l>=MAXN)
		return false;
	strcpy(s+len,buf);
	len+=l;
	
	sprintf(buf,"%d",n);
	l=strlen(buf);
	if(len+l>=MAXN)
		return false;
	strcpy(s+strlen(s),buf);
	len+=l;
	
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif
	
	while(scanf("%s%d%d",x[0],&n,&m)!=EOF && (strcmp(x[0],"0")||n||m))
	{
		int cur=0,next=1;
		for(int i=2;i<=n;++i)
		{
			x[next][len=0]=0;
			int l=strlen(x[cur]);
			for(int j=0;j<l;)
			{
				int k=j+1;
				while(x[cur][k]==x[cur][k-1])
					++k;
				if(!link(x[next],k-j,x[cur][j]-'0'))
					break;
				j=k;
			}

			swap(cur,next);
		}
		
		printf("%c\n",x[cur][m-1]);
	}
	
	return 0;
}

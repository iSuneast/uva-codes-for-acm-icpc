/*
548 - Tree

tree building...
给定中序和后序遍历求树的和...
*/

#include<iostream>
#define INF 1e9
#define MAXN 10010
using namespace std;

int key,ans,io[MAXN],po[MAXN],n,p;

void build(int start,int end,int s)
{
	if(start+1==end)
	{
		s+=po[p--];
		if(key>s)
		{
			key=s;
			ans=io[start];
		}
		else if(key==s)
			ans=ans<io[start]?ans:io[start];
		return ;
	}
	else if(start>=end)
		return ;
	int i;
	for(i=start;i<end;++i)
		if(io[i]==po[p])
			break;
	s+=po[p--];
	build(i+1,end,s);
	build(start,i,s);
}

int main()
{
//	freopen("in.txt","r",stdin);

	while(true)
	{
		n=0;
		char c;
		bool next=false;
		while(scanf("%d",&io[n++])!=EOF)
		{
			next=true;
			if((c=getchar())=='\r' || c=='\n')
				break;
		}
		if(!next)
			return 0;
		for(int i=0;i<n;++i)
			scanf("%d",&po[i]);
		p=n-1;
		key=ans=INF;
		build(0,n,0);
		cout<<ans<<endl;
	}

	return 0;
}

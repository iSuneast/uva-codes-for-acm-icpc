/*
165 - Stamps

brute force...
暴力打表...
直接枚举子集即可...
规模实在是小应该不会超时吧...
*/

#include<iostream>
using namespace std;

int h,k,key[13],ans[13],maxn;
bool flag[73];

void brute(int cur,int cnt,int s)
{
	flag[s]=true;
	if(!cnt)
		return ;
	for(int i=cur;i<k;++i)
		brute(cur,cnt-1,s+key[i]);
}

int general()
{
	memset(flag,0,sizeof(flag));
	brute(0,h,0);
	for(int i=1;;++i)
		if(!flag[i])
			return i-1;
}

void dfs(int cur,int dep)
{
	if(dep==k)
	{
		int t=general();
		if(t>maxn)
		{
			maxn=t;
			memcpy(ans,key,sizeof(key));
		}
	}
	else for(int i=cur;i<33;++i)
	{
		key[dep]=i;
		dfs(i+1,dep+1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&h,&k)!=EOF && (h||k))
	{
		maxn=0;
		key[0]=1;
		dfs(2,1);
		for(int i=0;i<k;++i)
			printf("%3d",ans[i]);
		printf(" ->%3d\n",maxn);
	}

	return 0;
}

/*rand.cpp
#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","w",stdout);
#endif

	for(int i=1;i<=9;++i)
		for(int j=1;j+i<=9;++j)
			cout<<i<<"   "<<j<<endl;
	cout<<"0 0"<<endl;

	return 0;
}
*/

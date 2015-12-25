/*
11786 - Global Raining at Bididibus

Ad hoc...
UVa contest 时候做出来的.
jwq说可以先建立坐标高度
然后从两边开始向中间压缩
令start,end为头尾坐标的下标idx[]保存坐标信息
while start<end
	if idx[start]<idx[end]
		if idx[start+1]<idx[start]
			idx[start+1]=idx[start]
		++start
	else
		if idx[end]>idx[end-1]
			idx[end-1]=idx[end]
		--end
*/

#include<iostream>
#define MAXN 10010
using namespace std;

char s[MAXN];
int idx[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%s",s);
		int l=strlen(s);
		idx[0]=0;
		for(int i=1;i<=l;++i)
			if(s[i-1]=='/')
				idx[i]=idx[i-1]+1;
			else if(s[i-1]=='_')
				idx[i]=idx[i-1];
			else if(s[i-1]=='\\')
				idx[i]=idx[i-1]-1;
		int start=0,end=l,ans=0,cur;
		while(start<end)
		{
			if(idx[start]<idx[end])
			{
				if(idx[start+1]<idx[start])
				{
					ans+=idx[start]-idx[start+1];
					idx[start+1]=idx[start];
				}
				++start;
			}
			else
			{
				if(idx[end]>idx[end-1])
				{
					ans+=idx[end]-idx[end-1];
					idx[end-1]=idx[end];
				}
				--end;
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}

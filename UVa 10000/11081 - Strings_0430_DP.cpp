/*
11081 - Strings

DP...
����һ��ʼ��lrj�ĸ�...
����ĺܸ���...
�����ƺ����뵽�˽ⷨȴһֱ��������ȥд...
��ʵ˵�������Ǻܼ򵥵�...

ֻ������ö��a,b,c�����ַ����Ĺ�ϵ����...
a[tsa]==c[sc]	��	dp(tsa+1,sb,sc+1)
b[tsb]==c[sc]	��	dp(sa,tsb+1,sc+1)
���仯��������...
(�ٶȱȽ���...����2.0sAC...����)
�߽�������sc==lc	��c�ַ����Ѿ�����ĩβ..

���ע��һ���ǽ��Ҫȡģ...
key[sa][sb][sc]%=10007	��%=������%
�����м������...
*/

#include<iostream>
#define MAXN 65
using namespace std;

char a[MAXN],b[MAXN],c[MAXN];
int key[MAXN][MAXN][MAXN],la,lb,lc;

int dp(int sa,int sb,int sc)
{
	if(key[sa][sb][sc]!=-1)
		return key[sa][sb][sc];
	key[sa][sb][sc]=0;
	if(sc==lc)
		return key[sa][sb][sc]=1;
	for(int tsa=sa;tsa<la;++tsa)
		if(a[tsa]==c[sc])
			key[sa][sb][sc]+=dp(tsa+1,sb,sc+1);
	for(int tsb=sb;tsb<lb;++tsb)
		if(b[tsb]==c[sc])
			key[sa][sb][sc]+=dp(sa,tsb+1,sc+1);
	return key[sa][sb][sc]%=10007;	//��%=������%
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		cin>>a>>b>>c;
		la=strlen(a);
		lb=strlen(b);
		lc=strlen(c);
		memset(key,-1,sizeof(key));
		cout<<dp(0,0,0)<<endl;
	}

	return 0;
}

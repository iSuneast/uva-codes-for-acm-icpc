/*
10404 - Bachet's Game

DP...
���Ų��ٵĲ���ɫ��...
ò�ƺͱ�������Ҳ����...

����sample: 23 3 1 3 8
���ǿ��Եõ����µ�״̬ת��...
  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
  1  0  1  0  1  0  1  1  1  1  0  1  0  1  0  1  0  1  1  1  1  0  1
1����-----Stan wins
0����-----Ollie wins

��֪:��������״̬����Stan��Ӯ����...
���ǿ��Եõ�˵����ڵ�i��״̬,����ȡ�Ӹ���w[j]����һ��flag[i-w[j]]Ϊfalse
������˵��״̬i-w[j]��OllieӮ..��
���ݲ�������ÿ���˶���ȡ���Ų���,������i-w[j]̬һ����OllieӮ..
�����ڵ�i��״̬Stan��һ��Ӯ...

���Ҵ�����Ĵ����Կ���..
���ֵĻ�ʤ���ʸ���...
*/

#include<iostream>
#define MAXN 1000010
using namespace std;

bool flag[MAXN];
int w[20],n,m;

bool dp()
{
	memset(flag,0,sizeof(flag));
	int i,j;
	flag[0]=true;
	for(i=0;i<m;++i)
		flag[w[i]]=true;
	for(i=1;i<=n;++i)
		if(!flag[i])
			for(j=0;j<m;++j)
				if(i>=w[j] && !flag[i-w[j]])
				{
					flag[i]=true;
					break;
				}
	return flag[n];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(cin>>n>>m)
	{
		for(int i=0;i<m;++i)
			cin>>w[i];
		if(dp())
			puts("Stan wins");
		else
			puts("Ollie wins");
	}

	return 0;
}

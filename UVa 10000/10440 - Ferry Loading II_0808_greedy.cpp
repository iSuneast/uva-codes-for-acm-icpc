/*
10440 - Ferry Loading II

greedy...
�Ϲ��...
�Ӻ���ǰ̰��...
���صľ�����,����¼װ��ʱ��
Ȼ���ٴ�ǰ����ɨ��ȡ��ʱ����ۼ�...
*/

#include<iostream>
#define MAXN 1444
using namespace std;

int n,t,m,tim[MAXN];
int add[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d%d",&n,&t,&m);
		for(int i=0;i<m;++i)
			scanf("%d",&tim[i]);
		int key=0,cnt=0;
		while(m)
		{
			add[cnt++]=tim[m-1];
			int k=n;
			while(k && m)
				--k,--m;
		}
		for(int i=cnt-1;i;--i)
			add[i-1]=max(add[i-1],add[i]+t*2);

		printf("%d %d\n",add[0]+t,cnt);
	}
	
	return 0;
}

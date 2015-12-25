/*
11292 - Dragon of Loowater

greedy...
��Ȼһ��knightֻ������һ��dragon
�ǵ�Ȼ�ڿ��������ǰ����ԽʡǮԽ��...
���Զ�knight�������ֲ���dragonֵ,�ۼ�����ֵ����
*/

#include<iostream>
#include<algorithm>
#define MAXN 20010
using namespace std;

int dragon[MAXN],knight[MAXN];
bool flag[MAXN];
int n,m;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		for(int i=0;i<n;++i)
			scanf("%d",dragon+i);

		for(int i=0;i<m;++i)
		{
			scanf("%d",knight+i);
			flag[i]=false;
		}
		sort(knight,knight+m);
		
		int key=0;
		for(int i=0;i<n;++i)
		{
			int p=lower_bound(knight,knight+m,dragon[i])-knight;
			while(p<m && flag[p])
				++p;
			if(p==m)
			{
				key=-1;
				break;
			}
			else
			{
				key+=knight[p];
				flag[p]=true;
			}
		}
		if(key==-1)
			puts("Loowater is doomed!");
		else
			printf("%d\n",key);
	}

	return 0;
}

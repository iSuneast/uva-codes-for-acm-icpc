/*
 * 10202 - Pairsumonious Numbers
 *
 * greedy...
 * �ǳ�ţ�Ƶ�����
 * ��mΪ��С��sum,��,
 *   @ m<0 , ans[0] ��СΪm
 *   @ ����, ans[0] ��СΪ0
 *   ans[0] ���Ϊm/2
 *
 * ֻ��ö��ans[0]��ֵ,�Ϳ��Ե��Ƴ�����������
 * ��sum���浽һ������set
 *
 * ans[1] = set������Сֵ-ans[0]
 * ɾ�� set����� ans[0] + ans[1]
 *
 * ans[2] = set������Сֵ-ans[0]
 * ɾ�� set����� ans[0] + ans[2], ans[1]+ans[2]
 * ...
 * (��ϸ����,����ķ������Ǻ���Ȼ��)
 *
 * �Դ�����,�����ͨ�����Ϸ����Ƶ�����ans[],��ans[]��Ϊ���н�
 * �����޽�
 */

#include<cstdio>
#include<map>
#define MAXN 50
using namespace std;

int s[MAXN], n, tot, key[MAXN];

bool process()
{
	map<int,int> mii;
	for(int i=0;i<tot;++i)
	{
		if( mii.find(s[i]) == mii.end() )
			mii[ s[i] ]=1;
		else
			++mii[ s[i] ];
	}

	for(int i=1;i<n;++i)
	{
		key[i]=mii.begin()->first-key[0];
		for(int j=0;j<i;++j)
		{
			int t= key[i]+key[j];
			if(mii.find(t)==mii.end())
				return false;
			if(mii[t]==1)
				mii.erase(t);
			else
				mii[t]--;
		}
	}

	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF)
	{
		tot = n*(n-1)/2;
		int m=1e9;
		for(int i=0; i<tot; ++i)
		{
			scanf("%d", s+i);
			m=min(m, s[i]);
		}

		bool got=false;
		for(int l= (m<0)?m:0, u=s[0]/2; l<=u; ++l)
		{
			key[0]=l;
			if(process())
			{
				for(int i=0;i+1<n;++i)
					printf("%d ",key[i]);
				printf("%d\n",key[n-1]);
				got=true;
				break;
			}
		}

		if(!got)
			puts("Impossible");
	}

	return 0;
}

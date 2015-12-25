/*
11572 - Unique Snowflakes

simulation...
ģ��һ�����м���...
��map��¼ÿ��Ԫ�ص�ӳ��
��ӳ���Ƿ����,���ڵĻ�,��
ɾ��������ӳ��ǰ���ֵ�Ԫ��...
ͳ�ƶ�������Ԫ�صĸ���,���ľ��Ǵ���...
*/

#include<iostream>
#include<map>
#define MAXN 1000003
#define INF 0x3f3f3f3f
#define eps 1e-9
using namespace std;

int var[MAXN],n,pos[MAXN];
bool flag[MAXN];
map<int,int> mii;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		memset(flag,0,sizeof(flag));
		mii.clear();

		int tot=0,front=0,_max=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&var[i]);
			if(mii.find(var[i])==mii.end())
				pos[i]=tot,mii[ var[i] ]=tot++;
			else
				pos[i]=mii[ var[i] ];

			if(flag[ pos[i] ])
			{
				do
					flag[ pos[front] ]=false;
				while(pos[front++]!=pos[i]);
			}
			_max=max(_max,i-front+1);
			flag[ pos[i] ]=true;
		}

		printf("%d\n",_max);
	}

	return 0;
}

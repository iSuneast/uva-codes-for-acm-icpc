/*
11559 - Event Planning

Ad hoc...
ֻҪ��һ��ĳ���ùݵ�ĳ������Ƿ����㹻�ķ���ס��
�еĻ�,�������,ȡ��С�ļ���
����С��Ҳ��Ԥ��,�Ǿ��޽���..
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n,b,h,w;
	while(scanf("%d%d%d%d",&n,&b,&h,&w)!=EOF)
	{
		int key=INF,money,ppl;
		for(int i=0;i<h;++i)
		{
			bool well=false;
			scanf("%d",&money);
			for(int j=0;j<w;++j)
			{
				scanf("%d",&ppl);
				if(ppl>=n)
					well=true;
			}
			if(well)
				key=min(key,n*money);
		}

		if(key>b)
			puts("stay home");
		else
			printf("%d\n",key);
	}

	return 0;
}

/*
11204 - Musical instruments

Ad hoc..
+_+��Ŀ��˼������Ⱑ...
��������˾ͺ�����...
ֻҪ�����ȼ�Ϊ1�������Ϳ�����.
���Ժ�����������ȫ�޹�
ͳ��һ��ÿ�������ȼ���ߵ�����
Ȼ����������Ǵ���...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int n,m,key[35]={0},t;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
			{
				scanf("%d",&t);
				if(t==1)
					++key[j];
			}
		int ans=1;
		for(int j=0;j<n;++j)
			if(key[j])
				ans*=key[j];
		printf("%d\n",ans);
	}

	return 0;
}

/*
10880 - Colin and Ryan

number theory..
��ʵ���Ǽ���	C=R+G*Q
�����������(C-R)��������
�������...

��Ȼ����ֱ��O(n)��ö��
ֻ��Ҫ�㵽sqrt(n),Ȼ����i*j==c
��j=c/i(ע��i==j������Ϳ�����)
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,c,r;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d%d",&c,&r);
		if(c==r)
		{
			printf("Case #%d: 0\n",cas);
			continue;
		}
		c-=r;

		printf("Case #%d:",cas);
		vector<int> key;
		for(int i=1;i*i<=c;++i)
			if(c%i==0)
			{
				key.push_back(i);
				if(i*i!=c)
					key.push_back(c/i);
			}
		sort(key.begin(),key.end());
		for(int i=0;i<key.size();++i)
			if(key[i]>r)
				printf(" %d",key[i]);
		putchar('\n');
	}

	return 0;
}

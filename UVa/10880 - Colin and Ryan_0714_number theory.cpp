/*
10880 - Colin and Ryan

number theory..
其实就是计算	C=R+G*Q
算出可以整除(C-R)的所有数
输出即可...

当然不能直接O(n)的枚举
只需要算到sqrt(n),然后由i*j==c
得j=c/i(注意i==j的情况就可以了)
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

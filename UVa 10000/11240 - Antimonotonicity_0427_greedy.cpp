/*
11240 - Antimonotonicity

greedy...
贪心算法...

原理很简单...
每次都寻找序列里面已有的最佳匹配...
如果存在则更新解...
*/

#include<iostream>
#define MAXN 30010
using namespace std;

int var[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int n,i;
		cin>>n;
		for(i=0;i<n;++i)
			scanf("%d",var+i);
		int cur=var[0],key=1;
		bool bigger=true;
		for(i=1;i<n;++i)
		{
			if(cur>var[i] && !bigger)		//保存的值比当前的大,但是此时正确的序列值应该比较小
				cur=var[i];
			else if(cur<var[i] && bigger)	//保存的值比当前的小,但是此时正确的序列值应该比较大
				cur=var[i];
			if( (cur>var[i] && bigger)
				|| (cur<var[i] && !bigger) )	//如果存在满足条件的值的话.累加.并且更新bigger.
			{
				cur=var[i];
				bigger=!bigger;
				++key;
			}
		}
		cout<<key<<endl;
	}

	return 0;
}

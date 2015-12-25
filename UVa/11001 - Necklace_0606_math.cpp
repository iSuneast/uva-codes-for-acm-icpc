/*
11001 - Necklace

math...
最近一看到题目就迫不及待地想推公式...
求n*0.3*sqrt(v/n-v0)的最大的n的值
	 n*0.3*sqrt(v/n-v0)
	=0.3*sqrt(v*n-v0*n*n)
sqrt()里面是条抛物线
当n=-v/(2*(-v0))=v/(2*v0)时,函数值最大
分三种情况讨论...
n的小数部分
	=0.5时,无解0
	>0.5时,解为n+1
	<0.5是,解为n

高中数学知识..
不解释了...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int vt,v0;
	while(scanf("%d%d",&vt,&v0)!=EOF && (vt||v0))
	{
		if(vt<=v0)
			puts("0");
		else
		{
			int t=vt/(2*v0);
			int t2=vt-2*v0*t;
			if(t2==v0)
				puts("0");
			else if(t2>v0)
				printf("%d\n",t+1);
			else
				printf("%d\n",t);
		}
	}

	return 0;
}

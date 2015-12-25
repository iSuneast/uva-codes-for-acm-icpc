/*
10493 - Cats, with or without Hats

math...
推推公式就出来了..
	1 -> n
也就是说,一只有帽子的猫可以扩展为n只没帽子的猫
然后该如何扩展是非常关键的,貌似没有规律...
但是只要认真想想就会发现说,无论拿那一只猫来扩展,结果都是一样的
{ n | 1+ (n-1)}	可以发现新产生的n只猫可以表示为1+(n-1),只要拿里面的1出来递归扩展就可以了
令k为扩展的次数,则发现没有帽子的猫m=(k-1)*(n-1)+n=k*(n-1)+1
得	k=(m-1)/(n-1)
猫的总数=k*n+1

显然k不是整数的话,结果是不存在的
当n=1时,m=1的话就有无穷多种解,否则无解
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		if(n==1)
		{
			if(m==1)
				printf("%d %d Multiple\n",n,m);
			else
				printf("%d %d Impossible\n",n,m);
		}
		else
		{
			if((m-1)%(n-1)==0)
				printf("%d %d %d\n",n,m,(m-1)/(n-1)*n+1);
			else
				printf("%d %d Impossible\n",n,m);
		}
	}

	return 0;
}

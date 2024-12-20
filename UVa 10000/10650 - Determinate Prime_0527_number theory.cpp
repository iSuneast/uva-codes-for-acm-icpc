/*
10650 - Determinate Prime

munber theory...
这题的tricky好多啊...
其次发现说我写错了很多的地方...

a-b-c-d-e 是符合题目要求的一个连串
输入 b d 则无解
同理,输入 a c,a d等仅仅截取部分区间都是无解的
所以对某个区间要考虑他的前后素数是否可以和当前串组成更长的串
可以组成的话
	@没有越界,输出
	@越界,continue(不能用break)
*/

#include<iostream>
#include<algorithm>
#define MAXN 32000
using namespace std;

bool flag[MAXN+3];
int prime[MAXN+3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cnt=0;
	prime[cnt++]=2;
	memset(flag,0,sizeof(flag));
	for(int i=3;i<=MAXN;i+=2)
		if(!flag[i])
		{
			prime[cnt++]=i;
			for(int j=i+i;j<=MAXN;j+=i)
				flag[j]=true;
		}
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF && (a||b))
	{
		if(a>b)		//晕,a可能比b要大?
			swap(a,b);
		int low=lower_bound(prime,prime+cnt,a)-prime;
		int up=upper_bound(prime,prime+cnt,b)-prime;
		for(int i=low;i<up;++i)
			if(prime[i]+prime[i+2]==2*prime[i+1])
			{
				if(i && prime[i]*2==prime[i+1]+prime[i-1])	//要与之前的比较
					continue;
				int j=i+3;
				while(prime[j]-prime[j-1]==prime[i+1]-prime[i])	//不能对j加其它的终止条件 prime[j]<=b就是错的
					++j;
				if(j>up)	//与之后的比较是否越界
					continue;
				printf("%d",prime[i]);
				for(int k=i+1;k<j;++k)
					printf(" %d",prime[k]);
				putchar('\n');
			}
	}

	return 0;
}

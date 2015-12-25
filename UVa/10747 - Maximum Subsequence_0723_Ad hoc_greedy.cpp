/*
10747 - Maximum Subsequence

Ad hoc..
先按数字大小的绝对值排序
绝对值一样的元素按大小排序

最后从绝对值大的元素开始一遍贪心即可
如果贪心得到的负数个数是奇数的话想办法通过交换元素来取得正的最大乘积
	@从解序列里面找一个负数,然后从剩余的元素里面找一个正数
	@从解序列里面找一个正数,然后从剩余的元素里面找一个负数
两种情况,尝试交换元素,取获得最大乘积的一组.乘积一样取和最大的一组

如果两种情况都没有出现,则说明序列里面的元素<=0
只需按值大小排序.然后取前k项最大值求和即可...
*/

#include<iostream>
#include<algorithm>
#define MAXN 10010
using namespace std;
typedef pair<int,int> pii;

int n,k,var[MAXN];

int cmp(const int a,const int b)
{
	if(abs(a)!=abs(b))
		return abs(a)>abs(b);
	else
		return a>b;
}

int s;

pii process1()
{
	for(int i=k;i<n;++i)
	{
		if(var[i]<0)
			for(int j=k-1;j>=0;--j)
				if(var[j]>0)
					return make_pair(j,i);
	}
	return make_pair(-1,-1);
}

pii process2()
{
	for(int i=k;i<n;++i)
	{
		if(var[i]>0)
			for(int j=k-1;j>=0;--j)
				if(var[j]<0)
					return make_pair(j,i);
	}
	return make_pair(-1,-1);
}

int sum()
{
	sort(var,var+n);
	int s=0;
	for(int i=n-1;i>=n-k;--i)
		s+=var[i];
	return s;
}

int calc()
{
	s=0;
	bool negetive=false;
	sort(var,var+n,cmp);
	for(int i=0;i<k;++i)
	{
		if(var[i]<0)
			negetive=!negetive;
		s+=var[i];
		if(!var[i])
			return sum();
	}

	if(!negetive)
		return s;

	pii a=process1();
	pii b=process2();
	if(a.first!=-1 && b.first!=-1)
	{
		if(var[a.second]*var[b.first] > var[b.second]*var[a.first])
			return s-var[a.first]+var[a.second];
		else if(var[a.second]*var[b.first]  < var[b.second]*var[a.first])
			return s-var[b.first]+var[b.second];
		else
			return max(s-var[a.first]+var[a.second],s-var[b.first]+var[b.second]);
	}
	else if(a.first!=-1)
		return s-var[a.first]+var[a.second];
	else if(b.first!=-1)
		return s-var[b.first]+var[b.second];
	else
		return max(s,sum());
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&k)!=EOF && (n||k))
	{
		for(int i=0;i<n;++i)
			scanf("%d",&var[i]);

		printf("%d\n",calc());
	}

	return 0;
}

/*随机数据生成器

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","w",stdout);
#endif

	srand((unsigned)time(NULL));
	int dataset=100;
	while(dataset--)
	{
		int n=rand()%10+1,k=rand()%n+1;
		cout<<n<<" "<<k<<endl;
		while(n--)
			cout<<rand()%10-5<<" ";
		cout<<endl;
	}
	cout<<"0 0"<<endl;

	return 0;
}

*/
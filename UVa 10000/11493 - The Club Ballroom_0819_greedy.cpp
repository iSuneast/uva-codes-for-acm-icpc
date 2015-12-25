/*
11493 - The Club Ballroom

greedy...
贪心...
知道用贪心的前提是题目看清楚了...
it can be joined to at most one other plank to 
	complete the distance
这句话很重要...

对所有长度排序...
对n,m分开处理...
先把一个的取走,,
然后两端往中间扫描,每次取两个...
*/

#include<iostream>
#include<algorithm>
#include<ctime>
#define MAXN 100003
#define INF 0x3f3f3f3f
using namespace std;

int n,m,l,k,key[MAXN];

int process(int len,int req)
{
	int cnt=0,front=0,rear=k-1,ans=0;

	while(rear>=0 && key[rear]>len)
		--rear;
	while(rear>=0 && key[rear]==len && cnt<req)
		++cnt,++ans,--rear;

	while(front<rear && cnt<req)
	{
		if(key[front]+key[rear]==len)
			++cnt,ans+=2,++front,--rear;
		else if(key[front]+key[rear]>len)
			--rear;
		else
			++front;
	}

	if(cnt>=req)
		return ans;
	return INF;
}

void random_data();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		scanf("%d%d",&l,&k);
		for(int i=0;i<k;++i)
			scanf("%d",&key[i]);
		sort(key,key+k);
		int ans=INF;
		if(n*100%l==0)
			ans=min(ans,process(m,n*100/l));
		if(m*100%l==0)
			ans=min(ans,process(n,m*100/l));

		if(ans!=INF)
			printf("%d\n",ans);
		else
			puts("impossivel");
	}

	return 0;
}

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

void random_data()
{
	freopen("in","w",stdout);

	int dataset=30;
	srand((unsigned)time(NULL));
	while(dataset--)
	{
		int n=1,m=1;
		while(gcd(n,m)==1)
			n=rand()%10+1,m=rand()%10+1;

		cout<<n<<" "<<m<<endl;
		cout<<gcd(n,m)*100<<endl;

		int k=rand()%30+1;
		cout<<k<<endl;
		while(k--)
			cout<<rand()%10+1<<" ";
		cout<<endl;
		cout<<endl;
	}
	puts("0 0");
}

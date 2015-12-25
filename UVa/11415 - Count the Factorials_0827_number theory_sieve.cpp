/*
11415 - Count the Factorials

number theory...
sieve...
pre_calc the count[ i! ] in O(NlogN) time...
because count[] is monotonic increasing...
we can use bsearch to located the correct answer in O(logN) time....
*/

#include<iostream>
#include<algorithm>
#define MAXN 10000001
using namespace std;

int cnt[MAXN],func[MAXN];
bool flag[MAXN];

void init()
{
	for(int i=2;i<MAXN;++i)
	{
		if(!flag[i])
		{
			cnt[i]=1;
			for(int j=i*2;j<MAXN;j+=i)
			{
				flag[j]=true;
				int k=j;
				while(k%i==0)
				{
					k/=i;
					++cnt[j];
				}
			}
		}
		cnt[i]+=cnt[i-1];
	}
	cnt[0]=cnt[1]=1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	int dataset,n;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		printf("%d\n",upper_bound(cnt,cnt+MAXN,n)-cnt);
	}

	return 0;
}

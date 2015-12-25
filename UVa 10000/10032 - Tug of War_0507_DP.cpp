/*
10032 - Tug of War

DP...
杯具啊...
抄正一下再交就WA了...
表示找不到Bug...
对着原来就代码又敲了好几遍...
然后...在什么都没有改动的情况下又AC了...
Orz...Uva果然是个神OJ...

没明白为什么这个版本AC...而其他版本TLE...
用滚动数组优化空间复杂度...

new_ppl表示当前状态...
next_ppl表示下一个阶段的状态...
而*_idx是代表当前状态的前一个阶段的位置...

因为体重集合是可重集...如果不加优化的话...
枚举的状态量里面将会有大量的重复...
为了避免重复扩展..
可以先对体重排序...
然后将无重复的体重保存到new_ppl作为状态枚举的起点...

其实就是背包问题...
原理同TLE的代码完全一致...
*/

#include<iostream>
#include<algorithm>
#define MAXN 22510
#define MAXPPL 110
using namespace std;

int ppl[MAXPPL],flag[MAXN];
int new_ppl[MAXN],new_idx[MAXN],next_ppl[MAXN],next_idx[MAXN];
int ppln,new_ppln,differ,sum,set_sz,new_sz,key;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&ppln);
		sum=0;
		for(int i=0;i<ppln;++i)		//读入
		{
			scanf("%d",ppl+i);
			sum+=ppl[i];
		}
		sort(ppl,ppl+ppln);
		memset(flag,0,sizeof(flag));
		differ=sum;
		new_ppln=0;
		key=0;
		for(int i=0;i<ppln;++i)		//删除重复元素
			if(flag[ppl[i]]!=1)
			{
				new_ppl[new_ppln]=ppl[i];
				new_idx[new_ppln++]=i;
				flag[ppl[i]]=1;
			}
		set_sz=ppln>>1;		//状态集合大小,应该为ceil(n/2)
		if(ppln&1)
			++set_sz;
		for(int i=2;i<=set_sz;++i)
		{
			new_sz=0;
			for(int j=0;j<new_ppln;++j)			//背包
				for(int k=new_idx[j]+1;k<ppln;++k)
				{
					if(k+ppln/2-i>=ppln)
						break;
					if(flag[new_ppl[j]+ppl[k]]!=i)
					{
						next_ppl[new_sz]=new_ppl[j]+ppl[k];
						next_idx[new_sz]=k;
						flag[next_ppl[new_sz]]=i;
						++new_sz;
					}
				}
			if(i==ppln/2 || i==set_sz)			//已经到达解
			{
				for(int j=0;j<new_sz;++j)
					if(abs(sum-(next_ppl[j]<<1))<differ)
					{
						differ=abs(sum-(next_ppl[j]<<1));
						key=next_ppl[j];
					}
			}
			if(i!=set_sz)			//滚动数组,将next_*的信息保存到new_*
			{
				new_ppln=0;
				for(int j=0;j<new_sz;++j)
				{
					new_ppl[new_ppln]=next_ppl[j];
					new_idx[new_ppln++]=next_idx[j];
				}
			}
		}
		if(key>sum-key)
			key=sum-key;
		printf("%d %d\n",key,sum-key);
		if(dataset)
			putchar('\n');
	}

	return 0;
}

/*
TLE代码....
相当不可思议...
我已经优化到无敌了...
速度暴快...
为什么还是TLE...

#include<iostream>
#include<algorithm>
#define MAXN 22510
#define MAXPPL 110
using namespace std;

bool flag[MAXPPL>>1][MAXN];
int next[MAXPPL>>1][MAXN],cnt[MAXPPL>>1],ppl[MAXPPL];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int n,tn,i,j,k,s=0,key=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",ppl+i);
			s+=ppl[i];
		}
		memset(flag,0,sizeof(flag));
		memset(cnt,0,sizeof(cnt));
		sort(ppl,ppl+n);
		flag[0][0]=1;
		cnt[0]=1;
		next[0][0]=0;
		tn=n>>1;
		int t=s,tmp;
		s>>=1;
		for(i=0;i<tn;i++)
		{
			for(j=0;j<cnt[i];j++)
				for(k=0;k<n;k++)
				{
					tmp=next[i][j]+ppl[k];
					if(tmp<=s && !flag[i+1][tmp])
					{
						flag[i+1][tmp]=1;
						next[i+1][cnt[i+1]++]=tmp;
					}
				}
		}
		key=upper_bound(next[tn],next[tn]+cnt[tn],s)-next[tn];
		if(key==cnt[tn])
			--key;
		key=next[tn][key];
		printf("%d %d\n",key,t-key);
		if(dataset)
			putchar('\n');
	}

	return 0;
}
*/
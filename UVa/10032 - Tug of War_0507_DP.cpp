/*
10032 - Tug of War

DP...
���߰�...
����һ���ٽ���WA��...
��ʾ�Ҳ���Bug...
����ԭ���ʹ��������˺ü���...
Ȼ��...��ʲô��û�иĶ����������AC��...
Orz...Uva��Ȼ�Ǹ���OJ...

û����Ϊʲô����汾AC...�������汾TLE...
�ù��������Ż��ռ临�Ӷ�...

new_ppl��ʾ��ǰ״̬...
next_ppl��ʾ��һ���׶ε�״̬...
��*_idx�Ǵ���ǰ״̬��ǰһ���׶ε�λ��...

��Ϊ���ؼ����ǿ��ؼ�...��������Ż��Ļ�...
ö�ٵ�״̬�����潫���д������ظ�...
Ϊ�˱����ظ���չ..
�����ȶ���������...
Ȼ�����ظ������ر��浽new_ppl��Ϊ״̬ö�ٵ����...

��ʵ���Ǳ�������...
ԭ��ͬTLE�Ĵ�����ȫһ��...
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
		for(int i=0;i<ppln;++i)		//����
		{
			scanf("%d",ppl+i);
			sum+=ppl[i];
		}
		sort(ppl,ppl+ppln);
		memset(flag,0,sizeof(flag));
		differ=sum;
		new_ppln=0;
		key=0;
		for(int i=0;i<ppln;++i)		//ɾ���ظ�Ԫ��
			if(flag[ppl[i]]!=1)
			{
				new_ppl[new_ppln]=ppl[i];
				new_idx[new_ppln++]=i;
				flag[ppl[i]]=1;
			}
		set_sz=ppln>>1;		//״̬���ϴ�С,Ӧ��Ϊceil(n/2)
		if(ppln&1)
			++set_sz;
		for(int i=2;i<=set_sz;++i)
		{
			new_sz=0;
			for(int j=0;j<new_ppln;++j)			//����
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
			if(i==ppln/2 || i==set_sz)			//�Ѿ������
			{
				for(int j=0;j<new_sz;++j)
					if(abs(sum-(next_ppl[j]<<1))<differ)
					{
						differ=abs(sum-(next_ppl[j]<<1));
						key=next_ppl[j];
					}
			}
			if(i!=set_sz)			//��������,��next_*����Ϣ���浽new_*
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
TLE����....
�൱����˼��...
���Ѿ��Ż����޵���...
�ٶȱ���...
Ϊʲô����TLE...

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
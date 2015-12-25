/*
11235 - Frequent values

rmq...
汗...
写得这么挫的rmq竟然过了...
主要是不知道该怎么合并两个区间...
其它的都好做...

实在想不出来什么好办法..
索性就暴力一点...
人工枚举算了...
*/

#include<iostream>
#define MAXN 100010
#define MAXDEP 17
using namespace std;

struct RMQ
{
	int l,r,l_freq,r_freq;
	int m_freq;
}tree[MAXN][MAXDEP];

int n,q,var[MAXN];

void rmq()
{
	for(int i=0;i<n;++i)
	{
		tree[i][0].l=tree[i][0].r=var[i];
		tree[i][0].l_freq=tree[i][0].r_freq=1;
		tree[i][0].m_freq=1;
	}

	for(int j=1;(1<<j)<=n;++j)
		for(int i=0;i+(1<<j)-1<n;++i)
		{
			int l=i,r=i+(1<<(j-1));

			tree[i][j].l=tree[l][j-1].l;
			tree[i][j].l_freq=tree[l][j-1].l_freq;
			tree[i][j].r=tree[r][j-1].r;
			tree[i][j].r_freq=tree[r][j-1].r_freq;

			if(tree[l][j-1].l==tree[r][j-1].r)
				tree[i][j].l_freq=tree[i][j].r_freq=tree[i][j].m_freq
					=tree[l][j-1].l_freq+tree[r][j-1].r_freq;
			else if(tree[l][j-1].r==tree[r][j-1].r)
				tree[i][j].r_freq=tree[i][j].m_freq
					=tree[l][j-1].r_freq+tree[r][j-1].r_freq;
			else if(tree[l][j-1].l==tree[r][j-1].l)
				tree[i][j].l_freq=tree[i][j].m_freq
					=tree[l][j-1].l_freq+tree[r][j-1].l_freq;
			else if(tree[l][j-1].r==tree[r][j-1].l)
			{
				tree[i][j].m_freq=tree[l][j-1].r_freq+tree[r][j-1].l_freq;
				tree[i][j].m_freq=max( tree[i][j].m_freq, max(tree[l][j-1].m_freq,tree[r][j-1].m_freq) );
				tree[i][j].m_freq=max( tree[i][j].m_freq, max(tree[i][j].l_freq,tree[i][j].r_freq) );
			}
			else
			{
				tree[i][j].m_freq=max(tree[l][j-1].m_freq,tree[r][j-1].m_freq);
				tree[i][j].m_freq=max( tree[i][j].m_freq, max(tree[i][j].l_freq,tree[i][j].r_freq) );
			}
		}
}

int log2(int n)
{
	int log;
	for(log=1;(1<<log)<=n;++log)
		;
	return log-1;
}

int query(int s,int e)
{
	RMQ key=tree[s][0];
	bool first=true;
	while(s<=e)
	{
		int j=log2(e-s+1);

		if(first)
			key=tree[s][j];
		else
		{
			RMQ cur=tree[s][j];

			if(key.l==cur.r)
			{
				key.l_freq=key.r_freq=key.l_freq+cur.r_freq;
				key.m_freq=max( key.m_freq, max(key.l_freq,key.r_freq) );
			}
			else if(key.l==cur.l)
			{
				key.r=cur.r;
				key.r_freq=cur.r_freq;
				key.l_freq=key.l_freq+cur.l_freq;
				key.m_freq=max( key.m_freq, max(key.l_freq,key.r_freq) );
			}
			else if(key.r==cur.r)
			{
				key.r_freq=key.r_freq+cur.r_freq;
				key.m_freq=max( key.m_freq, max(key.l_freq,key.r_freq) );
			}
			else if(key.r==cur.l)
			{
				key.m_freq=max( key.m_freq, key.r_freq+cur.l_freq );
				key.m_freq=max( key.m_freq, cur.m_freq );
				key.r=cur.r;
				key.r_freq=cur.r_freq;
			}
			else
			{
				key.m_freq=max( key.m_freq, cur.m_freq );
				key.r=cur.r;
				key.r_freq=cur.r_freq;
			}
		}

		s+=(1<<j);
		first=false;
	}
	return max(key.m_freq, max(key.r_freq,key.l_freq) );
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&q)!=EOF && n)
	{
		for(int i=0;i<n;++i)
			scanf("%d",var+i);

		rmq();

		int s,e;
		while(q--)
		{
			scanf("%d%d",&s,&e);
			--s,--e;
			printf("%d\n",query(s,e));
		}
	}

	return 0;
}

/*
#include<iostream>
#include<ctime>
#define MAXN 100000
using namespace std;

int var[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","w",stdout);
#endif

	int cas=3;
	while(cas--)
	{
		int n=rand()*rand()%100+1,q=rand()%n+1;
		cout<<n<<" "<<q<<endl;;
		for(int i=0;i<n;++i)
			var[i]=rand()*rand()%n-10;
		sort(var,var+n);
		for(int i=0;i<n;++i)
			cout<<var[i]<<" ";
		cout<<endl;
		while(q--)
		{
			int a=rand()%n+1,b=rand()%n+1;
			if(a>b)
				swap(a,b);
			cout<<a<<" "<<b<<endl;
		}

	}
	cout<<0<<endl;

	return 0;
}

*/
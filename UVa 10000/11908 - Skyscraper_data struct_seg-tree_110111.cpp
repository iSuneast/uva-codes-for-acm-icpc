/*
 * 11908 - Skyscraper
 * 
 * Data struct...
 * seg-tree...
 * sort the AD according to their END pos
 * then every AD has a value (BEGIN, END, MONEY)
 * build a Segment-tree
 * QUERY(N) return the maximum value with index <=N
 * INSERT(N , M) insert the node(N , N+1, M)
 * 
 * for every ADs
 *	 	Pre = Query(BEGIN-1)
 * 		INSERT( END-1, Pre+MONEY )
 * return ROOT.MONEY
 * 
 * done!
 * 
 * happy coding...
 */

#include<cstdio>
#include<algorithm>
#define MAXN 30003
#define MAX_NODE (1<<17)
#define MID(a,b) (((a)+(b))>>1)
#define LS(p) ((p)<<1)
#define RS(p) (((p)<<1)+1)
using namespace std;

class SEG_TREE
{
public:
	void build(int b,int e,const int &p=1)
	{
		node[p]=NODE(b,e,0);
		if(b+1==e)
			return ;
		build(b,MID(b,e),LS(p));
		build(MID(b,e),e,RS(p));
	}
	
	int query(int b,const int &p=1)
	{
		if(b<0)
			return 0;
		if(node[p].b+1==node[p].e)
			return node[p].m;
		else if(b<MID(node[p].b, node[p].e))
			return query(b,LS(p));
		else
			return max( node[LS(p)].m, query(b,RS(p)) );
	}
	
	void insert(int e,int m,const int &p=1)
	{
		if(node[p].b+1==node[p].e)
		{
			node[p].m=max(node[p].m,m);
			return ;
		}
		
		if(e<MID(node[p].b, node[p].e))
			insert(e,m,LS(p));
		else
			insert(e,m,RS(p));
		
		node[p].m=max(node[LS(p)].m, node[RS(p)].m);
	}
	
	int maxM()
	{
		return node[1].m;
	}
private:
	class NODE
	{
	public:
		NODE(){}
		NODE(int _b,int _e,int _m):b(_b), e(_e), m(_m){}
		int b,e,m;
	}node[MAX_NODE];
}st;

struct AD
{
	int b,e,m;
	bool operator<(const AD &t)const
	{
		return e<t.e;
	}
}ad[MAXN];
int n, sz, var[MAXN<<1];

int process()
{
	st.build(0,sz);
	for(int i=0;i<n;++i)
	{
		int b=lower_bound(var, var+sz, ad[i].b)-var;
		int e=lower_bound(var, var+sz, ad[i].e)-var;
		
		st.insert(e-1, st.query(b-1) + ad[i].m);
	}
	return st.maxM();
}

void read()
{
	sz=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d%d%d",&ad[i].b, &ad[i].e, &ad[i].m);
		ad[i].e+=ad[i].b;
		var[sz++]=ad[i].b;
		var[sz++]=ad[i].e;
	}
	sort(ad,ad+n);
	sort(var,var+sz);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
    	read();
    	printf("Case %d: %d\n",cas, process());
    }

    return 0;
}


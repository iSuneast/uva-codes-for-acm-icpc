/*
 * 10774 - Repeated Josephus
 * 
 * number theory...
 * you'd better try to find the final format for Josephus of length = 2
 * 1 -> 1
 * 2 -> 1
 * 3 -> 3
 * 4 -> 1
 * 5 -> 3
 * 6 -> 1
 * 7 -> 5
 * 8 -> 1
 * 9 -> 7
 * 10-> 1
 * 11-> 3
 * 12-> 5
 * ....
 * got it? yeah~ it's simple! just do it~
 * 
 * happy coding...
 */

#include<cstdio>
#define MAXN 30001
using namespace std;

int fa[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dep=1,p=0;
    for(int i=1;i<MAXN;++i)
    {
    	fa[i]=2*(++p)-1;
    	if(p==dep)
    	{
    		p=0;
    		dep<<=1;
    	}
    }
    
    int dataset;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
    	int key=0,n;
    	scanf("%d",&n);
    	while(fa[n]!=n)
    	{
    		n=fa[n];
    		++key;
    	}
    	printf("Case %d: %d %d\n",cas,key,n);
    }

    return 0;
}


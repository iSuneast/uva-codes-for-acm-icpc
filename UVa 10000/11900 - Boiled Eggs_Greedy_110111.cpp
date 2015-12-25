/*
 * 11900 - Boiled Eggs
 * 
 * Ad hoc...
 * Greedy...
 * just keep it simple...
 */

#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset, n, p, q, egg[33];
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
    	int key=0, w=0;
    	scanf("%d%d%d",&n,&p,&q);
    	for(int i=0;i<n;++i)
    	{
    		scanf("%d",&egg[i]);
    	}
    	sort(egg,egg+n);
    	for(int i=0;i<n;++i)
    	{
    		if(egg[i]+w<=q)
    		{
    			++key;
    			w+=egg[i];
    		}
    		else
    			break;
    	}
    	printf("Case %d: %d\n",cas,min(key,p));
    }

    return 0;
}


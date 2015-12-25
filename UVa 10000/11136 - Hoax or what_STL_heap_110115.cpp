/*
 * 11136 - Hoax or what
 * 
 * STL...
 * heap...
 * 映射二分堆...
 * but I just use multiset && priority_queue to solve it
 * the tricky is that the output is a long long integer
 * 
 * happy coding...
 */

#include<cstdio>
#include<queue>
#include<set>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    for(int day,n,p,q; scanf("%d",&day)!=EOF && day; )
    {
    	long long key=0;
    	priority_queue<int> M;
    	priority_queue<int,vector<int>,greater<int> > m;
    	multiset<int> sM, sm;
    	
    	while(day--)
    	{
    		scanf("%d",&n);
    		while(n--)
    		{
    			scanf("%d",&p);
    			m.push(p);
    			M.push(p);
    		}
    		
    		p=M.top();	M.pop();
    		while(sm.find(p)!=sm.end())
    		{
        		sm.erase(p);
        		p=M.top();	M.pop();
    		}
    		
    		q=m.top();	m.pop();
    		while(sM.find(q)!=sM.end())
    		{
        		sM.erase(q);
        		q=m.top();	m.pop();
    		}
    		
    		sM.insert(p);
    		sm.insert(q);
    		
    		key+=p-q;
    	}
    	
    	printf("%lld\n",key);
    }

    return 0;
}


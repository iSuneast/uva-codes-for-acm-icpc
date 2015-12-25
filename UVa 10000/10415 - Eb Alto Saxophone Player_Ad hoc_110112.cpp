/*
 * 10415 - Eb Alto Saxophone Player
 * 
 * Ad hoc...
 * no more tricky but: "and the song maybe empty."
 */

#include<cstdio>
#include<cstring>
#define MAXN 203
using namespace std;

char s[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    bool f[14][10]={
    		0,1,1,1,0,0,1,1,1,1,
    		0,1,1,1,0,0,1,1,1,0,
    		0,1,1,1,0,0,1,1,0,0,
    		0,1,1,1,0,0,1,0,0,0,
    		0,1,1,1,0,0,0,0,0,0,
    		0,1,1,0,0,0,0,0,0,0,
    		0,1,0,0,0,0,0,0,0,0,
    		0,0,1,0,0,0,0,0,0,0,

    		1,1,1,1,0,0,1,1,1,0,
    		1,1,1,1,0,0,1,1,0,0,
    		1,1,1,1,0,0,1,0,0,0,
    		1,1,1,1,0,0,0,0,0,0,
    		1,1,1,0,0,0,0,0,0,0,
    		1,1,0,0,0,0,0,0,0,0
    };
    
    char h[128];
    h['c']=0;
    h['d']=1;
    h['e']=2;
    h['f']=3;
    h['g']=4;
    h['a']=5;
    h['b']=6;
    
    h['C']=7;
    h['D']=8;
    h['E']=9;
    h['F']=10;
    h['G']=11;
    h['A']=12;
    h['B']=13;

    int dataset, key[10];
    bool pre[10];
    scanf("%d",&dataset);	gets(s);
    while(dataset--)
    {
    	gets(s);
    	memset(key,0,sizeof(key));
    	memset(pre,0,sizeof(pre));
    	for(int i=0;s[i];++i)
    	{
    		int p=h[ s[i] ];
    		for(int j=0;j<10;++j)
    		{
    			if(f[p][j])
    			{
    				if(!pre[j])
    					++key[j];
    				pre[j]=true;
    			}
    			else
    				pre[j]=false;
    		}
    	}
    	
    	for(int i=0;i<9;++i)
    		printf("%d ",key[i]);
    	printf("%d\n",key[9]);
    }

    return 0;
}


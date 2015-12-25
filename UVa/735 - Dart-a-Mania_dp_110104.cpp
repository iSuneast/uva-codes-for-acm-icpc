/*
 * 735 - Dart-a-Mania
 * 
 * dp...
 * find out all valid score with a single DART
 * then enum all valid sum using three DARTs
 * 
 * combination++
 * if two of them have the same score, permutation+=3
 * if all of them have the same score, permutation+=6
 * else permutation++
 */

#include<cstdio>
#include<algorithm>
#define SZ 181
using namespace std;

struct SCORE
{
	int per,com;
}scr[SZ];
int com[SZ],per[SZ];
int var[100],n;

void generate()
{
	n=0;
	for(int i=0;i<=20;++i)
	{
		var[n++]=i;
		var[n++]=2*i;
		var[n++]=3*i;
	}
	var[n++]=50;
	sort(var,var+n);
	
	int t=0;
	for(int i=0;i<n;++i)
		if(var[i]!=var[t])
			var[++t]=var[i];
	n=t+1;
}

void dp()
{
	generate();
	
	for(int i=0;i<n;++i)
	{
		for(int j=i;j<n;++j)
			for(int k=j;k<n;++k)
			{
				int s=var[i]+var[j]+var[k];
				scr[s].com++;
				if(i==k)
					scr[s].per++;
				else if(i==j || j==k)
					scr[s].per+=3;
				else
					scr[s].per+=6;
			}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    dp();
    for(int each;scanf("%d",&each)!=EOF && each>0;)
    {
    	if(each>=SZ || !scr[each].com)
    		printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",each);
    	else
    	{
    		printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",each,scr[each].com);
    		printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",each,scr[each].per);
    	}
    	puts("**********************************************************************");
    }
    puts("END OF OUTPUT");

    return 0;
}


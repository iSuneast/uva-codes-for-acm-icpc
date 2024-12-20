/*
11713 - Abstract Names

string...
*/

#include<iostream>
#define MAXN 128
using namespace std;

char pronounce[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	pronounce['a']=pronounce['e']=pronounce['i']=pronounce['o']=pronounce['u']=1;
	pronounce['A']=pronounce['E']=pronounce['I']=pronounce['O']=pronounce['U']=1;
	int dataset;
	scanf("%d",&dataset);
	char a[25],b[25];
	while(dataset--)
	{
		scanf("%s%s",a,b);
		int la=strlen(a),lb=strlen(b);
		if(la!=lb)
			puts("No");
		else
		{
			bool got=false;
			for(int i=0;i<la;++i)
				if(a[i]!=b[i]  && !pronounce[ a[i] ])
				{
					got=true;
					break;
				}
			if(got)
				puts("No");
			else
				puts("Yes");
		}
	}

	return 0;
}

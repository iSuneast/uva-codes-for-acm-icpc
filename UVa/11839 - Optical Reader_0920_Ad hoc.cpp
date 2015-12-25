/*
11839 - Optical Reader

Ad hoc...
no trick...
*
* those with values equal or lower to 127 are considered black
* and those with values higher than 127 will be considered white.
*
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n,var;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			vector<char> ans;
			for(int i=0;i<5;++i)
			{
				scanf("%d",&var);
				if(var<=127)
					ans.push_back(i+'A');
			}
			if(ans.size()==1)
				printf("%c\n",ans[0]);
			else
				puts("*");
		}
	}

	return 0;
}

/*
484 - The Department of Redundancy Department

simple
*/

#include<iostream>

using namespace std;

int list[2][10000000];

int main()
{
//	freopen("in.txt","r",stdin);

	int i,l=0,flag,n;
	memset(list,0,sizeof(list));
	while(scanf("%d",&n)!=EOF)
	{
		flag=0;
		for(i=0;i<l;i++)
			if(list[0][i]==n)
			{
				list[1][i]++;
				flag=1;
				break;
			}
		if(!flag)
		{
			list[0][l]=n;
			list[1][l++]=1;
		}
	}
	for(i=0;i<l;i++)
		cout<<list[0][i]<<' '<<list[1][i]<<endl;

return 0;
}

/*
10370 - Above Average
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int c,n,i;
	double avg,ans,s[1010];
	cin>>c;
	while(c--)
	{
		cin>>n;
		avg=ans=0;
		for(i=0;i<n;i++)
			cin>>s[i],avg+=s[i];
		avg/=n;
		for(i=0;i<n;i++)
			if(s[i]>avg)
				ans++;
		printf("%.3lf%%\n",100*ans/n);
	}

return 0;
}

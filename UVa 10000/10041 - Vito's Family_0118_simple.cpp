/*
10041 - Vito's Family

�ٲ�...
...
����WA...
��Ҫ��һ��ʼ��Ŀû�п����...
Ϲ��...
*/

#include<iostream>
#include<algorithm>

using namespace std;

int cmp(const long a,const long b)
{
	return a<b;
}

int main()
{
	long cas,r,s[500],i,ans,t;
	cin>>cas;
	while(cas--)
	{
		cin>>r;
		for(i=0;i<r;i++)
			cin>>s[i];
		ans=0;
		sort(s,s+r,cmp);
		t=s[(r-1)/2];
		for(i=0;i<r;i++)
			ans+=abs(t-s[i]);
		cout<<ans<<endl;
	}

return 0;
}
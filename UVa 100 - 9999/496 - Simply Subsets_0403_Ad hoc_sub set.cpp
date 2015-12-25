/*
496 - Simply Subsets

sub set...
Ad hoc...
*/

#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#define MAXN 100000
using namespace std;
int a[MAXN],b[MAXN];

int main()
{
//	freopen("in.txt","r",stdin);

	string buf;
	while(getline(cin,buf))
	{
		stringstream sin(buf);
		int cnt1,cnt2,match,p1,p2;
		cnt1=cnt2=0;
		while(sin>>a[cnt1])
			++cnt1;
		getline(cin,buf);
		stringstream sin2(buf);
		while(sin2>>b[cnt2])
			++cnt2;
		sort(a,a+cnt1);
		sort(b,b+cnt2);
		p1=p2=0;
		match=0;
		while(p1<cnt1 && p2<cnt2)
		{
			if(a[p1]==b[p2])
				++p1,++p2,++match;
			else if(a[p1]<b[p2])
				++p1;
			else
				++p2;
		}
		if(match==cnt1)
		{
			if(match==cnt2)
				cout<<"A equals B"<<endl;
			else
				cout<<"A is a proper subset of B"<<endl;
		}
		else if(match==cnt2)
			cout<<"B is a proper subset of A"<<endl;
		else if(match)
			cout<<"I'm confused!"<<endl;
		else
			cout<<"A and B are disjoint"<<endl;
	}

	return 0;
}

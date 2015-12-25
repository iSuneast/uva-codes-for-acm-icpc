/*
371 - Ackermann Functions
*/

#include<iostream>
#define MAXN 10000000
using namespace std;

long long num[MAXN],l,h,v,s,t;

long long calc(long long k)
{
	if(k==1)
		return 0;
	if(k<MAXN && num[k])
		return num[k];
	else if(k<MAXN)
	{
		if(k%2)
			return num[k]=calc(3*k+1)+1;
		return num[k]=calc(k/2)+1;
	}
	else
	{
		if(k%2)
			return calc(3*k+1)+1;
		return calc(k/2)+1;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("371.txt","w",stdout);

	while(cin>>l>>h && (l||h))
	{
		if(l>h)			//要注意这种情况是存在的.
			swap(l,h);
		cout<<"Between "
			<<l<<" and "<<h<<", ";
		s=0;
		if(l==1)		//还有就是要小心l==1时答案是3不是0.
		{
			v=l;
			s=3;
			++l;
		}
		while(l<=h)
		{
			t=calc(l);
			if(t>s)
			{
				s=t;
				v=l;
			}
			++l;
		}
		cout<<v<<" generates the longest sequence of "
			<<s<<" values."<<endl;
	}

return 0;
}

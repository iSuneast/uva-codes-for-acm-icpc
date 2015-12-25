/*
105 - The Skyline Problem

模拟题.
*/

#include<iostream>
using namespace std;

int building[10010];

int main()
{
//	freopen("in.txt","r",stdin);

	int l,h,r,lb=10010,rb=0;
	memset(building,0,sizeof(building));
	while(cin>>l>>h>>r)
		while(l<r)			//不要加等号
		{
			lb=lb<l?lb:l;
			rb=rb>r?rb:r;
			building[l]=building[l]>h?building[l]:h;
			l++;
		}
	bool first=true;
	while(lb<=rb)
	{
		if(building[lb]!=building[lb-1])
		{
			if(first)
				first=false;
			else
				cout<<' ';
			cout<<lb<<' '<<building[lb];
		}
		lb++;
	}
	cout<<endl;
return 0;
}

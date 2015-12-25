/*
10098 - Generating Fast
*/

#include<iostream>
#include<algorithm>

using namespace std;

int cmp(const char a,const char b)
{
	return a<b;
}

int main()
{
//	freopen("in.txt","r",stdin);
	char per[20];
	int n;
	cin>>n;
	while(n--)
	{
		cin>>per;
		sort(per,per+strlen(per),cmp);
		do
			cout<<per<<endl;
			while(next_permutation(per,per+strlen(per)));
		cout<<endl;
	}

return 0;
}

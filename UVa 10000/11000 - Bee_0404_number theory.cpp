/*
11000 - Bee

쳲��������еı���...
���������۵���...
�ܻƺܱ���...
*/

#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	long long t1,t2,t;
	int n;
	while(cin>>n && n!=-1)
	{
		t1=1;t2=2;
		for(int i=1;i<=n;++i)
		{
			t=t2;
			t2+=t1;
			t1=t;
		}
		cout<<t1-1<<' '<<t2-1<<endl;
	}

	return 0;
}

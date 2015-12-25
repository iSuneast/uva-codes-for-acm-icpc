/*
846 - Steps

simple math...
找规律的题...
0		---	0
1		---	1
11		---	2
121		---	3
1221	---	4
12321	---	5
123321	---	6
..................
接下去就很明显了...
*/

#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int a,b;
		cin>>a>>b;
		int dis=b-a,key=1,fa=1;
		if(!dis)
		{
			cout<<0<<endl;
			continue;
		}
		while(true)
		{
			if(fa!=1 && fa%2)
				++key;
			if(dis>=key)
				dis-=key;
			else
			{
				if(dis)
					++key;
				break;
			}
			if(dis)
				++fa;
			else
				break;
		}
		cout<<fa<<endl;
	}

	return 0;
}

/*
11202 - The least possible effort

math...
找规律...
矩形的时候ceil(n/2)*ceil(m/2)
正方形ceil(n/2)+...+1
用勤劳的双手模拟几组就知道了...
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int m,n,key=0;
		cin>>m>>n;
		if(m==n)
		{
			key=ceil(n/2.0);
			key=(1+key)*key/2;
		}
		else
			key=ceil(n/2.0)*ceil(m/2.0);
		printf("%d\n",key);
	}

	return 0;
}

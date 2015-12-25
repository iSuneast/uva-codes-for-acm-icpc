/*
11202 - The least possible effort

math...
�ҹ���...
���ε�ʱ��ceil(n/2)*ceil(m/2)
������ceil(n/2)+...+1
�����͵�˫��ģ�⼸���֪����...
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

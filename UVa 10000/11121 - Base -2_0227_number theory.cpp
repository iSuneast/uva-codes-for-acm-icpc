/*
11121 - Base -2
*/

/*
-2���Ƶ���...
ֻҪ��ϸ�������ֵ����ʾͿ��Ժ����׵ĵó�����...
��30������
30		1100010
-15		110001
8		11000
-4		1100
2		110
-1		11
1		1
ֻҪͨ�����ϵķ���...
�Ϳ��Եó�������...
������1�ǵݹ�Ľ�������.
�����ͬʱ1Ҳ�������...
_______________________________
��������õ��Ľ�������Ǹ���..
����Ҫ�ж������Ƿ�Ϊ-1.
-1�Ļ���1���...
��0,1���������..
*/

#include<iostream>

using namespace std;

void calc(int n)
{
	if(n==1)
	{
		cout<<1;
		return ;
	}
	if(n>0)
	{
		if(n%2)
			calc(-(n-1)/2);
		else
			calc(-n/2);
	}
	else if(n<0)
	{
		if(n%2)
			calc((-n+1)/2);
		else
			calc(-n/2);
	}
	cout<<(n%2?1:0);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int n,cas=0,dataset;
	cin>>dataset;
	while(cas++ < dataset)
	{
		cin>>n;
		cout<<"Case #"<<cas<<": ";
		if(!n)
			cout<<0;
		else
			calc(n);
		cout<<endl;
	}

return 0;
}

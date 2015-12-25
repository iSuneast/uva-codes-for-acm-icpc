/*
11121 - Base -2
*/

/*
-2进制的数...
只要仔细分析数字的性质就可以很容易的得出结论...
拿30做例子
30		1100010
-15		110001
8		11000
-4		1100
2		110
-1		11
1		1
只要通过以上的分析...
就可以得出结论了...
在这里1是递归的结束条件.
但与此同时1也必须输出...
_______________________________
负数求余得到的结果依旧是负数..
所以要判断余数是否为-1.
-1的话按1输出...
而0,1的情况不变..
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

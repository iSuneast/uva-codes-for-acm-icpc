/*
847 - A Multiplication Game

game theory...
��һ���������۵���Ŀ...
�о�������...
��Ŀ���ƺܸ�����ʵ���Ǻ��й��ɵ�...

��n<=9ʱ	-------	Stan wins.
��n<=9*2ʱ	-------	Ollie wins.
��n<=9*2*9ʱ-------	Stan wins.
��n<=9*2*9*2ʱ-----Ollie wins.
....

ԭ��ܼ�:
n<=9,stanһ��Ӯ
��9<n<=2*9ʱ,����stan��һ��ȡʲô(2~9)
			ollieһ���а취��ֵ����2*9
			��ʱollieӮ.
ͬ����Ե��Ƶõ���������Ľ��.
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,game[2]={9,2};
	while(cin>>n)
	{
		int state=-1,cur=1,cnt=0;
		while(cur<n)
			cur*=game[state=(state+1)%2],++cnt;
		if(cnt&1)
			cout<<"Stan wins."<<endl;
		else
			cout<<"Ollie wins."<<endl;
	}

	return 0;
}

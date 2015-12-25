/*
847 - A Multiplication Game

game theory...
第一次做博弈论的题目...
感觉好新鲜...
题目看似很复杂其实还是很有规律的...

当n<=9时	-------	Stan wins.
当n<=9*2时	-------	Ollie wins.
当n<=9*2*9时-------	Stan wins.
当n<=9*2*9*2时-----Ollie wins.
....

原理很简单:
n<=9,stan一定赢
在9<n<=2*9时,无论stan第一次取什么(2~9)
			ollie一定有办法让值超过2*9
			此时ollie赢.
同理可以递推得到其他情况的结局.
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

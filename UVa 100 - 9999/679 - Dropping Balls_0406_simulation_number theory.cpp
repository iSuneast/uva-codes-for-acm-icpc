/*
679 - Dropping Balls

完全二叉树的模拟题...
进行d次迭代...d为树高...
判断p的奇偶性...
p为奇...则小球向左...此时ans变为当前位置的左儿子...
p为偶...则小球向右...此时ans变为当前位置的右儿子...
改变p的值...
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
		int d,p,ans=1;
		cin>>d>>p;
		while(d--)
		{
			ans=ans<<1;
			if(p%2)
				p=(p+1)/2;
			else
				p/=2,++ans;
		}
		cout<<(ans>>1)<<endl;
	}
	cin>>dataset;	//这题的输入很奇怪耶...

	return 0;
}
